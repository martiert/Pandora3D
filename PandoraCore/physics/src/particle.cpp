#include "particle.h"

#include <cmath>

Physics::Particle::Particle ()
    : gravity (9.81), damping (1.0)
{}

Physics::Particle::Particle (const Real& gravity)
    : gravity (gravity), damping (1.0)
{}

Physics::Particle::Particle (const Real& gravity, const Math::Vector3& position)
  : gravity (gravity), damping (1.0), position (position)
{}

Physics::Particle::Particle (const Real& gravity, const Math::Vector3& position,
    const Math::Vector3& velocity)
  : gravity (gravity),
    damping (1.0),
    position (position),
    velocity (velocity)
{}

Physics::Particle::Particle (const Real& gravity, const Math::Vector3& position,
    const Math::Vector3& velocity, const Math::Vector3& acceleration)
  : gravity (gravity),
    damping (1.0),
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
