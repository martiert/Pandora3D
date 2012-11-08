#include <particlespring.h>
#include <particle.h>
#include <particleforceregistry.h>

#include <gtest/gtest.h>

TEST(ParticleSpringTests, particlespring_can_be_added_to_particleforceregistry)
{
  Physics::ParticleForceRegistry registry;
  std::shared_ptr<Physics::ParticleSpring> spring;
  std::shared_ptr<Physics::Particle> particle;

  registry.add(spring, particle);
}

TEST(ParticleSpringTests, particlespring_constructor_takes_particle_constant_and_restlength)
{
  std::shared_ptr<Physics::Particle> particle;
  Physics::ParticleSpring spring(particle, 1, 1);
}
