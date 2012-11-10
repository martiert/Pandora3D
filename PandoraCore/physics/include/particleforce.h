#ifndef PHYSICS_PARTICLE_H_INCLUDED
#define PHYSICS_PARTICLE_H_INCLUDED

#include <config.h>
#include <memory>

namespace Physics
{
  class Particle;

  class ParticleForce
  {
    public:
      virtual void update_force(std::shared_ptr<Particle> particle, real duration) = 0;
  };

  typedef std::shared_ptr<ParticleForce> ParticleForcePtr;
}

#endif //PHYSICS_PARTICLE_H_INCLUDED
