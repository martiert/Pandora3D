/*
--------------------------------------------------------------------------------
File Name : PandoraStack.cpp

Purpose : Implementation of the Stack class used in Pandora3D

Creation Date : 2010-01-24

Last Modified : to. 02. sep. 2010 kl. 16.24 +0200

Created By : Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include <PandoraStack.h>

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class T>
Stack<T>::Stack(unsigned int size)
{
    m_size = size;
    m_stackAt = -1;
    m_stack = new T[size];
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class T>
Stack<T>::~Stack()
{
    delete[] m_stack;
}


/********************************************************************************
 * Check if the stack is empty.                                                 *
 *******************************************************************************/
template<class T>
bool Stack<T>::isEmpty() const
{
    return m_stackAt == -1;
}


/********************************************************************************
 * Check if the stack is full.                                                  *
 *******************************************************************************/
template<class T>
bool Stack<T>::isFull() const
{
    return m_stackAt == (m_size - 1);
}


/********************************************************************************
 * Push an item on the stack.                                                   *
 *******************************************************************************/
template<class T>
void Stack<T>::push(const T& item)
{
    assert(m_stackAt < (m_size - 1) && "Stack is full");
    m_stack[++m_stackAt] = item;
}


/********************************************************************************
 * Pop the first item.                                                          *
 *******************************************************************************/
template<class T>
bool Stack<T>::pop(T& item) 
{
    if(m_stackAt == -1) {
        return false;
    }

    item = m_stack[m_stackAt--];
    return true;
}


/********************************************************************************
 * Clear the Stack.                                                             *
 *******************************************************************************/
template<class T>
void Stack<T>::clear()
{
    m_stackAt = -1;
}


/********************************************************************************
 * Get the top of the stack without popping.                                    *
 *******************************************************************************/
template<class T>
bool Stack<T>::getTop(T& item)
{
    if(m_stackAt == -1) {
        return false;
    }
    item = m_stack[m_stackAt];
    return true;
}
} // namespace Utils
} // namespace Pandora
