void addCrossSections( ENDFtk::file::Type< 3 >& MF3 ){

  decltype( auto ) grid = this->builder.energyGrid();
  for( decltype( auto ) reaction: MF3.sections() ){
    decltype( auto ) MT = reaction.MT();

    if( MT == 1 ) continue;

    decltype( auto ) rxBuilder = this->builder.reaction( MT );
    this->reactionBuilders.insert( { MT, rxBuilder } );

    decltype( auto ) energies = reaction.energies() | ranges::to_vector;
    auto start = ranges::find( grid, energies[ 0 ] );
    auto index = ranges::distance( grid.begin(), start );
    rxBuilder.crossSection()
      .values( reaction.crossSections() | ranges::to_vector )
      .energyGrid( grid 
                  | ranges::view::slice( index, ranges::distance( grid ) ) )
    .add(); // crossSection
  }
}
