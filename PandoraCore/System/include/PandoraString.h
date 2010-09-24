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

#ifndef PANDORASTRING_H
#define PANDORASTRING_H

#include <string.h>
#include <stddef.h>
#include <assert.h>

namespace Pandora
{
    namespace Utils
    {
        class String
        {
            public:
                /**
                 *  Constructor, makes a string.
                 *  \param
                 *      string - The char array we wish to use as a string.
                 */
                String(const char *string);

                /**
                 *  Constructor. Makes a string.
                 *  \param
                 *      string - The string we wish to copy.
                 */
                String(const String& string);

                /**
                 *  Destructor.
                 */
                ~String();

                /**
                 *  Assignment. Makes a hard copy.
                 *  \param
                 *      string - The char array we wish to assign to.
                 */
                String& operator=(const char *string);

                /**
                 *  Assignment. Makes a hard copy.
                 *  \param
                 *      string - The string we wish to assign to.
                 */
                String& operator=(const String string);

                /**
                 *  Get character number i from the string.
                 *  \param
                 *      i - The index to look in.
                 *  \return
                 *      Character number i in the string.
                 *  \note
                 *      Asserts if out of bounds in debug mode, undefined
                 *      behaviour in release.
                 */
                char& operator[](const ptrdiff_t i);

                /**
                 *  Get constant character number i from the string.
                 *  \param
                 *      i - The index to look in.
                 *  \return
                 *      Character number i in the string.
                 *  \note
                 *      Asserts if out of bounds in debug mode, undefined
                 *      behaviour in release.
                 */
                const char operator[](const ptrdiff_t i) const;

                /**
                 *  Get the string as a c-style string.
                 *  \return
                 *      The c-style string.
                 */
                char* c_str();

                /**
                 *  Get the string as a c-style constant string.
                 *  \return
                 *      The c-style constant string.
                 */
                const char* c_str() const;

                /**
                 *  Get the length of the string.
                 *  \return
                 *      The length of the string.
                 */
                unsigned int length() const;

                /**
                 *  Look for a substring.
                 *  \param
                 *      substring - The substring to look for.
                 *  \return
                 *      The index where the substring starts. -1 if it don't 
                 *      exist.
                 */
                int substr(const char *substring) const;

                /**
                 *  Look for a substring.
                 *  \param
                 *      substring - The substring to look for.
                 *  \return
                 *      The index where the substring starts. -1 if it don't 
                 *      exist.
                 */
                int substr(const String substring) const;
            private:
                char m_string[256];
                unsigned int m_len;
        };
    } // namespace Utils
} // namespace Pandora

#endif // PANDORASTRING_H
