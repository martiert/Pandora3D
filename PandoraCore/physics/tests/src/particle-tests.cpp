#include <particle.h>

#include "test-helpers.h"
#include <gtest/gtest.h>

TEST (ParticleTest, default_create_particle_has_inverse_mass_of_0)
{
  Physics::Particle particle;

  EXPECT_EQ (0, particle.get_inverse_mass ());
}

TEST (ParticleTest, copying_a_particle_gives_equal_mass_for_the_two_particles)
{
  BEGIN_MULTITEST

  Physics::Particle particle;
  particle.set_inverse_mass (create_random_scalar ());
  Physics::Particle copy = particle;

  EXPECT_EQ (particle.get_mass (), copy.get_mass ());

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_without_initial_position_sets_position_to_origin)
{
  BEGIN_MULTITEST

  const Physics::Particle particle;
  const Math::Vector3 origin;

  EXPECT_EQ (origin, particle.get_position ());

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_with_initial_position_sets_position)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const Physics::Particle particle (position);

  EXPECT_EQ (position, particle.get_position ());

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_without_initial_velocity_gives_zero_velocity)
{
  const Physics::Particle particle (create_random_vector3 ());
  const Math::Vector3 zero;

  EXPECT_EQ (zero, particle.get_velocity ());
}

TEST (ParticleTest, creating_particle_with_initial_velocity_sets_velocity_and_position)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const Physics::Particle particle (position, velocity);

  EXPECT_EQ (position, particle.get_position ());
  EXPECT_EQ (velocity, particle.get_velocity ());

  END_MULTITEST
}

TEST (ParticleTest, initial_acceleration_of_particle_is_the_zero_vector)
{
  const Physics::Particle particle (create_random_vector3 (), create_random_vector3 ());
  const Math::Vector3 zero;

  EXPECT_EQ (zero, particle.get_acceleration ());
}

TEST (ParticleTest, damping_is_set_to_1_if_not_specified)
{
  const Physics::Particle particle;
  EXPECT_EQ (1.0, particle.damping);
}

TEST (ParticleTest, default_gravity_of_particle_is_equal_to_physics_default_gravity)
{
  const Physics::Particle particle;

  EXPECT_EQ (particle.get_gravity (), Physics::default_gravity);
}

TEST (ParticleTest, setting_gravity_on_particle_makes_the_y_part_of_the_gravity_vector_minus_argument_and_rest_zero)
{
  BEGIN_MULTITEST

  const auto gravity = create_random_scalar ();
  Physics::Particle particle;
  particle.set_gravity (gravity);

  EXPECT_EQ (Math::Vector3 (0, -gravity, 0), particle.get_gravity ());

  END_MULTITEST
}

TEST (ParticleTest, updating_the_particle_with_timestep_of_one_moves_position_equal_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (position, velocity);
  particle.update (1);

  EXPECT_EQ (position + velocity, particle.get_position ());

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_timestep_of_one_half_moves_position_half_of_the_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (position, velocity);
  particle.update (0.5);

  EXPECT_EQ (position + 0.5 * velocity, particle.get_position ());

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_no_damping_or_forces_applied_do_not_change_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (position, velocity);
  particle.set_mass (1);
  particle.set_gravity (0);
  particle.update (0.5);

  EXPECT_EQ (velocity, particle.get_velocity ());

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_timestep_of_one_damping_and_no_forces_change_velocity_to_itself_times_damping)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto damping = create_random_scalar ();

  Physics::Particle particle (position, velocity);
  particle.set_mass (1);
  particle.set_gravity (0);
  particle.damping = damping;

  particle.update (1);
  EXPECT_EQ (damping * velocity, particle.get_velocity ());

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_without_forces_changes_velocity_to_damping_to_the_power_of_timestep)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto damping = create_random_scalar ();
  auto timestep = (Real) (rand () % 10000);
  timestep /= 10000;
  const auto change = std::pow (damping, timestep);

  Physics::Particle particle (position, velocity);
  particle.set_mass (1);
  particle.set_gravity (0);
  particle.damping = damping;

  particle.update (timestep);
  EXPECT_EQ (change * velocity, particle.get_velocity ());

  END_MULTITEST
}

TEST (ParticleTest, particle_with_velocity_no_damping_or_forces_will_not_change_velocity)
{
  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const Real timestep = 0.431;

  Physics::Particle particle (position, velocity);
  particle.set_mass (1);
  particle.set_gravity (0);

  for (size_t i = 0; i < 400; ++i) {
    particle.update (timestep);
    EXPECT_EQ (velocity, particle.get_velocity ());
  }
}

TEST (ParticleTest, particle_with_zero_inverse_mass_will_never_change_velocity)
{
  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const Real timestep = 0.431;

  Physics::Particle particle (position, velocity);

  for (size_t i = 0; i < 400; ++i) {
    particle.update (timestep);
    EXPECT_EQ (velocity, particle.get_velocity ());
  }
}

TEST (ParticleTest, y_component_of_velocity_of_particle_with_positive_mass_and_gravity_will_decrease_for_each_update)
{
  Physics::Particle particle;
  particle.set_inverse_mass (3.4);
  auto velocity = particle.get_velocity ();

  for (size_t i = 0; i < 400; ++i) {
    particle.update (0.45);
    const auto new_velocity = particle.get_velocity ();

    EXPECT_EQ (new_velocity.x, velocity.x);
    EXPECT_LT (new_velocity.y, velocity.y);
    EXPECT_EQ (new_velocity.z, velocity.z);
    velocity = new_velocity;
  }
}
