#ifndef PHYSICS_PARTICLE_H_INCLUDED
#define PHYSICS_PARTICLE_H_INCLUDED

#include <config.h>
#include <vector3.h>

namespace Physics
{
  static const Math::Vector3 default_gravity (0, -9.8, 0);

  class Particle
  {
    public:
      Particle ();
      Particle (const Math::Vector3& position);
      Particle (const Math::Vector3& position, const Math::Vector3& velocity);

      virtual void update (const Real& dt);

      const Math::Vector3& get_position () const;
      const Math::Vector3& get_velocity () const;
      const Math::Vector3& get_acceleration () const;

      void set_mass (const Real& mass);
      Real get_mass () const;

      void set_inverse_mass (const Real& inverse);
      Real get_inverse_mass () const;

      void set_gravity (const Real& new_gravity);
      const Math::Vector3& get_gravity () const;
    public:
      Real damping;

    protected:
      Real inverse_mass;

      Math::Vector3 position;
      Math::Vector3 velocity;
      Math::Vector3 acceleration;

      Math::Vector3 gravity;
  };
}

#endif // PHYSICS_PARTICLE_H_INCLUDED