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

#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

#include <cassert>

namespace Pandora
{
    template<class T>
    class Singleton
    {
        protected:
            static T* m_singleton;
        public:
            Singleton()
            {
                assert(!m_singleton);
                m_singleton = static_cast<T*>(this);
            }

            ~Singleton()
            {
                assert(m_singleton);
                m_singleton = NULL;
            }

            static T* getSingletonPtr()
            {
                return m_singleton;
            }

            static T& getSingleton()
            {
                assert(m_singleton);
                return (*m_singleton);
            }
    };
}
#endif
