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
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <math.h>

namespace Pandora
{
    namespace Utils
    {
        namespace
        {
            //One node in the table.
            template<class Key, class Value>
            struct Node
            {
                Key key;
                Value *value;
            };
        } //Anon namespace

        /** 
         *  A HashTable class.
         *  \note
         *      This class has a standard <VAR>hashFunction</VAR> function, but
         *      it can, and should, be overwritten with the userHashFunction 
         *      function.
         *  \todo 
         *      Make an iterator
         *  \todo
         *      Make the hashFunction function.
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
                bool insert(const Key& key, const Value& value);

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
                 *  A user defined hash function.
                 *  \param
                 *      key - The key to hash.
                 *  \return
                 *      The key as an integer between 0 and m_size.
                 *  \note
                 *      The user is responsible for making a good hashfunction
                 *      without collisions, since collisions will be ignored.
                 */
                int (*userHashFunction)(const Key& key);
            private:
                unsigned int m_size;
                unsigned int m_elements;
                Node<Key, Value> *m_values;

                int hashFunction(const Key& key) const;
        };

#include "PandoraHashtable.inl"

    }
}
#endif
