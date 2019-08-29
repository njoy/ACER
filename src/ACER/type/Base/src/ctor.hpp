Base( Material_t& evaluated, Material_t& processed ):
  evaluated( std::forward< Material_t >( evaluated ) ),
  processed( std::forward< Material_t >( processed ) )
{ }
