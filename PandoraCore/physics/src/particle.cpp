#include "particle.h"

#include <cmath>

Physics::Particle::Particle ()
    : damping (1.0),
      inverse_mass (0)
{}

Physics::Particle::Particle (const Real& mass)
    : damping (1.0),
      inverse_mass (1/mass)
{}

Physics::Particle::Particle (const Real& mass, const Math::Vector3& position)
  : damping (1.0),
    inverse_mass (1/mass),
    position (position)
{}

Physics::Particle::Particle (const Real& mass, const Math::Vector3& position,
    const Math::Vector3& velocity)
  : damping (1.0),
    inverse_mass (1/mass),
    position (position),
    velocity (velocity)
{}

Physics::Particle::Particle (const Real& mass, const Math::Vector3& position,
    const Math::Vector3& velocity, const Math::Vector3& acceleration)
  : damping (1.0),
    inverse_mass (mass),
    position (position),
    velocity (velocity),
    acceleration (acceleration)
{}

void Physics::Particle::update (const Real& dt)
{
  position += dt * velocity;

  velocity *= std::pow (damping, dt);
  velocity += acceleration * dt;
}

const Math::Vector3& Physics::Particle::get_position () const
{
  return position;
}

const Math::Vector3& Physics::Particle::get_velocity () const
{
  return velocity;
}

const Math::Vector3& Physics::Particle::get_acceleration () const
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

