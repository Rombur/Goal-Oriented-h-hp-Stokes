#include "RightHandSideEx6.hh"


template <int dim>
double RightHandSideEx6<dim>::value(const Point<dim> &, const unsigned int ) const
{
  return 0.;
}


template <int dim>
void
RightHandSideEx6<dim>::vector_value(const Point<dim> &p, Vector<double> &values) const
{
  for (unsigned int c=0; c<this->n_components; ++c)
    values(c) = this->value(p,c);
}


//Explicit initialization
template class RightHandSideEx6<2>;
template class RightHandSideEx6<3>;

