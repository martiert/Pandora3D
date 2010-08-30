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

#ifndef PANDORAHASHSET_H
#define PANDORAHASHSET_H

namespace Pandora
{
    namespace Utils
    {
        /**
         *  A class for storing keys in a set. The KEY class needs a function
         *  hash(int) which hashes the class. There is no default hash function
         *  implemented, as the class itselv is expected to hash.
         */
        template<class KEY>
        class HashSet
        {
            public:
                /**
                 *  Constructor.
                 *  \param
                 *      size - The size of the set. Defaults to 101.
                 */
                HashSet(const unsigned int size);

                /**
                 *  Destructor.
                 */
                ~HashSet();

                /**
                 *  Insert a key into the set.
                 *  \param
                 *      key - The key to store.
                 *  \return 
                 *      The address of the key.
                 */
                KEY* insert(const KEY& key);

                /**
                 *  Remove a key from the set.
                 *  \param  
                 *      key - The key we are looking for.
                 *  \return 
                 *      True if the key is found and removed, false otherwise.
                 */
                bool remove(const KEY& key);

                /**
                 *  Remove every entry in the set.
                 */
                void removeAll();

                /**
                 *  Get the number of elements in the set.
                 *  \return
                 *      The number of elements.
                 */
                int getQuantity() const;

                /**
                 *  Search for a key in the set.
                 *  \param
                 *      key - The key we are searching for.
                 *  \return
                 *      The address of the key. null if it's not found.
                 */
                KEY* get(const KEY& key) const;

                /**
                 *  Get the first entry of the set.
                 *  \return
                 *      The first entry of the set.
                 */
                KEY* getFirst() const;

                /**
                 *  Get the next entry of the set.
                 *  \return 
                 *      The next entry of the set.
                 *  \note
                 *      getFirst() must have been called for this to work.
                 */
                KEY* getNext() const;
            private:
                class HashItem
                {
                    public:
                        KEY key;
                        HashItem *next;
                };
                    
                unsigned int m_size;
                unsigned int m_quantity;
                HashItem** m_set;

                //Used for iterating.
                unsigned int m_idx;
                HashItem* m_present;
        };
    } // namespace Utils
} // namespace Pandora
#endif // PANDORAHASHSET_H
