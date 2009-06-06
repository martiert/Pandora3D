/*
 * ----------------------------------------------------------------------------
 * This source file is part of Pandora3D. For information, see 
 * http://Pandora3D.sourceforge.net.
 *
 * Copyright (c) 2009 Martin Ertsås
 *
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the license, or any later version.
 *
 * This program is distributed in hope that it will be useful, but WITHOUT ANY 
 * WARRANTY.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston MA 02111-1307, USA, or go to:
 *
 * http://www.gnu.org/licenses/#GPL
 * ----------------------------------------------------------------------------
 */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class T>
    class Stack
    {
        public:
            //Makes a stack with n elements.
            Stack(const int n);
            //Destructor.
            ~Stack();

            //Checks if the stack is empty.
            bool isEmpty() const;

            //Checks if the stack is full.
            bool isFull() const;

            //Pushes an element on the stack.
            void push(const T& element);

            //Pops an element from the stack.
            void pop(T& element);

            //Clears the stack (moves the index to -1)
            void clear();

            //Get the top of the stack, without decrementing the stack. Returns
            //false if the stack is empty.
            bool getTop(T& element) const;
        protected:
            T* m_data;
            int m_index;
            int m_size;
    };
}

#endif
