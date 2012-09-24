#include "particleforcetest.h"
#include <particle.h>

void ParticleForceTest::SetUp ()
{
  particle = std::make_shared<Physics::Particle> ();

  force1 = std::make_shared<SimpleForce> ();
  force2 = std::make_shared<SimpleForce> ();

  timestep = 0.45;
}

void ParticleForceTest::add_both_forces ()
{
  registry.add (force1, particle);
  registry.add (force2, particle);
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

TEST_F (ParticleForceTest, removing_force_makes_sure_we_dont_call_update_force_on_the_removed_force)
{
  registry.add (force1, particle);
  registry.remove (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_FALSE (force1->called);
}

TEST_F (ParticleForceTest, calling_update_particles_with_forces_calls_update_force_on_all_forces)
{
  add_both_forces ();
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force1->called);
  EXPECT_TRUE (force2->called);
}

TEST_F (ParticleForceTest, removing_one_force_particle_pair_still_calls_update_force_on_the_remaining_forces)
{
  add_both_forces ();
  registry.remove (force1, particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force2->called);
}

TEST_F (ParticleForceTest, clearing_registry_makes_sure_update_forces_is_not_called_on_any_force)
{
  add_both_forces ();
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

TEST_F (ParticleForceTest, trying_to_remove_force_particle_pair_will_not_remove_pair_if_not_particle_matches)
{
  auto other_particle = std::make_shared<Physics::Particle> ();
  registry.add (force1, particle);
  registry.remove (force1, other_particle);
  registry.update_particles_with_forces (timestep);

  EXPECT_TRUE (force1->called);
}
