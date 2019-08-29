class Base {

public:
  using buffer_t = decltype( njoy::utility::slurpFileToMemory( "" ) );
  using Material_t = std::decay_t< decltype( 
      ENDFtk::syntaxTree::makeTape( buffer_t{} ).MAT( int{} ).front() ) >;

protected:
  using Input = std::variant< Material_t >;
  Input evaluated;
  Input processed;

  #include "ACER/type/Base/src/ctor.hpp"
};
