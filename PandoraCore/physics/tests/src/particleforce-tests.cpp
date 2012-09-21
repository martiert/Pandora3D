#include <particleforce.h>
#include <particleforceregistry.h>
#include <particle.h>

#include <gtest/gtest.h>

class SimpleForce : public Physics::ParticleForce
{
  public:
    SimpleForce ()
      : called (false)
    {}

    virtual void update_force (Physics::ParticlePtr particle, Real duration)
    {
      called = true;
    }

    bool called;
};

typedef std::shared_ptr<SimpleForce> SimpleForcePtr;

class ParticleForceTest : public ::testing::Test
{
  protected:
    virtual void SetUp () {
      particle = std::make_shared<Physics::Particle> ();

      force1 = std::make_shared<SimpleForce> ();
      force2 = std::make_shared<SimpleForce> ();
    }

    Physics::ParticleForceRegistry registry;
    Physics::ParticlePtr particle;
    SimpleForcePtr force1;
    SimpleForcePtr force2;
};

TEST_F (ParticleForceTest, can_remove_force_particle_pair_from_registry)
{
  registry.remove (force1, particle);
}

TEST_F (ParticleForceTest, can_clear_force_registry)
{
  registry.clear ();
}

TEST_F (ParticleForceTest, calling_update_particles_with_one_force_particle_pair_calls_update_force_on_force)
{
  registry.add (force1, particle);
  registry.update_particles_with_forces (0);

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
  registry.remove (force2, particle);
  registry.update_particles_with_forces (0);

  EXPECT_FALSE (force1->called);
}

TEST_F (ParticleForceTest, adding_two_forces_to_a_particle_and_calling_update_particles_with_forces_calls_update_force_on_both_forces)
{
  registry.add (force1, particle);
  registry.add (force2, particle);
  registry.update_particles_with_forces (0);

  EXPECT_TRUE (force1->called);
  EXPECT_TRUE (force2->called);
}
