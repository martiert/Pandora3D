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

#include "PandoraMath.hpp"

namespace Pandora
{
    template<class Real>
    class Vector2
    {
        public:
            Vector2(Real tx = 1, Real ty = 0);

            //Comparsion operators
            bool operator==(const Vector2<Real>& vec);
            bool operator!=(const Vector2<Real>& vec);

            //Aritmethic operators
            Vector2<Real> operator+(const Vector2<Real>& vec);
            Vector2<Real> operator-(const Vector2<Real>& vec);
            Vector2<Real> operator+=(const Vector2<Real>& vec);
            Vector2<Real> operator-=(const Vector2<Real>& vec);
            Real operator*(const Vector2<Real>& vec);
        public:
            Real x, y;
    };

    template<class Real>
    Vector2<Real>::Vector2(Real tx, Real ty)
    {
        x = tx;
        y = ty;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator==(const Vector2<Real>& vec)
    {
        return x == vec.x && y == vec.y;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator!=(const Vector2<Real>& vec)
    {
        return !operator==(vec);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator+(const Vector2<Real>& vec)
    {
        return Vector2<Real>(x+vec.x,y+vec.y);
    }
}
