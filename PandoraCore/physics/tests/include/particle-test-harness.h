#ifndef PARTICLETESTHARNESS_H_INCLUDED
#define PARTICLETESTHARNESS_H_INCLUDED

#include <particle.h>

#include <gtest/gtest.h>

const Physics::Vector3 zero_vector;

class ParticleTest : public ::testing::Test
{
  protected:
    ParticleTest();
    void set_mass_gravity(const real& mass, const real& gravity);
    void set_mass_gravity_damping(const real& mass, const real& gravity, const real& damping);
    bool velocity_have_decreased_in_y_direction_while_x_and_y_have_not_changed(const Physics::Vector3& velocity);

    Physics::Vector3 initial_position;
    Physics::Vector3 initial_velocity;
    Physics::Vector3 origin;

    Physics::Particle default_particle;
    Physics::Particle random_position_particle;
    Physics::Particle random_particle;

    real timestep;
    real damping;
    real change;
};

#endif
