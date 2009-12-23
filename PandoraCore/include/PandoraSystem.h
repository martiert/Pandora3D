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
#ifndef PANDORASYSTEM_H
#define PANDORASYSTEM_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** The main namespace of the engine.
 */
namespace Pandora
{
    class System
    {
        /**
         * Load a binary file into memory.
         * \param
         *      filename - The name of the file to read.
         *      buffer - The buffer to write to.
         *      size - the number of bytes in the file.
         * \return
         *      False if the file don't exist, the file can't be opened for
         *      reading or if the size of the file is different from the size
         *      parameter.
         */
        static bool load(const char *filename, char*& buffer, size_t size);

        /**
         * Save data to a file.
         * \param
         *      filename - The file to write to.
         *      buffer - The buffer to read from.
         *      size - The size of the buffer.
         *  \return
         *      False if the buffer is NULL, the file can not be opened or the
         *      number of bytes written differs from the size parameter.
         */
        static bool save(const char *filename, const char *buffer, size_t size);

        /**
         * Append data to a file.
         * \param
         *      filename - The file to append to.
         *      buffer - The buffer to read from.
         *      size - The size of the buffer.
         *  \return
         *      False if the buffer is NULL, the file can not be opened or the
         *      number of bytes written differs from the size parameter.
         */
        static bool append(const char *filename, const char *buffer, 
                size_t size);

        /**
         * Allocates a 2D array. This uses only two allocation, regardless of
         * the size.
         * \param
         *      cols - The number of columns to allocate.
         *      rows - The number of rows to allocate.
         *      array - The array to allocate to.
         *  \note
         *      Does not set the elements to anything because of speed.
         */
        template<class T> static void allocate2D(size_t cols, size_t rows,
                T**& array);

        /**
         * Frees up the memory of a 2D array. Have to have used allocate2D to
         * free with this function. Uses only two deallocation calls.
         * \param
         *      array - The array to deallocate.
         * \note
         *      The behaviour is undefined if you use an array that is not 
         *      allocate with allocate2D.
         */
        template<class T> static void deallocate2D(T**& array);

        /**
         * Allocates a 3D array. This uses only three allocations, regardless
         * of the size.
         * \param
         *      cols - The number of columns to allocate.
         *      rows - The number of rows to allocate.
         *      slices - The number of slices to allocate.
         *      array - The array to allocate.
         *  \note
         *      Does not set the elements to anything because of speed.
         */
        template<class T> static void allocate3D(size_t cols, size_t rows,
                size_t slices, T***& array);

        /**
         * Frees up memory allocated by allocate3D. Uses only three 
         * deallocation calls.
         * \param
         *      array - The array to deallocate.
         * \note
         *      The behaviour is undefined if you use an array that is not
         *      allocated with allocate3D.
         */
        template<class T> static void deallocate3D(T***& array);
    };

    //-------------------------------------------------------------------------
    // Load a file from memory.
    //-------------------------------------------------------------------------
    static bool System::load(const char *filename, char*& buffer, size_t size)
    {
        return true;
    }

    //-------------------------------------------------------------------------
    // Save to disk.
    //-------------------------------------------------------------------------
    static bool system::save(const char *filename, const char *buffer, 
            size_t size)
    {
        return true;
    }

    //-------------------------------------------------------------------------
    // Append to file.
    //-------------------------------------------------------------------------
    static bool System::append(const char *filename, const char *buffer, 
            size_t size)
    {
        return true;
    }

    //-------------------------------------------------------------------------
    // Allocate a 2D array.
    //-------------------------------------------------------------------------
    template<class T>
    static void System::allocate2D(size_t cols, size_t rows, T**& array)
    {
        int elements = rows * cols;
        array = new T*[rows];
        array[0] = new T[elements];

        for(int i = 0; i < rows; ++i)
            array[i] = array[0][i*cols];
    }

    //-------------------------------------------------------------------------
    // Deallocate a 2D array.
    //-------------------------------------------------------------------------
    template<class T>
    static void System::deallocate2D(T**& array)
    {
        delete[] array[0];
        delete[] array;
        array = NULL;
    }

    //-------------------------------------------------------------------------
    // Allocate a 3D array.
    //-------------------------------------------------------------------------
    template<class T>
    static void System::allocate3D(size_t cols, size_t rows, size_t slices,
            T***& array)
    {
        array = new T**[slices];
        array[0] = new T*[rows*slices];
        array[0][0] = new T[rows*slices*cols];

        for(int i = 0; i < slices; ++i) {
            for(int j = 0; j < rows; ++j) {
                array[i][j] = array[0][0][i*j*rows];
            }
        }
    }

    //-------------------------------------------------------------------------
    // Deallocates a 3D array.
    //-------------------------------------------------------------------------
    template<class T>
    static void System::deallocate3D(T***& array)
    {
        delete[] array[0][0];
        delete[] array[0];
        delete[] array;
        array = NULL;
    }
}
#endif
