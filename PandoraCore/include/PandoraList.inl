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

//-----------------------------------------------------------------------------
// This file contains the implementation of the List class from Pandora3D. See
// PandoraList.h for detailed explanation.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Makes the List itself
//-----------------------------------------------------------------------------
template<class T>
List<T>::List(const T& data)
{
    if(data == NULL) {
        m_size = 0;
        return;
    }

    m_root = malloc(sizeof(Node<T>));
    m_root->data = data;
    m_size = 1;
}

//-----------------------------------------------------------------------------
// Delete the List
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Insert an element at the start of the List. O(1)
//-----------------------------------------------------------------------------
template<class T>
void List<T>::insert(const T& data)
{
    Node<T> *tmp = malloc(sizeof(Node<T>));
    tmp->data = data;
    tmp->next = m_root;
    m_root = tmp;
}

//-----------------------------------------------------------------------------
// Remove an element from the List. O(n)
//-----------------------------------------------------------------------------
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
}

//-----------------------------------------------------------------------------
// See if an element exists in the List. O(n)
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Remove all elements from the List.
//-----------------------------------------------------------------------------
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