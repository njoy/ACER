class Fast {

  using buffer_t = decltype( njoy::utility::slurpFileToMemory( "" ) );
  using Material_t = std::decay_t< decltype( 
      ENDFtk::syntaxTree::makeTape( buffer_t{} ).MAT( int{} ).front() ) >;

  using Input = std::variant< Material_t >;
  Input evaluated_;
  Input processed_;

public:
  #include "ACER/Fast/src/ctor.hpp"
  // #include "ACER/Fast/src/buildReactions.hpp"
};
