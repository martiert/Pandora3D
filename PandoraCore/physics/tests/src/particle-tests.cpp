#include "particle-test-harness.h"
#include "test-helpers.h"

TEST_F(ParticleTest, default_create_particle_has_inverse_mass_of_0)
{
  EXPECT_EQ(0, default_particle.get_inverse_mass());
}

TEST_F(ParticleTest, copying_a_particle_gives_equal_mass_for_the_two_particles)
{
  default_particle.set_inverse_mass(create_random_scalar());
  Physics::Particle copy = default_particle;

  EXPECT_EQ(default_particle.get_mass(), copy.get_mass());
}

TEST_F(ParticleTest, creating_particle_without_initial_position_sets_position_to_origin)
{
  EXPECT_EQ(origin, default_particle.get_position());
}

TEST_F(ParticleTest, creating_particle_with_initial_position_sets_position)
{
  EXPECT_EQ(initial_position, random_position_particle.get_position());
}

TEST_F(ParticleTest, creating_particle_without_initial_velocity_gives_zero_velocity)
{
  EXPECT_EQ(zero_vector, random_position_particle.get_velocity());
}

TEST_F(ParticleTest, creating_particle_with_initial_velocity_sets_velocity_and_position)
{
  EXPECT_EQ(initial_position, random_particle.get_position());
  EXPECT_EQ(initial_velocity, random_particle.get_velocity());
}

TEST_F(ParticleTest, initial_acceleration_of_particle_is_the_zero_vector)
{
  EXPECT_EQ(zero_vector, random_particle.get_acceleration());
}

TEST_F(ParticleTest, damping_is_set_to_1_if_not_specified)
{
  EXPECT_EQ(1.0, random_particle.damping);
}

TEST_F(ParticleTest, default_gravity_of_particle_is_equal_to_physics_default_gravity)
{
  EXPECT_EQ(random_particle.get_gravity(), Physics::default_gravity);
}

TEST_F(ParticleTest, setting_gravity_on_particle_makes_the_y_part_of_the_gravity_vector_minus_argument_and_rest_zero)
{
  const auto gravity = create_random_scalar();
  random_particle.set_gravity(gravity);

  EXPECT_EQ(Physics::Vector3({0, -gravity, 0}), random_particle.get_gravity());
}

TEST_F(ParticleTest, updating_the_particle_with_timestep_of_one_moves_position_equal_velocity)
{
  random_particle.update(1);

  EXPECT_EQ(initial_position + initial_velocity, random_particle.get_position());
}

TEST_F(ParticleTest, updating_particle_with_timestep_of_one_half_moves_position_half_of_the_velocity)
{
  random_particle.update(0.5);

  EXPECT_EQ(initial_position + 0.5 * initial_velocity, random_particle.get_position());
}

TEST_F(ParticleTest, updating_particle_with_no_damping_or_forces_applied_do_not_change_velocity)
{
  set_mass_gravity(1, 0);
  random_particle.update(0.5);

  EXPECT_EQ(initial_velocity, random_particle.get_velocity());
}

TEST_F(ParticleTest, updating_particle_with_timestep_of_one_damping_and_no_forces_change_velocity_to_itself_times_damping)
{
  set_mass_gravity_damping(1, 0, damping);
  random_particle.update(1);

  EXPECT_EQ(damping * initial_velocity, random_particle.get_velocity());
}

TEST_F(ParticleTest, updating_particle_without_forces_changes_velocity_to_damping_to_the_power_of_timestep)
{
  set_mass_gravity_damping(1, 0, damping);
  random_particle.update(timestep);

  EXPECT_EQ(change * initial_velocity, random_particle.get_velocity());
}

TEST_F(ParticleTest, particle_with_velocity_no_damping_or_forces_will_not_change_velocity)
{
  set_mass_gravity(1, 0);

  for (size_t i = 0; i < 400; ++i) {
    random_particle.update(timestep);
    EXPECT_EQ(initial_velocity, random_particle.get_velocity());
  }
}

TEST_F(ParticleTest, particle_with_zero_inverse_mass_will_never_change_velocity)
{
  for (size_t i = 0; i < 400; ++i) {
    random_particle.update(timestep);
    EXPECT_EQ(initial_velocity, random_particle.get_velocity());
  }
}

TEST_F(ParticleTest, y_component_of_velocity_of_particle_with_positive_mass_and_gravity_will_decrease_for_each_update)
{
  default_particle.set_inverse_mass(3.4);
  auto velocity = default_particle.get_velocity();

  for (size_t i = 0; i < 400; ++i) {
    default_particle.update(0.45);
    EXPECT_TRUE(velocity_have_decreased_in_y_direction_while_x_and_y_have_not_changed(velocity));
    velocity = default_particle.get_velocity();
  }
}
