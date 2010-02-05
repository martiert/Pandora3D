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

#include <sys/time.h>
#include <time.h>

/** 
 *  The main namespace of the engine.
 */
namespace Pandora
{
    /**
     *  The System class. Holds all the functions which wrapps platform
     *  dependent functions.
     */
    class System
    {
        public:
        /**
         *  Get the current time in seconds.
         *  \return
         *      The current time in seconds.
         */
        static double getTime()
        {
            double time;

            struct timeval tv;
            gettimeofday(&tv, NULL);
            time = tv.tv_sec + tv.tv_usec/1000000.0;
            return time;
        }

        /**
         *  Load a binary file into memory.
         *  \param
         *      filename - The name of the file to read.
         *  \param
         *      buffer - The buffer to write to.
         *  \param
         *      size - the number of bytes in the file.
         *  \return
         *      False if the file don't exist, the file can't be opened for
         *      reading or if the size of the file is different from the size
         *      parameter.
         *  \todo write the function.
         */
        static bool load(const char *filename, char*& buffer, int size);

        /**
         *  Save data to a file.
         *  \param
         *      filename - The file to write to.
         *  \param
         *      buffer - The buffer to read from.
         *  \param
         *      size - The size of the buffer.
         *  \return
         *      False if the buffer is NULL, the file can not be opened or the
         *      number of bytes written differs from the size parameter.
         *  \todo write the function.
         */
        static bool save(const char *filename, const char *buffer, int size);

        /**
         *  Append data to a file.
         *  \param
         *      filename - The file to append to.
         *  \param
         *      buffer - The buffer to read from.
         *  \param
         *      size - The size of the buffer.
         *  \return
         *      False if the buffer is NULL, the file can not be opened or the
         *      number of bytes written differs from the size parameter.
         *  \todo write the function.
         */
        static bool append(const char *filename, const char *buffer, 
                int size);

        /**
         *  Allocates a 2D array. This uses only two allocation, regardless of
         *  the size.
         *  \param
         *      cols - The number of columns to allocate.
         *  \param
         *      rows - The number of rows to allocate.
         *  \param
         *      array - The array to allocate to.
         *  \note
         *      Does not set the elements to anything because of speed.
         */
        template<class T> static void allocate2D(int cols, int rows,
                T**& array)
        {
            array = new T*[rows];
            array[0] = new T[rows*cols];

            for(int i = 0; i < rows; ++i)
                array[i] = array[0][i*cols];
        }

        /**
         *  Frees up the memory of a 2D array. Have to have used allocate2D to
         *  free with this function. Uses only two deallocation calls.
         *  \param
         *      array - The array to deallocate.
         *  \note
         *      The behaviour is undefined if you use an array that is not 
         *      allocate with allocate2D.
         */
        template<class T> static void deallocate2D(T**& array)
        {
            delete[] array[0];
            delete[] array;
            array = NULL;
        }

        /**
         *  Allocates a 3D array. This uses only three allocations, regardless
         *  of the size.
         *  \param
         *      cols - The number of columns to allocate.
         *  \param
         *      rows - The number of rows to allocate.
         *  \param
         *      slices - The number of slices to allocate.
         *  \param
         *      array - The array to allocate.
         *  \note
         *      Does not set the elements to anything because of speed.
         */
        template<class T> static void allocate3D(int cols, int rows,
                int slices, T***& array)
        {
            array = new T**[slices];
            array[0] = new T*[slices*rows];
            array[0][0] = new T*[cols*slices*rows];

            for(int i = 0; i < slices; ++i) {
                array[i] = array[0][i*rows];
                for(int j = 0; j < rows; ++j) {
                    array[i][j] = array[0][i][j*cols];
                }
            }
        }

        /**
         *  Frees up memory allocated by allocate3D. Uses only three 
         *  deallocation calls.
         *  \param
         *      array - The array to deallocate.
         *  \note
         *      The behaviour is undefined if you use an array that is not
         *      allocated with allocate3D.
         */
        template<class T> static void deallocate3D(T***& array)
        {
            delete[] array[0][0];
            delete[] array[0];
            delete[] array;
            array = NULL;
        }
    };
}
#endif
