#include "particle-test-harness.h"
#include "test-helpers.h"

ParticleTest::ParticleTest()
    : initial_position(create_random_vector3()),
      initial_velocity(create_random_vector3()),
      origin(zero_vector),
      default_particle(),
      random_position_particle(initial_position),
      random_particle(initial_position, initial_velocity),
      timestep((real)(rand() % 10000) / 10000),
      damping(create_random_scalar()),
      change(std::pow(damping, timestep))
{ }

void ParticleTest::set_mass_gravity(const real & mass, const real & gravity)
{
    default_particle.set_mass(mass);
    default_particle.set_gravity(gravity);

    random_position_particle.set_mass(mass);
    random_position_particle.set_gravity(gravity);

    random_particle.set_mass(mass);
    random_particle.set_gravity(gravity);
}

void ParticleTest::set_mass_gravity_damping(const real & mass, const real & gravity, const real & damping)
{
    set_mass_gravity(mass, gravity);

    default_particle.damping = damping;
    random_position_particle.damping = damping;
    random_particle.damping = damping;
}

bool ParticleTest::velocity_have_decreased_in_y_direction_while_x_and_y_have_not_changed(const Physics::Vector3 & velocity)
{
    auto new_velocity = default_particle.get_velocity();
    return (new_velocity[1] < velocity[1] &&
            new_velocity[0] == velocity[0] &&
            new_velocity[2] == velocity[2]);
}
