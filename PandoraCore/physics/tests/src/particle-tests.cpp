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

TEST (ParticleTest, creating_particle_without_initial_position_sets_position_to_origin)
{
  BEGIN_MULTITEST

  const Physics::Particle particle (create_random_scalar ());
  const Math::Vector3 origin;

  EXPECT_EQ (particle.get_position (), origin);

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_with_initial_position_sets_position)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const Physics::Particle particle (9.8, position);

  EXPECT_EQ (particle.get_position (), position);

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_without_initial_velocity_gives_zero_velocity)
{
  const Physics::Particle particle (9.8, create_random_vector3 ());
  const Math::Vector3 zero;

  EXPECT_EQ (particle.get_velocity (), zero);
}

TEST (ParticleTest, creating_particle_with_initial_velocity_sets_velocity_and_position)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const Physics::Particle particle (9.8, position, velocity);

  EXPECT_EQ (particle.get_position (), position);
  EXPECT_EQ (particle.get_velocity (), velocity);

  END_MULTITEST
}

TEST (ParticleTest, creating_particle_without_initial_acceleration_gives_zero_acceleration)
{
  const Physics::Particle particle (9.8, create_random_vector3 (), create_random_vector3 ());
  const Math::Vector3 zero;

  EXPECT_EQ (particle.get_acceleration (), zero);
}

TEST (ParticleTest, creating_particle_with_initial_acceleration_sets_acceleration)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto acceleration = create_random_vector3 ();

  const Physics::Particle particle (9.8, position, velocity, acceleration);

  EXPECT_EQ (particle.get_position (), position);
  EXPECT_EQ (particle.get_velocity (), velocity);
  EXPECT_EQ (particle.get_acceleration (), acceleration);

  END_MULTITEST
}

TEST (ParticleTest, damping_is_set_to_1_if_nothing_else_is_specified)
{
  const Physics::Particle particle;
  EXPECT_EQ (particle.damping, 1.0);
}

TEST (ParticleTest, updating_the_particle_with_timestep_of_one_moves_position_equal_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (9.8, position, velocity);
  particle.update (1);

  EXPECT_EQ (particle.get_position (), position + velocity);

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_timestep_of_one_half_moves_position_half_of_the_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (9.8, position, velocity);
  particle.update (0.5);

  EXPECT_EQ (particle.get_position (), position + 0.5*velocity);

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_no_damping_and_no_acceleration_dont_change_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();

  Physics::Particle particle (9.8, position, velocity);
  particle.update (0.5);

  EXPECT_EQ (particle.get_velocity (), velocity);

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_timestep_of_one_damping_and_no_forces_change_velocity_to_itself_times_damping)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto damping = create_random_scalar ();

  Physics::Particle particle (9.8, position, velocity);
  particle.damping = damping;

  particle.update (1);
  EXPECT_EQ (particle.get_velocity (), damping * velocity);

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

  Physics::Particle particle (9.8, position, velocity);
  particle.damping = damping;

  particle.update (timestep);
  EXPECT_EQ (particle.get_velocity (), change * velocity);

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_acceleration_and_timestep_of_one_makes_new_velocity_the_damped_velocity_times_acceleration)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto acceleration = create_random_vector3 ();
  const auto damping = create_random_scalar ();

  Physics::Particle particle (9.8, position, velocity, acceleration);
  particle.damping = damping;

  particle.update (1);
  EXPECT_EQ (particle.get_velocity (), damping * velocity + acceleration);

  END_MULTITEST
}

TEST (ParticleTest, updating_particle_with_acceleration_adds_acceleration_times_timestep_to_the_damped_velocity)
{
  BEGIN_MULTITEST

  const auto position = create_random_vector3 ();
  const auto velocity = create_random_vector3 ();
  const auto acceleration = create_random_vector3 ();
  const auto damping = create_random_scalar ();
  auto timestep = (Real) (rand () % 10000);
  timestep /= 10000;
  const auto change = std::pow (damping, timestep);

  Physics::Particle particle (9.8, position, velocity, acceleration);
  particle.damping = damping;

  particle.update (timestep);

  EXPECT_EQ (particle.get_velocity (), change * velocity + timestep * acceleration);

  END_MULTITEST
}
