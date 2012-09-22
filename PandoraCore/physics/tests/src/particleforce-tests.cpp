#include "particleforcetest.h"
#include <particle.h>

void ParticleForceTest::SetUp () {
  particle = std::make_shared<Physics::Particle> ();

  force1 = std::make_shared<SimpleForce> ();
  force2 = std::make_shared<SimpleForce> ();

  timestep = 0.45;
}

TEST_F (ParticleForceTest, can_clear_force_registry)
{
  registry.clear ();
}

TEST_F (ParticleForceTest, calling_update_particles_with_one_force_particle_pair_calls_update_force_on_force)
{
  registry.add (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force1->called);
}

TEST_F (ParticleForceTest, update_force_is_not_called_on_force_after_it_is_added)
{
  registry.add (force1, particle);

  EXPECT_FALSE (force1->called);
}

TEST_F (ParticleForceTest, if_removing_already_added_force_particle_pair_before_update_particles_with_forces_is_called_does_not_call_update_force_on_force)
{
  registry.add (force1, particle);
  registry.remove (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_FALSE (force1->called);
}

TEST_F (ParticleForceTest, adding_two_forces_to_a_particle_and_calling_update_particles_with_forces_calls_update_force_on_both_forces)
{
  registry.add (force1, particle);
  registry.add (force2, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force1->called);
  EXPECT_TRUE (force2->called);
}

TEST_F (ParticleForceTest, adding_two_forces_to_a_particle_removing_the_first_force_and_calling_update_particles_with_forces_calls_update_force_on_the_remaining_force)
{
  registry.add (force1, particle);
  registry.add (force2, particle);
  registry.remove (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force2->called);
}

TEST_F (ParticleForceTest, after_clearing_registry_and_calling_update_particle_with_forces_no_forces_have_been_called_with_update_force)
{
  registry.add (force1, particle);
  registry.add (force2, particle);
  registry.clear ();
  registry.update_particles_with_forces (timestep);

  EXPECT_FALSE (force1->called);
  EXPECT_FALSE (force2->called);
}

TEST_F (ParticleForceTest, calling_update_particles_with_forces_forwards_the_timestep_to_the_force_in_update_force)
{
  registry.add (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_EQ (timestep, force1->step_recieved);
}

TEST_F (ParticleForceTest, calling_update_particles_with_forces_with_zero_timestep_does_not_call_the_forces)
{
  registry.add (force1, particle);
  registry.update_particles_with_forces (0);

  EXPECT_FALSE (force1->called);
}
