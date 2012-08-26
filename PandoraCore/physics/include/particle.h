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
      Particle (const Real& mass);
      Particle (const Real& mass, const Math::Vector3& position);
      Particle (const Real& mass, const Math::Vector3& position,
                const Math::Vector3& velocity);
      Particle (const Real& mass, const Math::Vector3& position,
                const Math::Vector3& velocity, const Math::Vector3& acceleration);

      void update (const Real& dt);

      const Math::Vector3& get_position () const;
      const Math::Vector3& get_velocity () const;
      const Math::Vector3& get_acceleration () const;

      void set_mass (const Real& mass);
      Real get_mass () const;

      void set_inverse_mass (const Real& inverse);
      Real get_inverse_mass () const;
    public:
      Real damping;

    private:
      Real inverse_mass;
      Math::Vector3 position;
      Math::Vector3 velocity;
      Math::Vector3 acceleration;
  };
}

#endif // PHYSICS_PARTICLE_H_INCLUDED
