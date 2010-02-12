/*
-------------------------------------------------------------------------------
This source file is part of Pandora3D.

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation. Either version 2 of the License, or (at your option) any later 
version.

This program comes without any warranty whatsoever, but under the hope that it
will be useful. See the GNU General Public License for more information.

You should have received a copy of the GNU Lesser General Public License along 
with this program; if not, write to the Free Software Foundation, Inc., 59 
Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-------------------------------------------------------------------------------
*/

#include "PandoraMath.h"
#include <stddef.h>

namespace Pandora
{
    namespace Math
    {
        /**
         *  A 2x2 Matrix class. Keeps the data in rowvise order. Like:
         *
         *  |0 1|
         *  |2 3|
         */
        template<class Real>
        class Matrix2
        {
            public:
                /**
                 *  Constructor. Takes four elements.
                 *  \param
                 *      a - Element in row one, column one.
                 *  \param
                 *      b - Element in row one, column two.
                 *  \param
                 *      c - Element in row two, column one.
                 *  \param
                 *      d - Element in row two, column two.
                 *  \note
                 *      If no elements are sent to the constructor, the 
                 *      identity matrix is constructed.
                 */
                Matrix2(const Real& a = (Real) 1.0, const Real& b = (Real) 0.0, 
                        const Real& c = (Real) 0.0, const Real& d = (Real) 1.0);

                /**
                 *  Constructor. Copies an array to this vector.
                 *  \param
                 *      array - The array we take values from.
                 */
                Matrix2(Real array[4]);

                /**
                 *  Copy a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to copy from
                 */
                Matrix2(Matrix2& mat);

                /**
                 *  Implicit conversion.
                 *  \return
                 *      The matrix as an array.
                 */
                operator Real *();

                /**
                 *  Implicit conversion.
                 *  \return
                 *      The matrix as a constant array.
                 */
                operator const Real *() const;

                /**
                 *  Get index number i.
                 *  \param
                 *      i - The index we are looking into.
                 *  \return
                 *      The element in index i.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get value in index number i.
                 *  \param
                 *      i - The index we are looking into.
                 *  \return
                 *      Value of the element in index i.
                 */
                const Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get element from (row,col).
                 *  \param
                 *      row - The row we are searching for.
                 *  \param
                 *      col - The column we are searching for.
                 *  \return
                 *      The element in (row,col)
                 */
                Real& operator()(const int row, const int col);

                /**
                 *  Get value in element (row,col).
                 *  \param
                 *      row - The row we are searching for.
                 *  \param
                 *      col - The column we are searching for.
                 *  \return
                 *      The value in element (row,col).
                 */
                const Real operator()(const int row, const int col) const;
            protected:
                Real m_data[4];
        };
    }
}
