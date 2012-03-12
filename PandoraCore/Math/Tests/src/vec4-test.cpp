#include <Math/vector4.h>
#include <Math/vector3.h>

#include <gtest/gtest.h>

TEST (Vector4Test, construction)
{
    const Math::Vec4d vector_1;
    EXPECT_EQ (0.0, vector_1.x);
    EXPECT_EQ (0.0, vector_1.y);
    EXPECT_EQ (0.0, vector_1.z);
    EXPECT_EQ (0.0, vector_1.w);

    const Math::Vec4d vector_2 (0.1, 7.8, 4.3, 2.3);
    EXPECT_EQ (0.1, vector_2.x);
    EXPECT_EQ (7.8, vector_2.y);
    EXPECT_EQ (4.3, vector_2.z);
    EXPECT_EQ (2.3, vector_2.w);

    double tmp[] = {3.4, 3.2, 2.1, 5.4};
    const Math::Vec4d vector_3 (tmp);
    EXPECT_EQ (tmp[0], vector_3.x);
    EXPECT_EQ (tmp[1], vector_3.y);
    EXPECT_EQ (tmp[2], vector_3.z);
    EXPECT_EQ (tmp[3], vector_3.w);

    const Math::Vec4d vector_4 (vector_1);
    EXPECT_EQ (vector_1.x, vector_4.x);
    EXPECT_EQ (vector_1.y, vector_4.y);
    EXPECT_EQ (vector_1.z, vector_4.z);
    EXPECT_EQ (vector_1.w, vector_4.w);

    const Math::Vec4d vector_5 = vector_2;
    EXPECT_EQ (vector_2.x, vector_5.x);
    EXPECT_EQ (vector_2.y, vector_5.y);
    EXPECT_EQ (vector_2.z, vector_5.z);
    EXPECT_EQ (vector_2.w, vector_5.w);

    const Math::Vec4d vector_6 = tmp;
    EXPECT_EQ (tmp[0], vector_6.x);
    EXPECT_EQ (tmp[1], vector_6.y);
    EXPECT_EQ (tmp[2], vector_6.z);
    EXPECT_EQ (tmp[3], vector_6.w);

    const Math::Vec3d tmp_vector (4.5, 3.2, 1.9);
    const Math::Vec4d vector_7 (tmp_vector);
    EXPECT_EQ (tmp_vector.x, vector_7.x);
    EXPECT_EQ (tmp_vector.y, vector_7.y);
    EXPECT_EQ (tmp_vector.z, vector_7.z);
    EXPECT_EQ (1.0, vector_7.w);

    const Math::Vec4d vector_8 = tmp_vector;
    EXPECT_EQ (tmp_vector.x, vector_8.x);
    EXPECT_EQ (tmp_vector.y, vector_8.y);
    EXPECT_EQ (tmp_vector.z, vector_8.z);
    EXPECT_EQ (1.0, vector_8.w);
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

TEST (Vector4Test, length)
{
    const Math::Vec4d vector_1 (2.3, 4.5, 7.6, 9.4);
    const Math::Vec4d vector_2;

    EXPECT_EQ (vector_1.x * vector_1.x +
            vector_1.y * vector_1.y +
            vector_1.z * vector_1.z +
            vector_1.w * vector_1.w, vector_1.lengthSquared ());
    EXPECT_EQ (0.0, vector_2.lengthSquared ());

    EXPECT_EQ (std::sqrt (vector_1.x * vector_1.x +
                vector_1.y * vector_1.y +
                vector_1.z * vector_1.z +
                vector_1.w * vector_1.w), vector_1.length ());
    EXPECT_EQ (0.0, vector_2.length ());
}

TEST (Vector4Test, normalize)
{
    Math::Vec4d vector_1 (3.2, 4.2, 6.7, 4.3);

    EXPECT_NE (1.0, vector_1.length ());
    auto vector_3 = vector_1.normalize ();
    EXPECT_EQ (1.0, vector_1.length ());
    EXPECT_EQ (1.0, vector_3.length ());

    Math::Vec4d vector_2;
    EXPECT_THROW (vector_2.normalize (), std::domain_error);
}

TEST (Vector4Test, negation)
{
    const Math::Vec4d vec_1 (3.2, 4.3, 1.2, 6.7);
    auto vec_2 = -vec_1;

    EXPECT_EQ (-vec_1.x, vec_2.x);
    EXPECT_EQ (-vec_1.y, vec_2.y);
    EXPECT_EQ (-vec_1.z, vec_2.z);
    EXPECT_EQ (-vec_1.w, vec_2.w);
}

TEST (Vector4Test, addition)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);

    auto vec_3 = vec_1 + vec_2;
    EXPECT_EQ (vec_1.x + vec_2.x, vec_3.x);
    EXPECT_EQ (vec_1.y + vec_2.y, vec_3.y);
    EXPECT_EQ (vec_1.z + vec_2.z, vec_3.z);
    EXPECT_EQ (vec_1.w + vec_2.w, vec_3.w);

    vec_3 = vec_1 - vec_2;
    EXPECT_EQ (vec_1.x - vec_2.x, vec_3.x);
    EXPECT_EQ (vec_1.y - vec_2.y, vec_3.y);
    EXPECT_EQ (vec_1.z - vec_2.z, vec_3.z);
    EXPECT_EQ (vec_1.w - vec_2.w, vec_3.w);

    vec_3 = vec_1;
    vec_3 += vec_2;
    EXPECT_EQ (vec_1.x + vec_2.x, vec_3.x);
    EXPECT_EQ (vec_1.y + vec_2.y, vec_3.y);
    EXPECT_EQ (vec_1.z + vec_2.z, vec_3.z);
    EXPECT_EQ (vec_1.w + vec_2.w, vec_3.w);

    vec_3 = vec_1;
    vec_3 -= vec_2;
    EXPECT_EQ (vec_1.x - vec_2.x, vec_3.x);
    EXPECT_EQ (vec_1.y - vec_2.y, vec_3.y);
    EXPECT_EQ (vec_1.z - vec_2.z, vec_3.z);
    EXPECT_EQ (vec_1.w - vec_2.w, vec_3.w);
}

TEST (Vector4Test, multiplication)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);

    auto res = vec_1 * 2.4;
    EXPECT_EQ (vec_1.x * 2.4, res.x);
    EXPECT_EQ (vec_1.y * 2.4, res.y);
    EXPECT_EQ (vec_1.z * 2.4, res.z);
    EXPECT_EQ (vec_1.w * 2.4, res.w);

    res = 2.4 * vec_1;
    EXPECT_EQ (vec_1.x * 2.4, res.x);
    EXPECT_EQ (vec_1.y * 2.4, res.y);
    EXPECT_EQ (vec_1.z * 2.4, res.z);
    EXPECT_EQ (vec_1.w * 2.4, res.w);

    res = vec_1 / 2.4;
    EXPECT_EQ (vec_1.x / 2.4, res.x);
    EXPECT_EQ (vec_1.y / 2.4, res.y);
    EXPECT_EQ (vec_1.z / 2.4, res.z);
    EXPECT_EQ (vec_1.w / 2.4, res.w);

    res *= 2.4;
    EXPECT_EQ (vec_1.x, res.x);
    EXPECT_EQ (vec_1.y, res.y);
    EXPECT_EQ (vec_1.z, res.z);
    EXPECT_EQ (vec_1.w, res.w);

    res /= 2.4;
    EXPECT_EQ (vec_1.x / 2.4, res.x);
    EXPECT_EQ (vec_1.y / 2.4, res.y);
    EXPECT_EQ (vec_1.z / 2.4, res.z);
    EXPECT_EQ (vec_1.w / 2.4, res.w);

    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);
    res = vec_1 * vec_2;
    EXPECT_EQ (vec_1.x * vec_2.x, res.x);
    EXPECT_EQ (vec_1.y * vec_2.y, res.y);
    EXPECT_EQ (vec_1.z * vec_2.z, res.z);
    EXPECT_EQ (vec_1.w * vec_2.w, res.w);

    EXPECT_THROW (vec_1 / 0.0, std::invalid_argument);
    EXPECT_THROW (res /= 0.0, std::invalid_argument);

    res = vec_1;
    res *= vec_2;
    EXPECT_EQ (vec_1.x * vec_2.x, res.x);
    EXPECT_EQ (vec_1.y * vec_2.y, res.y);
    EXPECT_EQ (vec_1.z * vec_2.z, res.z);
    EXPECT_EQ (vec_1.w * vec_2.w, res.w);

    auto scalar = vec_1.dot (vec_2);
    EXPECT_EQ (vec_1.x * vec_2.x +
               vec_1.y * vec_2.y +
               vec_1.z * vec_2.z +
               vec_1.w * vec_2.w, scalar);
}

TEST (Vector4Test, comparison_operator)
{
    const Math::Vec4d vec1 (3.4, 5.6, 7.1, 2.3);
    const Math::Vec4d vec2 (2.3, 4.1, 6.7, 2.1);
    const Math::Vec4d vec3 (3.4, 5.6, 7.1, 2.3);

    EXPECT_EQ (vec1, vec3);
    EXPECT_FALSE (vec1 == vec2);

    EXPECT_NE (vec1, vec2);
    EXPECT_FALSE (vec1 != vec3);
}

TEST (Vector4Test, vector_can_be_casted)
{
    Math::Vec4d vector;
    auto pointer = (double *) vector;

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
    EXPECT_EQ (pointer[2], vector.z);
    EXPECT_EQ (pointer[3], vector.w);

    auto pointer2 = static_cast<double*> (vector);
    EXPECT_EQ (pointer2[0], vector.x);
    EXPECT_EQ (pointer2[1], vector.y);
    EXPECT_EQ (pointer2[2], vector.z);
    EXPECT_EQ (pointer2[3], vector.w);

    auto tmp = pointer2[0];
    ++pointer2[0];
    EXPECT_EQ (pointer2[0], tmp + 1);
    EXPECT_EQ (pointer2[0], pointer[0]);
    EXPECT_EQ (vector.x, pointer2[0]);

    const Math::Vec4d vector2;
    auto pointer3 = (const double*) vector2;
    auto pointer4 = static_cast<const double*> (vector2);

    EXPECT_EQ (vector2.x, pointer3[0]);
    EXPECT_EQ (vector2.y, pointer3[1]);
    EXPECT_EQ (vector2.z, pointer3[2]);
    EXPECT_EQ (vector2.w, pointer3[3]);

    EXPECT_EQ (vector2.x, pointer4[0]);
    EXPECT_EQ (vector2.y, pointer4[1]);
    EXPECT_EQ (vector2.z, pointer4[2]);
    EXPECT_EQ (vector2.w, pointer4[3]);
}
