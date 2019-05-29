#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACER.hpp"

SCENARIO( "Testing ACER" ){
  GIVEN( "ENDF and PENDF files" ){

    decltype( auto ) sENDF = njoy::utility::slurpFileToMemory( "U235.endf" );
    decltype( auto ) sPENDF = njoy::utility::slurpFileToMemory( "U235.pendf" );

    decltype( auto ) ENDFtape = njoy::ENDFtk::syntaxTree::makeTape( sENDF );
    decltype( auto ) PENDFtape = njoy::ENDFtk::syntaxTree::makeTape( sPENDF );
  } // GIVEN
} // SCENARIO
