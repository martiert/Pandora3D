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
#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

namespace Pandora
{
    namespace Utils
    {
        /** A simple String class. */
        class String
        {
            public:
                /** Default Constructor.
                 *  \param
                 *      text - The characters to form a string.
                 */
                String(const char *text);
                
                /** Constructor.
                 *  \param
                 *      length - The length of the text.
                 *      text - The text to form a string.
                 */
                String(size_t length, const char *text);

                /** Copy constructor.
                 *  \param
                 *      text - The string to copy.
                 */
                String(const String& text);

                /** Destructor */
                ~String();

                /** Get the length of the string.
                 *  \return
                 *      The length of the string.
                 */
                int getLength();

                /** Get a pointer to the string.
                 *  \return
                 *      A pointer to the char array.
                 */
                operator const char* () const;

                /** Assignment operator.
                 *  \param
                 *      text - The string to copy.
                 */
                void operator=(const char* text);

                /** Assignment operator.
                 *  \param
                 *      text - The string to copy.
                 */
                void operator=(const String& text);

                /** Equality operator.
                 *  \param
                 *      text - The string to check for equality on.
                 *  \return
                 *      True if the strings are equal, false otherwise.
                 */
                bool operator==(const String& text) const;

                /** Inequality operator.
                 *  \param
                 *      text - The string were checking if is equal.
                 *  \return
                 *      True if the string are not equal, false otherwise.
                 */
                bool operator!=(const String& text) const;

                /** Integer conversion.
                 *  \return
                 *      The string as an unsigned int.
                 */
                operator unsigned int () const;
            private:
                int m_length;
                char *m_string;
        };
    }
}
#endif
