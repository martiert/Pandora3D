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

#ifndef PANDORAITERATOR_H
#define PANDORAITERATOR_H

#include "PandoraHashTable.h"

namespace Pandora
{
    namespace Utils
    {
        /**
         *  An iterator class.
         */
        template<class Type>
        class Iterator
        {
            public:
                /**
                 *  Constructor.
                 */
                Iterator();

                /**
                 *  Destructor.
                 */
                ~Iterator();

                /**
                 *  Check if the iterator has a next.
                 *  \return
                 *      True if the iterator has more elements.
                 */
                bool hasNext() const;

                /**
                 *  Get the next element in the iterator.
                 *  \return
                 *      The next element in the iterator.
                 */
                Type& getNext() const;

            protected:
                class Node
                {
                    public:
                        Type elem;
                        Node *next;
                }

                Node *m_node;

                 /**
                 *  Append to the iterator.
                 *  \param
                 *      elem - The element to append.
                 */
                void append(const Type& elem);

                friend class HashTable;
        };
    } // namespace Utils
} // namespace Pandora

#endif // PANDORAITERATOR_H
