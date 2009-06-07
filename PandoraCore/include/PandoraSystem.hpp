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

//This file includes the most used headers from the std, and defines a few
//types
#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <string>
#include <fstream>

#include "PandoraHashSet.hpp"
#include "PandoraHashTable.hpp"
#include "PandoraSet.hpp"
#include "PandoraVector.hpp"
#include "PandoraStack.hpp"

namespace Pandora
{
    //A wrapper class for functions that I have to make platform independent.
    class System
    {
        public:
            //For getting the time of day.
            static double getTime();

            //For file I/O.
            static bool load(const char* filename, char*& buffer, int& size);
            static bool save(const char* filename, const char* buffer, 
                    int size);
            static bool append(const char* filename, char* buffer, int size);

            static void swapBytes(int size, void* value);
            static void swpaBytes(int size, int quantity, void* value);
            static void endianCopy(int size, const void* from, void* to);
            static void endianCopy(int size, int quantity, const void* from, 
                    void* to);
    };
}
#endif
