#ifndef PARTICLE_PHYSICS_H_INCLUDED
#define PARTICLE_PHYSICS_H_INCLUDED

#include <config.h>
#include <vector3.h>
#include <memory>

namespace Physics
{
  static const Vector3 default_gravity({0, -9.8, 0});

  class Particle
  {
    public:
      explicit Particle();
      explicit Particle(const Vector3& position);
      explicit Particle(const Vector3& position, const Vector3& velocity);

      virtual void update(const real& dt);

      const Vector3& get_position() const;
      const Vector3& get_velocity() const;
      const Vector3& get_acceleration() const;

      void set_mass(const real& mass);
      real get_mass() const;

      void set_inverse_mass(const real& inverse);
      real get_inverse_mass() const;

      void set_gravity(const real& new_gravity);
      const Vector3& get_gravity() const;
    public:
      real damping;

    protected:
      real inverse_mass;

      Vector3 position;
      Vector3 velocity;
      Vector3 acceleration;

      Vector3 gravity;
  };

  typedef std::shared_ptr<Particle> ParticlePtr;
}

#endif // PARTICLE_PHYSICS_H_INCLUDED
