#include "particle.h"

Physics::Particle::Particle ()
    : gravity (9.81)
{}

Physics::Particle::Particle (const Real& gravity)
    : gravity (gravity)
{}
