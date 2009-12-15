#ifndef PANDORALIST_H
#define PANDORALIST_H

#include <stdlib.h>

namespace PandoraUtils
{
    namespace {
        template<class T>
        struct Node
        {
            Node *next;
            T data;
        };
    } //Anon namespace

    template<class T>
    class List
    {
        public:
            //The list constructor. If you send in data, we make a root node,
            //else we do nothing and set the size to 0.
            List(const T& data = NULL);
            ~List();

            void insert(const T& data);
            bool remove(const T& data);

            bool exists(const T& data);

            void removeAll();
        protected:
            Node<T> *m_root;
            size_t m_size;
    };

    //-------------------------------------------------------------------------
    // Makes the List itselv
    //-------------------------------------------------------------------------
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

    //-------------------------------------------------------------------------
    // Delete the List
    //-------------------------------------------------------------------------
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

    //-------------------------------------------------------------------------
    // Insert an element at the start of the List. O(1)
    //-------------------------------------------------------------------------
    template<class T>
    void List<T>::insert(const T& data)
    {
        Node<T> *tmp = malloc(sizeof(Node<T>));
        tmp->data = data;
        tmp->next = m_root;
        m_root = tmp;
    }

    //-------------------------------------------------------------------------
    // Remove an element from the List. O(n)
    //-------------------------------------------------------------------------
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

    //-------------------------------------------------------------------------
    // See if an element exsits in the List. O(n)
    //-------------------------------------------------------------------------
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

    //-------------------------------------------------------------------------
    // Remove all elements from the List.
    //-------------------------------------------------------------------------
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
}
#endif
