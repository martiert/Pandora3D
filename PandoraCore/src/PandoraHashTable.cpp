/*
--------------------------------------------------------------------------------
File Name : PandoraHashtable.cpp
 
Purpose : Implementation of the Hashtable class used in Pandora3D
 
Creation Date : 2010-01-24

Last Modified : ma. 30. aug. 2010 kl. 13.57 +0200
 
Created By : Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "../include/PandoraHashTable.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Key, class Value>
HashTable<Key,Value>::HashTable(const unsigned int& size)
{
    m_size = size;
    m_elements = 0;
    m_values = new Node[size];
    memcpy(m_value, 0, m_size*sizeof(Node));
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Key, class Value>
HashTable<Key,Value>::~HashTable()
{
    removeAll();
    delete[] m_values;
}


/********************************************************************************
 * Insert a value into the HashTable.                                           *
 *******************************************************************************/
template<class Key, class Value>
void HashTable<Key,Value>::insert(const Key& key, const Value& value)
{
    int index = key.hash(m_size);
    Node *input = new Node();
    input->key = key;
    input->value = value;
    input->next = m_values[index];
    m_values[index] = input;
}


/********************************************************************************
 * Remove element from the table, and return the value of the element.          *
 *******************************************************************************/
template<class Key, class Value>
Value& HashTable<Key,Value>::remove(const Key& key)
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    if(node && node->key == key) {
        m_values[index] = node->next;
        Value val = node->value;
        delete node;
        m_elements--;
        return val;
    }

    Node *next = node->next;
    while(next) {
        if(next->key == key) {
            node->next = next->next;
            Value val = next->value;
            delete next;
            m_element--;
            return val;
        }
        node = next;
        next = node->next;
    }

    return NULL;
}


/********************************************************************************
 * Remove all elements from the table.                                          *
 *******************************************************************************/
template<class Key, class Value>
void HashTable<Key,Value>::removeAll()
{
    if(m_elements > 0) {
        for(int i = 0; i < m_size; ++i) {
            Node *node = m_values[i];
            while(node) {
                Node *next = node->next;
                delete node;
                node = next;
            }
        }

        m_elements = 0;
    }
}


/********************************************************************************
 * Checks if the key is present in the table.                                   *
 *******************************************************************************/
template<class Key, class Value>
bool HashTable<Key,Value>::exists(const Key& key) const
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    while(node) {
        if(node->key == key) {
            return true;
        }
        node = node->next;
    }

    return false;
}


/********************************************************************************
 * Checks if the key is present in the table and, if it is, returns the         *
 * element.                                                                     *
 *******************************************************************************/
template<class Key,class Value>
Value& HashTable<Key,Value>::find(const Key& key) const
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    while(node) {
        if(node->key == key) {
            return node->value;
        }
        node = node->next;
    }

    return NULL;
}


/********************************************************************************
 * Get a key iterator.                                                          *
 *******************************************************************************/
template<class Key, class Value>
Iterator<Key> HashTable<Key,Value>::getKeys() const
{
    Iterator<Key> keyIt();

    for(int i = 0; i < m_size; i++) {
        Node *node = m_values[i];
        while(node) {
            keyIt->append(node->key);
            node = node->next;
        }
    }

    return keyIt;
}


/********************************************************************************
 * Get a value iterator.                                                        *
 *******************************************************************************/
template<class Key, class Value>
Iterator<Value> HashTable<Key,Value>::getValues() const
{
    Iterator<Value> valueIt();

    for(int i = 0; i < m_size; i++) {
        Node *node = m_value[i];
        while(node) {
            valueIt->append(node->value);
            node = node->next;
        }
    }

    return valueIt;
} // namespace Utils
} // namespace Pandora
