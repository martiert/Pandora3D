#ifndef PHYSICS_PARTICLE_H_INCLUDED
#define PHYSICS_PARTICLE_H_INCLUDED

#include <config.h>
#include <vector3.h>

namespace Physics
{
  class Particle
  {
    public:
      Particle ();
      Particle (const Real& gravity);
      Particle (const Real& gravity, const Math::Vector3& position);
      Particle (const Real& gravity, const Math::Vector3& position,
                const Math::Vector3& velocity);
      Particle (const Real& gravity, const Math::Vector3& position,
                const Math::Vector3& velocity, const Math::Vector3& acceleration);

      void update (const Real& dt);

      const Math::Vector3& get_position () const;
      const Math::Vector3& get_velocity () const;
      const Math::Vector3& get_acceleration () const;
    public:
      Real gravity;
      Real damping;

    private:
      Math::Vector3 position;
      Math::Vector3 velocity;
      Math::Vector3 acceleration;
  };
}

#endif // PHYSICS_PARTICLE_H_INCLUDED
