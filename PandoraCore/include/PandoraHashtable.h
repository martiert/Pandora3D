#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "PandoraSystem.h"

namespace Pandora
{
    template<class Key, class Value>
    class HashTable
    {
        public:
            //Constructor.
            HashTable(const size_t& size);
            ~HashTable();

            void insert(Key key, Value value);
            Value& remove(Key key);

            bool exists(Key key);

            int (*userHashFunction)(const Key&);
        protected:
            class Node
            {
                public:
                    Key key;
                    Value value;
                    Node *next;

                    Node(Key k, Value val)
                    {
                        key = k;
                        value = val;
                    }

                    ~Node()
                    {
                        if(next)
                            delete next;
                    }
            };

            size_t m_size;
            Node **m_values;
            
            int m_hashFunction(const Key&);
    };

    //-------------------------------------------------------------------------
    //
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    HashTable<Key, Value>::HashTable(const size_t& size)
    {
        m_size = size;
        m_values = new Node[size];
        userHashFunction = NULL;
    }

    //-------------------------------------------------------------------------
    //
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    HashTable<Key, Value>::~HashTable()
    {
        //Go through the whole array
        for(int i = 0; i < m_size; ++i) {
            if(m_values[i])
                delete m_values[i];
        }

        delete[] m_values;
    }

    //-------------------------------------------------------------------------
    //
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    void HashTable<Key, Value>::insert(Key key, Value value)
    {
        int i = m_hashFunction(key);

        if(m_values[i]) {
            Node tmp = m_values[i];

            while(tmp->next) {
                tmp = tmp->next;
            }

            tmp->next = new Node(key, value);
            return;
        }

        m_values[i] = new Node(key, value);
    }

    //-------------------------------------------------------------------------
    //
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    Value& HashTable<Key, Value>::remove(Key key)
    {
        int i = m_hashFunction(key);

        Node tmp = m_values[i];

        if(tmp->key == key) {
            m_values[i] = tmp->next;
            Value val = tmp->value;
            tmp->next = NULL;
            delete tmp;
            return val;
        }

        if(tmp) {
            Node next = tmp->next;

            while(next) {
                if(next->key == key) {
                    tmp->next = next->next;
                    next->next = NULL;
                    Value val = next->value;
                    delete next;
                    return val;
                }

                tmp = next;
                next = tmp->next;
            }
        }

        return 0;
    }


    //-------------------------------------------------------------------------
    //
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    bool HashTable<Key, Value>::exists(Key key)
    {
        int i = m_hashFunction(key);

        Node tmp = m_values[i];

        while(tmp) {
            if(tmp->key == key)
                return true;
            tmp = tmp->next;
        }

        return false;
    }
}
#endif
