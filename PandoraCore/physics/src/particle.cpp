#include "particle.h"

#include <cmath>

namespace Physics
{
  Particle::Particle()
    : damping(1.0),
      inverse_mass(0),
      gravity(default_gravity)
  {}

  Particle::Particle(const Vector3& position)
    : damping(1.0),
      inverse_mass(0),
      position(position)
  {}

  Particle::Particle(const Vector3& position, const Vector3& velocity)
    : damping(1.0),
      inverse_mass(0),
      position(position),
      velocity(velocity),
      gravity(default_gravity)
  {}

  void Particle::update(const real& dt)
  {
    position += dt * velocity;

    acceleration = inverse_mass * gravity;
    velocity *= std::pow(damping, dt);
    velocity += acceleration * dt;
  }

  const Vector3& Particle::get_position() const
  {
    return position;
  }

  const Vector3& Particle::get_velocity() const
  {
    return velocity;
  }

  const Vector3& Particle::get_acceleration() const
  {
    return acceleration;
  }

  void Particle::set_mass(const real& mass)
  {
    inverse_mass = 1/mass;
  }

  real Particle::get_mass() const
  {
    return 1/inverse_mass;
  }

  void Particle::set_inverse_mass(const real& inverse)
  {
    inverse_mass = inverse;
  }

  real Particle::get_inverse_mass() const
  {
    return inverse_mass;
  }

  void Particle::set_gravity(const real& new_gravity)
  {
    gravity = Vector3({0, -new_gravity, 0});
  }

  const Vector3& Particle::get_gravity() const
  {
    return gravity;
  }
}
