#include "particleforceregistry.h"
#include "particleforce.h"
#include "particle.h"

#include <algorithm>

namespace Physics
{

void ParticleForceRegistry::add(Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
    ForceParticlePair pair{force, particle};
    particleforcepairs.push_front(pair);
}

void ParticleForceRegistry::remove(Physics::ParticleForcePtr force, Physics::ParticlePtr particle)
{
    ForceParticlePair pair{force, particle};
    particleforcepairs.remove(pair);
}

void ParticleForceRegistry::clear()
{
    particleforcepairs.clear();
}

void ParticleForceRegistry::update_particles_with_forces(const real & timestep)
{
    if (timestep == 0) {
        return;
    }

    auto update_force = [&timestep](ForceParticlePair & pair) { pair.update_force(timestep); };
    std::for_each(particleforcepairs.begin(), particleforcepairs.end(), update_force);
}

ParticleForceRegistry::ForceParticlePair::ForceParticlePair(std::shared_ptr<ParticleForce> force, std::shared_ptr<Particle> particle)
    : force(force), particle(particle)
{}

void ParticleForceRegistry::ForceParticlePair::update_force(const real & timestep)
{
    force->update_force(particle, timestep);
}

bool ParticleForceRegistry::ForceParticlePair::operator==(const ParticleForceRegistry::ForceParticlePair & other)
{
    return (this->force == other.force && this->particle == other.particle);
}

}
