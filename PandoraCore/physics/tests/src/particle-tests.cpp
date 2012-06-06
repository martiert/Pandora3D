#include <particle.h>

#include "test-helpers.h"

#include <gtest/gtest.h>

TEST (ParticleTest, default_create_particle_has_gravity_of_9_8_1)
{
    Physics::Particle particle;

    EXPECT_EQ (9.81, particle.gravity);
}

TEST (ParticleTest, creating_particle_with_argument_sets_gravity_to_the_argument)
{
    Physics::Particle particle (3.4);

    EXPECT_EQ (3.4, particle.gravity);
}

TEST (ParticleTest, copying_a_particle_gives_equal_gravity_for_the_two_particles)
{
    BEGIN_MULTITEST

    const Physics::Particle particle (create_random_scalar ());
    Physics::Particle copy = particle;

    EXPECT_EQ (particle.gravity, copy.gravity);

    END_MULTITEST
}
