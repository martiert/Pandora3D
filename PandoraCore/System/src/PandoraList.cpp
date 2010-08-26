/*
---------------------------------------------------------------------------------
File Name : PandoraList.cpp

Purpose : Implementation of the List class used in Pandora3D

Creation Date : 2010-01-25

Last Modified : to. 26. aug. 2010 kl. 22.02 +0200

Created By : Martin Ertsaas (martiert@student.matnat.uio.no)
---------------------------------------------------------------------------------
*/

#include "../include/PandoraList.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Makes the List itself.                                                       *
 *******************************************************************************/
template<class T>
List<T>::List()
{
    m_size = 0;
    m_root = NULL;
}


template<class T>
List<T>::List(const T& data)
{
    if(!data) {
        m_size = 0;
        m_root = NULL;
        return;
    }

    m_root = (Node<T>*) malloc(sizeof(Node<T>));
    m_root->data = data;
    m_root->next = NULL;
    m_size = 1;
}


/********************************************************************************
 * Delete the List.                                                             *
 *******************************************************************************/
template<class T>
List<T>::~List()
{
    //Get all the nodes and free them from memory.
    while(m_root) {
        Node<T> *tmp = m_root;
        m_root = m_root->next;
        free(tmp);
    }
}


/********************************************************************************
 * Insert an element at the start of the List. O(1)                             *
 *******************************************************************************/
template<class T>
void List<T>::insert(const T& data)
{
    Node<T> *tmp = (Node<T>*) malloc(sizeof(Node<T>));
    tmp->data = data;
    tmp->next = m_root;
    m_root = tmp;
    m_size++;
}


/********************************************************************************
 * Remove an element from the List. O(n)                                        *
 *******************************************************************************/
template<class T>
bool List<T>::remove(const T& data)
{
    //If the root don't exist. Return false.
    if(!m_root)
        return false;

    //If the root node is what we're looking for.
    if(m_root->data == data) {
        Node<T> *tmp = m_root;
        m_root = tmp->next;
        free(tmp);
        --m_size;
        if(m_size == 0)
            m_root = NULL;
        return true;
    }

    Node<T> *now = m_root->next;
    Node<T> *last = m_root;

    //While we have not found the data, and we're not at the end of the
    //list, go to next element.
    while(now && now->data != data) {
        last = now;
        now = now->next;
    }

    //We're at the end of the list, so no such element in the list.
    if(!now)
        return false;

    last->next = now->next;
    free(now);
    --m_size;
    if(m_size == 0)
        m_root = NULL;

    return true;
}


/********************************************************************************
 * See if an element exists in the List. O(n)                                   *
 *******************************************************************************/
template<class T>
bool List<T>::exists(const T& data)
{
    Node<T> *tmp = m_root;

    while(tmp && tmp->data != data)
        tmp = tmp->next;

    //Found it, hurray!
    if(tmp)
        return true;

    return false;
}


/********************************************************************************
 * Remove all elements from the List.                                           *
 *******************************************************************************/
template<class T>
void List<T>::removeAll()
{
    Node<T> *tmp;

    while(m_root) {
        tmp = m_root;
        m_root = m_root->next;
        free(tmp);
    }

    m_size = 0;
}


/********************************************************************************
 * Get the length of the list.                                                  *
 *******************************************************************************/
template<class T>
unsigned int List<T>::length()
{
    return m_size;
}
} // namespace Utils
} // namespace Pandora
