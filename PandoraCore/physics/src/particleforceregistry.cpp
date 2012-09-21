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
  particleforcepairs.clear ();
}

void Physics::ParticleForceRegistry::clear ()
{
}

void Physics::ParticleForceRegistry::update_particles_with_forces (const Real& timestep)
{
  auto force_update_routine = [] (ForceParticlePair& pair) { pair.update_force (0); };
  std::for_each (particleforcepairs.begin (), particleforcepairs.end (), force_update_routine);
}

Physics::ParticleForceRegistry::ForceParticlePair::ForceParticlePair (std::shared_ptr<ParticleForce> force,
                                                                      std::shared_ptr<Particle> particle)
  : force (force), particle (particle)
{}

void Physics::ParticleForceRegistry::ForceParticlePair::update_force (const Real& timestep)
{
  force->update_force (particle, 0);
}
