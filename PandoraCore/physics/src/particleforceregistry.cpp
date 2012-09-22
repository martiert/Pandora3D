#include "particleforceregistry.h"
#include "particleforce.h"
#include "particle.h"

#include <algorithm>

void Physics::ParticleForceRegistry::add (Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
  ForceParticlePair pair {force, particle};
  particleforcepairs.push_back (pair);
}

void Physics::ParticleForceRegistry::remove (Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
  for (auto element = particleforcepairs.begin (); element != particleforcepairs.end (); ++element) {
    if (element->is_same_force_particle_pair (force, particle)) {
      particleforcepairs.erase (element);
      break;
    }
  }
}

void Physics::ParticleForceRegistry::clear ()
{
  particleforcepairs.clear ();
}

void Physics::ParticleForceRegistry::update_particles_with_forces (const Real& timestep)
{
  if (timestep == 0)
    return;

  auto update_force = [&timestep] (ForceParticlePair& pair) { pair.update_force (timestep); };
  std::for_each (particleforcepairs.begin (), particleforcepairs.end (), update_force);
}

Physics::ParticleForceRegistry::ForceParticlePair::ForceParticlePair (std::shared_ptr<ParticleForce> force,
                                                                      std::shared_ptr<Particle> particle)
  : force (force), particle (particle)
{}

void Physics::ParticleForceRegistry::ForceParticlePair::update_force (const Real& timestep)
{
  force->update_force (particle, timestep);
}

bool Physics::ParticleForceRegistry::ForceParticlePair::is_same_force_particle_pair (std::shared_ptr<ParticleForce> force,
                                                                                     std::shared_ptr<Particle> particle)
{
  return (this->force == force && this->particle == particle);
}
