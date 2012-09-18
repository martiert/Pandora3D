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

TEST (ParticleForceTest, can_remove_force_particle_pair_from_registry)
{
  Physics::ParticleForceRegistry registry;
  Physics::ParticlePtr particle (new Physics::Particle ());
  SimpleForcePtr force (new SimpleForce ());

  registry.remove (force, particle);
}

TEST (ParticleForceTest, can_clear_force_registry)
{
  Physics::ParticleForceRegistry registry;
  registry.clear ();
}

TEST (ParticleForceTest, calling_update_particles_with_one_force_particle_pair_calls_update_force_on_force)
{
  Physics::ParticleForceRegistry registry;
  Physics::ParticlePtr particle (new Physics::Particle ());
  SimpleForcePtr force (new SimpleForce ());

  registry.add (force, particle);
  registry.update_particles_with_forces (0);

  EXPECT_TRUE (force->called);
}

TEST (ParticleForceTest, update_force_is_not_called_on_force_after_it_is_added)
{
  Physics::ParticleForceRegistry registry;
  Physics::ParticlePtr particle (new Physics::Particle ());
  SimpleForcePtr force (new SimpleForce ());

  registry.add (force, particle);

  EXPECT_FALSE (force->called);
}

TEST (ParticleForceTest, if_removing_already_added_force_particle_pair_before_update_particles_with_forces_is_called_does_not_call_update_force_on_force)
{
  Physics::ParticleForceRegistry registry;
  Physics::ParticlePtr particle (new Physics::Particle ());
  SimpleForcePtr force (new SimpleForce ());

  registry.add (force, particle);
  registry.remove (force, particle);
  registry.update_particles_with_forces (0);

  EXPECT_FALSE (force->called);
}
