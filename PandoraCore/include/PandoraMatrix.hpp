/*
 * ----------------------------------------------------------------------------
 * This source file is part of Pandora3D. For information, see 
 * http://Pandora3D.sourceforge.net.
 *
 * Copyright (c) 2009 Martin Ertsås
 *
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the license, or any later version.
 *
 * This program is distributed in hope that it will be useful, but WITHOUT ANY 
 * WARRANTY.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston MA 02111-1307, USA, or go to:
 *
 * http://www.gnu.org/licenses/#GPL
 * ----------------------------------------------------------------------------
 */

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#ifdef DEBUG
    #include <iostream>
#endif

#include "PandoraSystem.hpp"
#include "PandoraVector4.hpp"
#include "PandoraVector3.hpp"

namespace Pandora
{
    //|(0,0) (0,1) (0,2) (0,3)|
    //|(1,0) (1,1) (1,2) (1,3)|
    //|(2,0) (2,1) (2,2) (2,3)|
    //|(3,0) (3,1) (3,2) (3,3)|
    class Matrix
    {
        protected:
            float m_data[4][4];
        public:
            //Default constructor, makes an Identity matrix
            Matrix()
            {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(i == j)
                            m_data[i][j] = 1.0f;
                        else
                            m_data[i][j] = 0.0f;
                    }
                }
            }

            //A Copy constructor
            Matrix(Matrix& mat)
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        m_data[i][j] = mat[i][j];
            }

            //Destructor, does nothing
            ~Matrix() { }

            //Copy operator
            inline void operator=(Matrix& mat)
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        m_data[i][j] = mat[i][j];
            }

            //Get row number i from the matrix
            inline float* operator[](const unsinged int i)
            {
                assert(i < 4);
                return m_data[i];
            }

            //Negates the matrix
            inline Matrix operator-()
            {
                Matrix tmp;
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        tmp[i][j] = -m_data[i][j];

                return tmp;
            }

            //Adds a matrix to this matrix
            inline void operator+=(Matrix& mat)
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        m_data[i][j] += mat[i][j];
            }

            //Subtracts a matrix from this matrix
            inline void operator-=(Matrix& mat)
            {
                *this += -mat;
            }

            //Multiplies this matrix with a scalar
            inline void operator*=(const float& scalar)
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        m_data[i][j] *= scalar;
            }

            //Adds a matrix with this matrix and returns the new matrix
            inline Matrix operator+(Matrix& mat)
            {
                Matrix tmp(*this);
                tmp += mat;
                return tmp;
            }

            //Subtracts a matrix with this matrix and returns the new matrix
            inline Matrix operator-(Matrix& mat)
            {
                Matrix tmp(*this);
                tmp -= mat;
                return tmp;
            }

            //Multiplies this matrix with a scalar and returns the new matrix
            inline Matrix operator*(const float& scalar)
            {
                Matrix tmp(*this);
                tmp *= scalar;
                return tmp;
            }

            //Multiplies this matrix with a 4D vector and returns the new vector
            inline Vector4 operator*(Vector4& vec)
            {
                Vector4 tmp;
                tmp[0] = m_data[0][0] * vec.x + m_data[0][1] * vec.y + 
                    m_data[0][2] * vec.z + m_data[0][3] * vec.w;
                tmp[1] = m_data[1][0] * vec.x + m_data[1][1] * vec.y +
                    m_data[1][2] * vec.z + m_data[1][3] * vec.w;
                tmp[2] = m_data[2][0] * vec.x + m_data[2][1] * vec.y +
                    m_data[2][2] * vec.z + m_data[2][3] * vec.w;
                tmp[3] = m_data[3][0] * vec.x + m_data[3][1] * vec.y +
                    m_data[3][2] * vec.z + m_data[3][3] * vec.w;

                return tmp;
            }

            //Multiplies this matrix with a 3D vector (Multiplying a 4D vector
            //with last component = 0) and returns the new vector
            inline Vector3 operator*(Vector3& vec)
            {
                Vector4 tmp(vec);
                tmp = (*this) * tmp;
                return Vector3(tmp.x, tmp.y, tmp.z);
            }

            //Multiplies this vector with another vector and returns the result
            inline Matrix operator*(Matrix& mat)
            {
                Matrix tmp;
                tmp[0][0] = tmp[1][1] = tmp[2][2] = tmp[3][3] = 0.0f;

                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        for(int k = 0; k < 4; k++)
                            tmp[i][j] += m_data[i][k] * m_data[k][j];

                return tmp;
            }

            //Returns the determinant of the matrix, not exactly pretty, but it
            //works
            inline float determinant()
            {
                float tmp = 
                    m_data[0][0]*(
                        m_data[1][1]*(
                            m_data[2][2]*m_data[3][3]-m_data[2][3]*m_data[3][2])
                        - m_data[1][2]*(
                            m_data[2][1]*m_data[3][3]-m_data[2][3]*m_data[3][1])
                        + m_data[1][3]*(
                            m_data[2][1]*m_data[3][2]-m_data[2][2]*m_data[3][1]))
                    - m_data[0][1]*(
                        m_data[1][0]*(
                            m_data[2][2]*m_data[3][3]-m_data[2][3]*m_data[3][2])
                        - m_data[1][2]*(
                            m_data[2][0]*m_data[3][3]-m_data[2][3]*m_data[3][0])
                        + m_data[1][3]*(
                            m_data[2][0]*m_data[3][2]-m_data[2][2]*m_data[3][0]))
                    + m_data[0][2]*(
                        m_data[1][0]*(
                            m_data[2][1]*m_data[3][3]-m_data[2][3]*m_data[3][1])
                        - m_data[1][1]*(
                            m_data[2][0]*m_data[3][3]-m_data[2][3]*m_data[3][0])
                        + m_data[1][3]*(
                            m_data[2][0]*m_data[3][1]-m_data[2][1]*m_data[3][0]))
                    - m_data[0][3]*(
                        m_data[1][0]*(
                            m_data[2][1]*m_data[3][2]-m_data[2][2]*m_data[3][1])
                        - m_data[1][1]*(
                            m_data[2][0]*m_data[3][2]-m_data[2][2]*m_data[3][0])
                        + m_data[1][2]*(
                            m_data[2][0]*m_data[3][1]-m_data[2][1]*m_data[3][0]));

                return tmp;
            }

            //Returns the inverse of the matrix
            inline Matrix inverse()
            {
                Matrix tmp(*this);
                Matrix inv;

                for(int i = 0; i < 4; i++) {
                    //If tmp[i][i] is zero, we have to switch this with the
                    //first row where column i is non-zero
                    if(tmp[i][i] == 0) {
                        int j = i + 1;
                        while(tmp[j][i] == 0 && j < 4)
                            j++;
                        assert(j != 4);
                        //Now we know we have to switch row i and j
                        for(int k = 0; k < 4; k++) {
                            //switching tmp
                            tmpvar = tmp[i][k];
                            tmp[i][k] = tmp[j][k];
                            tmp[j][k] = tmp[i][k];
                            //switching inverse
                            tmpvar = inv[i][k];
                            inv[i][k] = inv[j][k];
                            inv[j][k] = tmpvar;
                        }
                    }

                    //Now scale the row so tmp[i][i] == 1
                    float scale = 1.0 / tmp[i][i];
                    for(int j = 0; j < 4; j++) {
                        tmp[i][j] *= scale;
                        inv[i][j] *= scale;
                    }

                    //Then we have to make everything under i in the i-th column
                    //zero
                    for(int j = i+1; j < 4; j++) {
                        float scale = tmp[j][i];
                        for(int k = 0; k < 4; k++) {
                            tmp[j][k] -= tmp[i][k];
                            inv[j][k] -= inv[i][k];
                        }
                    }
                }
                //Now we have an upper, triangular matrix:
                //|  1   (0,1) (0,2) (0,3)|
                //|  0     1   (1,2) (1,3)|
                //|  0     0     1   (2,3)|
                //|  0     0     0     1  |
    
                for(int i = 3; i >= 0; i--) {
                    for(int j = i - 1; j >= 0; j--) {
                        float scale = tmp[j][i];
                        for(int k = 0; k < 4; k++) {
                            tmp[j][k] -= tmp[i][k];
                            inv[j][k] -= tmp[i][k];
                        }
                    }
                }
                return inv;
            }

#ifdef DEBUG
            //Prints out the Matrix. For testing purposes only
            inline friend std::ostream& operator<<(std::ostream& os, Matrix& m)
            {
                for(int i = 0; i < 4; i++) {
                    os << "|"
                    for(int j = 0; j < 4; j++) {
                        os << m_data[i][j];
                        if(j < 3)
                            os << " ";
                    }
                    os << "|\n";
                }
                return os;
            }
#endif
    };
}
#endif
