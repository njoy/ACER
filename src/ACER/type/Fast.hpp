class Fast: protected Base {

  using Builder_t = ACEtk::interpretation::ContinuousEnergyNeutron::Builder;
  Builder_t builder;

  std::vector< double > totalXS;
  std::vector< double > disappearanceXS;

  std::map< int, Builder_t::Reaction::Builder > reactionBuilders;

protected:
  #include "ACER/type/FAST/src/addCrossSections.hpp"
public:
  #include "ACER/type/Fast/src/ctor.hpp"

  decltype( auto ) construct(){ return builder.construct(); }
};
