#ifndef PARTICLESPRING_H_INCLUDED
#define PARTICLESPRING_H_INCLUDED

#include <particleforce.h>

namespace Physics
{
  class ParticleSpring : public ParticleForce
  {
    public:
      ParticleSpring(std::shared_ptr<Particle> ancor, real spring_constant, real rest_length);

      virtual void update_force(std::shared_ptr<Particle> particle, real duration);
  };
}

#endif // PARTICLESPRING_H_INCLUDED
