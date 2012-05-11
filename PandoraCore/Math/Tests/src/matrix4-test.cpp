#include <Math/matrix4.h>
#include <gtest/gtest.h>

TEST (Matrix4Test, can_populate_4d_matrix)
{
    const Math::Matrix4d matrix (3.2, 1.2, 6.7, 5.2,
                                 8.7, 5.4, 2.3, 3.3,
                                 8.9, 7.6, 4.3, 3.3,
                                 1.4, 5.4, 3.4, 8.8);
}

TEST (Matrix4Test, default_constructor_creates_identity_matrix)
{
    const Math::Matrix4d matrix;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j)
                EXPECT_EQ (1, matrix (i,j));
            else
              EXPECT_EQ (0, matrix (i,j));
        }
    }
}
