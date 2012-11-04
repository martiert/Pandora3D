#include "particlespring.h"

namespace Physics
{

Math::Vector3<Real> ParticleSpring::get_center() const
{
  return Math::Vector3<Real>::ZERO;
}

Real ParticleSpring::get_rest_length() const
{
  return 0;
}
}
