/*
--------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------
*/

#ifndef PANDORAQUADTREE_H
#define PANDORAQUADTREE_H

namespace Pandora {
    namespace Utils {
        template<class T>
        class QuadTree {
            public:
                /**
                 *  Default constructor. Sets the root node to NULL if nothing
                 *  else is defined.
                 *  \param  
                 *      root - The root node.
                 */
                QuadTree(T *root = NULL);

                /**
                 *  Destructor.
                 */
                ~QuadTree();

                /**
                 *  Insert an element in the tree.
                 *  \param
                 *      elem - The element to insert.
                 */
                void insert(T *elem);

                /**
                 *  Get the element in the current node.
                 */
            protected:
                class Node {
                    Node *node1;
                    Node *node2;
                    Node *node3;
                    Node *node4;
                    T *element;
                };

                Node *m_root;
        };
    } // namespace Utils
} // namespace Pandora

#endif // PANDORAQUADTREE_H
