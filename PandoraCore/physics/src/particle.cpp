#include "particle.h"

#include <cmath>

namespace Physics
{
  Particle::Particle ()
    : damping (1.0),
      inverse_mass (0),
      gravity (default_gravity)
  {}

  Particle::Particle (const Math::Vector3<Real>& position)
    : damping (1.0),
      inverse_mass (0),
      position (position)
  {}

  Particle::Particle (const Math::Vector3<Real>& position, const Math::Vector3<Real>& velocity)
    : damping (1.0),
      inverse_mass (0),
      position (position),
      velocity (velocity),
      gravity (default_gravity)
  {}

  void Particle::update (const Real& dt)
  {
    position += dt * velocity;

    acceleration = inverse_mass * gravity;
    velocity *= std::pow (damping, dt);
    velocity += acceleration * dt;
  }

  const Math::Vector3<Real>& Particle::get_position () const
  {
    return position;
  }

  const Math::Vector3<Real>& Particle::get_velocity () const
  {
    return velocity;
  }

  const Math::Vector3<Real>& Particle::get_acceleration () const
  {
    return acceleration;
  }

  void Particle::set_mass (const Real& mass)
  {
    inverse_mass = 1/mass;
  }

  Real Particle::get_mass () const
  {
    return 1/inverse_mass;
  }

  void Particle::set_inverse_mass (const Real& inverse)
  {
    inverse_mass = inverse;
  }

  Real Particle::get_inverse_mass () const
  {
    return inverse_mass;
  }

  void Particle::set_gravity (const Real& new_gravity)
  {
    gravity = Math::Vector3<Real> (0, -new_gravity, 0);
  }

  const Math::Vector3<Real>& Particle::get_gravity () const
  {
    return gravity;
  }
}
