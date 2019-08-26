Base( Material_t& evaluated, Material_t& processed ):
  evaluated_( std::forward< Material_t >( evaluated ) ),
  processed_( std::forward< Material_t >( processed ) )
{ }
