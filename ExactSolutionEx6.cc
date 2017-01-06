#include "ExactSolutionEx6.hh"
#include <cmath>

template <>
void ExactSolutionEx6<2>::vector_value(const Point<2> &p, Vector<double> &values) const
{
  // Because we don't know the exact solution but we need it to impose the
  // boundary conditions, we impose zero every where except at the inlet and the
  // outlet.
  values(0) = 0.;
  values(1) = 0.;
  values(2) = 1.;
  const double x = p(0);
  if ((std::abs(x+2.5) < 1e-12) || (std::abs(x-2.5) < 1e-12))
    {
      const double y = p(1);
      values(0) = -4.*y*(y+1.);
    }
}



template <>
void ExactSolutionEx6<2>::vector_gradient(const Point<2> &,
                                          std::vector<Tensor<1,2>> &) const
{
  // Since we don't know the exact solution, there is no way to compute the
  // exact gradient. So we do nothing.
}



template <>
void ExactSolutionEx6<3>::vector_value(const Point<3> &, Vector<double> &) const
{}



template <>
void ExactSolutionEx6<3>::vector_gradient(const Point<3> &,
                                          std::vector<Tensor<1,3>> &) const
{}
