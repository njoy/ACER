Fast( Base::Material_t& evaluated, Base::Material_t& processed ):
  Base( evaluated, processed ),
  builder()
{
  decltype( auto ) MF3 = 
    mpark::get< Base::Material_t >( this->processed ).MF( 3 ).parse< 3 >();
  try{ // Set energygrid
    this->builder.energyGrid( MF3.MT( 1 ).energies() | ranges::to_vector );
  } catch( std::out_of_range& ){
    Log::info( "Unable to find total cross section" );
    Log::info( "MT=1 not found on PENDF file." );
    throw;
  }
  try{ // Set heating values
    this->builder.heating( MF3.MT( 301 ).energies() | ranges::to_vector );
  } catch( std::out_of_range& ){
    Log::info( "Unable to find heating cross section data (MT=301)" );
    throw;
  }

  auto size = builder.energyGrid().size();
  this->totalXS = std::vector< double >( size, 0.0 );
  this->disappearanceXS = std::vector< double >( size, 0.0 );
  
  this->addCrossSections( MF3 );

  builder.totalCrossSection( std::move( this->totalXS ) );
  builder.totalDisappearanceCrossSection( std::move( this->disappearanceXS ) );

}
