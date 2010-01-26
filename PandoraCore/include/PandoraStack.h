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
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <assert.h>

namespace Pandora
{
    namespace Utils
    {
        /** 
         *  A simple Stack.
         *  \note
         *      The stack is not resizable.
         */
        template<class T>
        class Stack
        {
            public:
                /** 
                 *  Default constructor.
                 *  \param
                 *      size - The number of elements in the stack. This number
                 *      is final.
                 */
                Stack(unsigned int size);

                /** 
                 *  Destructor. 
                 */
                ~Stack();

                /** 
                 *  Checks if the stack is empty.
                 *  \return
                 *      True if the stack is empty, false otherwise.
                 */
                bool isEmpty() const;

                /** 
                 *  Checks if the stack is full.
                 *  \return
                 *      True if the stack is full, false otherwise.
                 */
                bool isFull() const;

                /** 
                 *  Pushes an item on to the stack.
                 *  \param
                 *      item - The element to push on the stack.
                 *  \note
                 *      Kills the program if the stack is full.
                 */
                void push(const T& item);

                /** 
                 *  Pops the first item from the stack.
                 *  \param
                 *      item - The place to store the item.
                 *  \return
                 *      false if the stack is empty. True otherwise.
                 */
                bool pop(T& item);

                /** 
                 *  Clears the stack. 
                 */
                void clear();

                /** 
                 *  Get the top item in the stack without popping.
                 *  \param
                 *      item - The place to store the item.
                 *  \return
                 *      false if the stack is empty. True otherwise.
                 */
                bool getTop(T& item);
            private:
                T* m_stack;
                int m_size, m_stackAt;
        };

#include "PandoraStack.inl"

    }
}
#endif
