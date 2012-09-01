#include "particle.h"

#include <cmath>

Physics::Particle::Particle ()
    : damping (1.0),
      inverse_mass (0),
      gravity (default_gravity)
{}

Physics::Particle::Particle (const Math::Vector3<Real>& position)
  : damping (1.0),
    inverse_mass (0),
    position (position)
{}

Physics::Particle::Particle (const Math::Vector3<Real>& position, const Math::Vector3<Real>& velocity)
  : damping (1.0),
    inverse_mass (0),
    position (position),
    velocity (velocity),
    gravity (default_gravity)
{}

void Physics::Particle::update (const Real& dt)
{
  position += dt * velocity;

  acceleration = inverse_mass * gravity;
  velocity *= std::pow (damping, dt);
  velocity += acceleration * dt;
}

const Math::Vector3<Real>& Physics::Particle::get_position () const
{
  return position;
}

const Math::Vector3<Real>& Physics::Particle::get_velocity () const
{
  return velocity;
}

const Math::Vector3<Real>& Physics::Particle::get_acceleration () const
{
  return acceleration;
}

void Physics::Particle::set_mass (const Real& mass)
{
  inverse_mass = 1/mass;
}

Real Physics::Particle::get_mass () const
{
  return 1/inverse_mass;
}

void Physics::Particle::set_inverse_mass (const Real& inverse)
{
  inverse_mass = inverse;
}

Real Physics::Particle::get_inverse_mass () const
{
  return inverse_mass;
}

void Physics::Particle::set_gravity (const Real& new_gravity)
{
  gravity = Math::Vector3<Real> (0, -new_gravity, 0);
}

const Math::Vector3<Real>& Physics::Particle::get_gravity () const
{
  return gravity;
}
