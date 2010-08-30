/*
--------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <math.h>
#include "PandoraIterator.h"

namespace Pandora
{
    namespace Utils
    {
        namespace
        {

        /** 
         *  A HashTable class.
         *  \note
         *      The key needs a hash(int) function used for hashing. There is
         *      no default hash function.
         */
        template<class Key, class Value>
        class HashTable
        {
            public:
                /** 
                 *  Default constructor.
                 *  \param
                 *      size - The size of the hashTable. It is not possible to
                 *          change this at a later time.
                 */
                HashTable(const unsigned int& size);

                /** 
                 *  Destructor 
                 */
                ~HashTable();

                /** 
                 *  Insert an element into the HashTable.
                 *  \param
                 *      key - The key to be associated with this element.
                 *  \param
                 *      value - The value of the element.
                 *  \return
                 *      False if the table is full, or we get a collision.
                 *      True else.
                 */
                void insert(const Key& key, const Value& value);

                /**
                 *  Remove an element from the HashTable.
                 *  \param
                 *      key - The key we are searching for.
                 *  \return
                 *      The value if we found the element. NULL else.
                 */
                Value& remove(const Key& key);

                /** 
                 *  Removes everything in the HashTable.
                 */
                void removeAll();

                /** 
                 *  Checks if a key exists in the HashTable.
                 *  \param
                 *      key - The key to search for.
                 *  \return
                 *      True if the key exists. False otherwise.
                 */
                bool exists(const Key& key) const;

                /** 
                 *  Finds an element in the HashTable and returns it.
                 *  \param
                 *      key - The key to search for.
                 *  \return
                 *      The element itself if the key is found. NULL otherwise.
                 */
                Value& find(const Key& key) const;

                /**
                 *  Get a Key iterator.
                 *  \return
                 *      A key iterator.
                 */
                Iterator<Key> getKeys() const;

                /**
                 *  Get a Value iterator.
                 *  \return
                 *      A value iterator.
                 */
                Iterator<Value> getValues() const;
            protected:
                class Node {
                    Key key;
                    Value value;
                    Node *next;
                }

                unsigned int m_size;
                unsigned int m_elements;
                Node *m_values;
        };
    }
}
#endif
