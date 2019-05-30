class Fast {

  using buffer_t = decltype( njoy::utility::slurpFileToMemory( std::string{} ) );
  using Material_t = 
    decltype( ENDFtk::syntaxTree::makeTape( buffer_t{} ).MAT( int{} ).front() );
  Material_t evaluated_;
  Material_t processed_;

public:
  #include "ACER/Fast/src/ctor.hpp"
};
