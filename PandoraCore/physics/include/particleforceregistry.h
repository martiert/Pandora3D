#ifndef PARTICLE_FORCE_REGISTRY_H_INCLUDED
#define PARTICLE_FORCE_REGISTRY_H_INCLUDED

#include "config.h"
#include <memory>

namespace Physics
{
  class ParticleForce;
  class Particle;

  class ParticleForceRegistry
  {
    public:
      void add (std::shared_ptr<ParticleForce> force, std::shared_ptr<Particle> particle);

      void remove (std::shared_ptr<ParticleForce> force, std::shared_ptr<Particle> particle);

      void clear ();

      void update_particles_with_forces (const Real& timestep);

    private:
      std::shared_ptr<ParticleForce> force;
      std::shared_ptr<Particle> particle;
  };
}

#endif // PARTICLE_FORCE_REGISTRY_H_INCLUDED
