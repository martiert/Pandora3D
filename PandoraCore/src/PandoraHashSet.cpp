/*
--------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-08-30

Last Modified : man 30-08-2010 12:00:31 CEST

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)ås
--------------------------------------------------------------------------------
*/

#include "../include/PandoraHastSet.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class KEY>
HashSet<KEY>::HashSet(const int size)
{
    m_size = size;
    m_set = new HashItem*[size];
    memset(m_set, 0, m_size*sizeof(HashItem*));
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class KEY>
HashSet<KEY>::~HashSet()
{
    removeAll();
    delete[] m_set;
}


/********************************************************************************
 * Insert item into set.                                                        *
 *******************************************************************************/
template<class KEY>
KEY* HashSet<KEY>::insert(const KEY& key)
{
    int idx = key.hash(m_size);
    HashItem* item = m_set[idx];

    while(item) {
        if(key == item->key) {
            // Key already in set
            return &(HashItem->key);
        }
        item = item->next;
    }

    // Set the new key at the front of the list
    item = new HashItem;
    item->key = key;
    item->next = m_set[idx];
    m_set[idx] = item;
    m_quantity++;
}


/********************************************************************************
 * Remove item from the set.                                                    *
 *******************************************************************************/
template<class KEY>
bool hashSet<KEY>::remove(const KEY& key)
{
    int idx = key.hash(m_size);

    if(!m_set[idx])
        return false;

    m_set[idx] = NULL;
    return true;
}


} // namespace Utils
} // namespace Pandora
