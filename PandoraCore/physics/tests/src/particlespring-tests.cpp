#include <particlespring.h>
#include <vector3.h>
#include <gtest/gtest.h>

TEST(ParticleSpringTests, initial_ancor_if_at_zero)
{
  Physics::ParticleSpring spring;
  EXPECT_EQ(Math::Vec3d::ZERO, spring.get_center());
}

TEST(ParticleSpringTests, initial_rest_length_is_zero)
{
  Physics::ParticleSpring spring;
  EXPECT_EQ(0, spring.get_rest_length());
}
