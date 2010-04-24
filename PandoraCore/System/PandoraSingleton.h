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
#ifndef PANDORA_SINGLETON_H
#define PANDORA_SINGLETON_H

namespace Pandora
{
    namespace Utils
    {
        template<class T>
        class Singleton
        {
            public:
                static T& instance()
                {
                    if(!m_instance) {
                        m_instance = new T();
                    }
                    return *m_instance;
                }
            private:
                Singleton();
                Singleton(const Singleton& a);
                Singleton& operator=(const Singleton& a);
                ~Singleton();

                static T *m_instance;
        };

        template<class T>
        T* Singleton<T>::m_instance=0;
    }
}
#endif
