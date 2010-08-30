/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-08-30

Last Modified : ma. 30. aug. 2010 kl. 14.15 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "../include/PandoraIterator.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Type>
Iterator<Type>::Iterator()
{
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Type>
Iterator<Type>::~Iterator()
{
    while(m_node) {
        Node *next = node->next;
        delete m_node;
        m_node = next;
    }
}


/********************************************************************************
 * Check if we have a next element.                                             *
 *******************************************************************************/
template<class Type>
bool Iterator<Type>::hasNext() const
{
    if(m_node)
        return true;
    return false;
}


/********************************************************************************
 * Get the next element.                                                        *
 *******************************************************************************/
template<class Type>
Type& Iterator<Type>::getNext()
{
    Type elem = m_node->elem;
    m_node = m_node->next;
    return elem;
}


/********************************************************************************
 * Append to the iterator.                                                      *
 *******************************************************************************/
template<class Type>
void Iterator<Type>::append(const Type& elem)
{
    Node *node = new Node();
    node->elem = elem;
    node->next = m_node;
    m_node = node;
}

} // namespace Utils
} // namespace Pandora
