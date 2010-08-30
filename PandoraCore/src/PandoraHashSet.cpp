/*
--------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-08-30

Last Modified : ma. 30. aug. 2010 kl. 14.25 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)ås
--------------------------------------------------------------------------------
*/

#include "../include/PandoraHashSet.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class KEY>
HashSet<KEY>::HashSet(const unsigned int size)
{
    m_size = size;
    m_set = new HashItem*[size];
    m_quantity = 0;
    m_idx = 0;
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
            return &(item->key);
        }
        item = item->next;
    }

    // Set the new key at the front of the list
    item = new HashItem;
    item->key = key;
    item->next = m_set[idx];
    m_set[idx] = item;
    m_quantity++;
    return &(m_set[idx]->key);
}


/********************************************************************************
 * Remove item from the set.                                                    *
 *******************************************************************************/
template<class KEY>
bool HashSet<KEY>::remove(const KEY& key)
{
    int idx = key.hash(m_size);
    HashItem* item = m_set[idx];

    if(item->key == key) {
        m_set[idx] = item->next;
        delete item;
        m_quantity--;
        return true;
    }

    HashItem* next = item->next;
    while(next) {
        if(next->key == key) {
            item->next = next->next;
            delete next;
            m_quantity--;
            return true;
        }
        item = next;
        next = item->next;
    }

    return false;
}


/********************************************************************************
 * Remove all.                                                                  *
 *******************************************************************************/
template<class KEY>
void HashSet<KEY>::removeAll()
{
    for(int i = 0; i < m_size; i++) {
        HashItem* item = m_set[i];

        while(item) {
            HashItem* next = item->next;
            delete item;
            item = next;
        }
    }

    m_quantity = 0;
}


/********************************************************************************
 * Get the number of elements in the set.                                       *
 *******************************************************************************/
template<class KEY>
int HashSet<KEY>::getQuantity() const
{
    return m_quantity;
}


/********************************************************************************
 * Get a key in the set.                                                        *
 *******************************************************************************/
template<class KEY>
KEY* HashSet<KEY>::get(const KEY& key) const
{
    int idx = key.hash(m_size);
    HashItem* item = m_set[idx];

    while(item) {
        if(item->key == key) {
            return &(item->key);
        }
        item = item->next;
    }

    return 0;
}


/********************************************************************************
 * Get the first item in the set.                                               *
 *******************************************************************************/
template<class KEY>
KEY* HashSet<KEY>::getFirst() const
{
    for(m_idx = 0; m_idx < m_size; m_idx++) {
        if(m_set[m_idx]) {
            m_present = m_set[m_idx];
            return &(m_present->key);
        }
    }
}


/********************************************************************************
 * Get the next item in the set.                                                *
 *******************************************************************************/
template<class KEY>
KEY* HashSet<KEY>::getNext() const
{
    // Have you called getFirst() ?
    if(!m_present)
        return 0;

    if(m_present->next) {
        m_present = m_present->next;
        return &(m_present->key);
    }

    m_idx++;
    for(;m_idx < m_size; m_idx++) {
        if(m_set[m_idx]) {
            m_present = m_set[m_idx];
            return &(m_present->key);
        }
    }

    // No more keys.
    return 0;
}

} // namespace Utils
} // namespace Pandora
