#ifndef PARTICLETESTHARNESS_H_INCLUDED
#define PARTICLETESTHARNESS_H_INCLUDED

#include <particle.h>

#include <gtest/gtest.h>

class ParticleTest : public ::testing::Test
{
  protected:
    ParticleTest();
    void set_mass_gravity(const Real& mass, const Real& gravity);
    void set_mass_gravity_damping(const Real& mass, const Real& gravity, const Real& damping);
    bool velocity_have_decreased_in_y_direction_while_x_and_y_have_not_changed(const Math::Vector3<Real>& velocity);

    Math::Vector3<Real> initial_position;
    Math::Vector3<Real> initial_velocity;
    Math::Vector3<Real> origin;

    Physics::Particle default_particle;
    Physics::Particle random_position_particle;
    Physics::Particle random_particle;

    Real timestep;
    Real damping;
    Real change;
};

#endif
