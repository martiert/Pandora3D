#ifndef PARTICLE_FORCE_REGISTRY_H_INCLUDED
#define PARTICLE_FORCE_REGISTRY_H_INCLUDED

#include "config.h"
#include <vector>
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
      struct ForceParticlePair
      {
        public:
          ForceParticlePair (std::shared_ptr<ParticleForce> force, std::shared_ptr<Particle> particle);

          void update_force (const Real& timestep);

          bool is_same_force_particle_pair (std::shared_ptr<ParticleForce> force, std::shared_ptr<Particle> particle);
        private:
          std::shared_ptr<ParticleForce> force;
          std::shared_ptr<Particle> particle;
      };

      bool element_is_equal_and_erased (std::vector<ForceParticlePair>::iterator& element,
                                        std::shared_ptr<ParticleForce> force,
                                        std::shared_ptr<Particle> particle);

      std::vector<ForceParticlePair> particleforcepairs;
  };
}

#endif // PARTICLE_FORCE_REGISTRY_H_INCLUDED
