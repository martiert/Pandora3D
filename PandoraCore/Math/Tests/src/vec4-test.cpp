#include <Math/vector4.h>
#include <Math/vector3.h>

#include <gtest/gtest.h>

TEST (Vector4Test, construction)
{
  const Math::Vec4d vector_1;
  EXPECT_EQ (0.0, vector_1.x ());
  EXPECT_EQ (0.0, vector_1.y ());
  EXPECT_EQ (0.0, vector_1.z ());
  EXPECT_EQ (0.0, vector_1.w ());

  const Math::Vec4d vector_2 (0.1, 7.8, 4.3, 2.3);
  EXPECT_EQ (0.1, vector_2.x ());
  EXPECT_EQ (7.8, vector_2.y ());
  EXPECT_EQ (4.3, vector_2.z ());
  EXPECT_EQ (2.3, vector_2.w ());

  double tmp[] = {3.4, 3.2, 2.1, 5.4};
  const Math::Vec4d vector_3 (tmp);
  EXPECT_EQ (tmp[0], vector_3.x ());
  EXPECT_EQ (tmp[1], vector_3.y ());
  EXPECT_EQ (tmp[2], vector_3.z ());
  EXPECT_EQ (tmp[3], vector_3.w ());

  const Math::Vec4d vector_4 (vector_1);
  EXPECT_EQ (vector_1.x (), vector_4.x ());
  EXPECT_EQ (vector_1.y (), vector_4.y ());
  EXPECT_EQ (vector_1.z (), vector_4.z ());
  EXPECT_EQ (vector_1.w (), vector_4.w ());

  const Math::Vec4d vector_5 = vector_2;
  EXPECT_EQ (vector_2.x (), vector_5.x ());
  EXPECT_EQ (vector_2.y (), vector_5.y ());
  EXPECT_EQ (vector_2.z (), vector_5.z ());
  EXPECT_EQ (vector_2.w (), vector_5.w ());

  const Math::Vec4d vector_6 = tmp;
  EXPECT_EQ (tmp[0], vector_6.x ());
  EXPECT_EQ (tmp[1], vector_6.y ());
  EXPECT_EQ (tmp[2], vector_6.z ());
  EXPECT_EQ (tmp[3], vector_6.w ());

  const Math::Vec3d tmp_vector (4.5, 3.2, 1.9);
  const Math::Vec4d vector_7 (tmp_vector);
  EXPECT_EQ (tmp_vector.x (), vector_7.x ());
  EXPECT_EQ (tmp_vector.y (), vector_7.y ());
  EXPECT_EQ (tmp_vector.z (), vector_7.z ());
  EXPECT_EQ (1.0, vector_7.w ());

  const Math::Vec4d vector_8 = tmp_vector;
  EXPECT_EQ (tmp_vector.x (), vector_8.x ());
  EXPECT_EQ (tmp_vector.y (), vector_8.y ());
  EXPECT_EQ (tmp_vector.z (), vector_8.z ());
  EXPECT_EQ (1.0, vector_8.w ());
}

TEST (Vector4Test, index_operator_valid_input)
{
  Math::Vec4d vector_1 (2.3, 4.2, 5.1, 1.3);
  const Math::Vec4d vector_2 (2.3, 6.7, 8.9, 1.6);

  EXPECT_EQ (2.3, vector_1[0]);
  EXPECT_EQ (4.2, vector_1[1]);
  EXPECT_EQ (5.1, vector_1[2]);
  EXPECT_EQ (1.3, vector_1[3]);

  EXPECT_EQ (2.3, vector_2[0]);
  EXPECT_EQ (6.7, vector_2[1]);
  EXPECT_EQ (8.9, vector_2[2]);
  EXPECT_EQ (1.6, vector_2[3]);

  vector_1[0] = 5.8;
  EXPECT_EQ (5.8, vector_1[0]);
  EXPECT_EQ (4.2, vector_1[1]);
  EXPECT_EQ (5.1, vector_1[2]);
  EXPECT_EQ (1.3, vector_1[3]);
}

TEST (Vector4Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
  Math::Vec4d vector;
  const Math::Vec4d const_vector;
  double tmp = 3;

  EXPECT_THROW (tmp = vector[4], std::out_of_range);
  EXPECT_THROW (tmp = const_vector[4], std::out_of_range);
}
