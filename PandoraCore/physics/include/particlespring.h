#ifndef PARTICLESPRING_H_INCLUDED
#define PARTICLESPRING_H_INCLUDED

#include <vector3.h>

namespace Physics
{
  class ParticleSpring
  {
    public:
      Math::Vector3<Real> get_center() const;
      Real get_rest_length() const;
  };
}

#endif // PARTICLESPRING_H_INCLUDED
