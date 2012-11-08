#ifndef PARTICLESPRING_H_INCLUDED
#define PARTICLESPRING_H_INCLUDED

#include <particleforce.h>

namespace Physics
{
  class ParticleSpring : public ParticleForce
  {
    public:
      ParticleSpring(std::shared_ptr<Particle> ancor, Real spring_constant, Real rest_length);

      virtual void update_force(std::shared_ptr<Particle> particle, Real duration);
  };
}

#endif // PARTICLESPRING_H_INCLUDED
