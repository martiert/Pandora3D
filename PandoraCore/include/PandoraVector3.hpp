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
    class Vector3
    {
       public:
            //Constructors and destructors
            Vector3(Real mx = 1, Real my = 0, Real mz = 0);
            Vector3(const Vector3<Real>& vec);
            ~Vector3();

            //Equality operators
            bool operator==(const Vector3<Real>& vec) const;
            bool operator!=(const Vector3<Real>& vec) const;

            //Data assignment
            Real& operator[](const int i);
            Real operator[](int i) const;
            operator const Real* () const;
            operator Real* ();
        public:
            Real x, y, z;
    };

//#############################################################################
//
//                              Default constructor.
//
//#############################################################################

    template<class Real>
    Vector3<Real>::Vector3(Real mx, Real my, Real mz)
    {
        x = mx;
        y = my;
        z = mz;
    }

//#############################################################################
//
//                              Copy constructor.
//
//#############################################################################

    template<class Real>
    Vector3<Real>::Vector3(const Vector3<Real>& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
    }

//#############################################################################
//
//                          Destructor. Does nothing.
//
//#############################################################################

    template<class Real> 
    Vector3<Real>::~Vector3() 
    { }

//#############################################################################
//
//                              Checks equality.
//
//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator==(const Vector3<Real>& vec) const
    {
        return x == vec.x && y == vec.y && z == vec.z;
    }

//#############################################################################
//
//                              Checks inequality.
//
//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator!=(const Vector3<Real>& vec) const
    {
        return !operator==(vec);
    }

//#############################################################################
//#############################################################################

    template<class Real>
    Real& Vector3<Real>::operator[](const int i)
    {
        assert(i < 3);
        return *(&x + i);
    }

//#############################################################################
//#############################################################################

    template<class Real>
    Real Vector3<Real>::operator[](const int i) const
    {
        assert(i < 3);
        return *(&x + i);
    }

//#############################################################################
//#############################################################################

    template<class Real>
    operator const Real* () const
    {
        return &x;
    }
}
