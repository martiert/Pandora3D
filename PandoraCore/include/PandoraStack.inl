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

//---------------------------------------------------------------------
// Constructor.
//---------------------------------------------------------------------
template<class T>
Stack<T>::Stack(size_t size)
{
    m_size = size;
    m_stackAt = -1;
    m_stack = new T[size];
}

//---------------------------------------------------------------------
// Destructor.
//---------------------------------------------------------------------
template<class T>
Stack<T>::~Stack()
{
    delete[] m_stack;
}

//---------------------------------------------------------------------
// Check if the stack is empty.
//---------------------------------------------------------------------
template<class T>
bool Stack<T>::isEmpty() const
{
    return m_stackAt == -1;
}

//---------------------------------------------------------------------
// Check if the stack is full.
//---------------------------------------------------------------------
template<class T>
bool Stack<T>::isFull() const
{
    return m_stackAt == (m_size - 1);
}

//---------------------------------------------------------------------
// Push an item on the stack.
//---------------------------------------------------------------------
template<class T>
void Stack<T>::push(const T& item)
{
    assert(m_stackAt < (m_size - 1) && "Stack is full");
    m_stack[++m_stackAt] = item;
}

//---------------------------------------------------------------------
// Pop the first item.
//---------------------------------------------------------------------
template<class T>
T& Stack<T>::pop() 
{
    if(m_stackAt == -1)
        return NULL;

    return m_stack[m_stackAt--];
}

//---------------------------------------------------------------------
// Clear the Stack.
//---------------------------------------------------------------------
template<class T>
void Stack<T>::clear()
{
    m_stackAt = -1;
}

//---------------------------------------------------------------------
// Get the top of the stack without popping.
//---------------------------------------------------------------------
template<class T>
T& Stack<T>::getTop() const
{
    if(m_stackAt == -1)
        return NULL;
    return m_stack[m_stackAt];
}
