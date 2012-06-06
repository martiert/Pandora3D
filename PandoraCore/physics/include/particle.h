#ifndef PHYSICS_PARTICLE_H_INCLUDED
#define PHYSICS_PARTICLE_H_INCLUDED

#include <config.h>

namespace Physics
{
    class Particle
    {
        public:
            Particle ();

            Particle (const Real& gravity);

        public:
            Real gravity;
    };
}

#endif // PHYSICS_PARTICLE_H_INCLUDED
