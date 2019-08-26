#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACER.hpp"

SCENARIO( "Testing Fast ACER production" ){
  GIVEN( "ENDF and PENDF files" ){

    decltype( auto ) sENDF = njoy::utility::slurpFileToMemory( "U235.endf" );
    decltype( auto ) sPENDF = njoy::utility::slurpFileToMemory( "U235.pendf" );

    decltype( auto ) ENDFTape = njoy::ENDFtk::syntaxTree::makeTape( 
        std::move( sENDF ) );
    decltype( auto ) PENDFTape = njoy::ENDFtk::syntaxTree::makeTape( 
        std::move( sPENDF ) );
    decltype( auto ) eMaterial = ENDFTape.MAT( 9228 ).front();
    decltype( auto ) pMaterial = PENDFTape.MAT( 9228 ).front();

    WHEN( "the Fast class is created" ){
      njoy::ACER::type::Fast fast{ eMaterial, pMaterial };
    }
  } // GIVEN
} // SCENARIO

