#ifndef PARTICLEFORCETEST_H_INCLUDED
#define PARTICLEFORCETEST_H_INCLUDED

#include <particleforce.h>
#include <particleforceregistry.h>

#include <gtest/gtest.h>

class SimpleForce : public Physics::ParticleForce
{
  public:
    SimpleForce ()
      : called (false), step_recieved (0)
    {}

    virtual void update_force (std::shared_ptr<Physics::Particle> /* particle */, Real duration)
    {
      called = true;
      step_recieved = duration;
    }

    bool called;
    Real step_recieved;
};

typedef std::shared_ptr<SimpleForce> SimpleForcePtr;

class ParticleForceTest : public ::testing::Test
{
  protected:
    virtual void SetUp ();

    Physics::ParticleForceRegistry registry;
    std::shared_ptr<Physics::Particle> particle;
    SimpleForcePtr force1;
    SimpleForcePtr force2;
    Real timestep;
};

#endif // PARTICLEFORCETEST_H_INCLUDED
