#include "particleforceregistry.h"
#include "particleforce.h"
#include "particle.h"

void Physics::ParticleForceRegistry::add (Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
  this->force = force;
  this->particle = particle;
}

void Physics::ParticleForceRegistry::remove (Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
  this->force = nullptr;
}

void Physics::ParticleForceRegistry::clear ()
{
}

void Physics::ParticleForceRegistry::update_particles_with_forces (const Real& timestep)
{
  if (force != nullptr)
    force->update_force (particle, 0);
}
