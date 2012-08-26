#include "vector4.h"
#include "vector3.h"

#include <sstream>
#include <cmath>

Math::Vector4::Vector4 ()
  : x (0), y (0), z (0), w (0)
{ }

Math::Vector4::Vector4 (const Real& x, const Real& y, const Real& z, const Real& w)
  : x (x), y (y), z (z), w (w)
{ }

Math::Vector4::Vector4 (const Real data[4])
  : x (data[0]), y (data[1]), z (data[2]), w (data[3])
{ }

Math::Vector4::Vector4 (const Vector3& vec)
  : x (vec.x), y (vec.y), z (vec.z), w (1)
{ }

Real& Math::Vector4::operator[] (const size_t& i)
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return (&x)[i];
}

Real Math::Vector4::operator[] (const size_t& i) const
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return (&x)[i];
}

Math::Vector4::operator Real* ()
{
  return &x;
}

Math::Vector4::operator const Real* () const
{
  return &x;
}

Math::Vector4& Math::Vector4::operator+= (const Vector4& vec)
{
  x += vec.x;
  y += vec.y;
  z += vec.z;
  w += vec.w;

  return *this;
}

Math::Vector4& Math::Vector4::operator-= (const Vector4& vec)
{
  x -= vec.x;
  y -= vec.y;
  z -= vec.z;
  w -= vec.w;

  return *this;
}

Math::Vector4& Math::Vector4::operator*= (const Vector4& vec)
{
  x *= vec.x;
  y *= vec.y;
  z *= vec.z;
  w *= vec.w;

  return *this;
}

Math::Vector4& Math::Vector4::operator*= (const Real& scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;

  return *this;
}

Math::Vector4& Math::Vector4::operator/= (const Real& scalar)
{
  if (scalar == 0)
    throw division_by_zero_exception ();

  x /= scalar;
  y /= scalar;
  z /= scalar;
  w /= scalar;

  return *this;
}

Real Math::Vector4::length () const
{
  return std::sqrt (this->lengthSquared ());
}

Real Math::Vector4::lengthSquared () const
{
  return dot (*this);
}

Real Math::Vector4::dot (const Vector4& vec) const
{
  return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

Math::Vector4& Math::Vector4::normalize ()
{
  Real len = length ();

  if (len == 0)
    throw normalizing_zero_vector_exception ();

  return *this /= len;
}

Math::Vector4 Math::operator- (const Vector4& vec)
{
  return Vector4 (-vec.x, -vec.y, -vec.z, -vec.w);
}

Math::Vector4 Math::operator+ (const Vector4& vec_1, const Vector4& vec_2)
{
  auto result = vec_1;
  result += vec_2;
  return result;
}

Math::Vector4 Math::operator- (const Vector4& vec_1, const Vector4& vec_2)
{
  auto result = vec_1;
  result -= vec_2;
  return result;
}

Math::Vector4 Math::operator* (const Vector4& vec_1, const Vector4& vec_2)
{
  auto tmp = vec_1;
  tmp *= vec_2;
  return tmp;
}

Math::Vector4 Math::operator* (const Vector4& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

Math::Vector4 Math::operator* (const Real& scalar, const Vector4& vec)
{
  return vec * scalar;
}

Math::Vector4 Math::operator/ (const Vector4& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

bool Math::operator== (const Vector4& vec1, const Vector4& vec2)
{
  return (vec1.x == vec2.x &&
      vec1.y == vec2.y &&
      vec1.z == vec2.z &&
      vec1.w == vec2.w);
}

bool Math::operator!= (const Vector4& vec1, const Vector4& vec2)
{
  return !(vec1 == vec2);
}

Math::Vector4::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
  : index (i)
{ }

const char* Math::Vector4::index_operator_out_of_range_exception::what () const throw ()
{
  std::stringstream out;
  out << "Tried to access index: " << index;
  return out.str ().c_str ();
}
