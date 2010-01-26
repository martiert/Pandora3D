/*
-------------------------------------------------------------------------------
File Name : PandoraSet.inl

Purpose : Implementation of the Set class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : ti. 26. jan. 2010 kl. 11.25 +0100

Created By : Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
template<class T>
Set<T>::Set(const unsigned int size, const unsigned int increment)
{
    m_data = new T[size];
    m_size = size;
    m_increment = increment;
    m_elements = 0;
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
template<class T>
Set<T>::~Set()
{
    delete[] m_data;
}

//-----------------------------------------------------------------------------
// Appends an element to the first free place in the set. If no free spots,
// we have to resize the array.
//-----------------------------------------------------------------------------
template<class T>
bool Set<T>::insert(const T& in)
{
    //If we have room for the element, no rearranging have to be done.
    if(m_elements < m_size) {
        m_data[m_elements++] = in;
        return true;
    } else {
        //Checks if we are allowed to resize the set.
        if(m_increment == 0)
            return false;

        //Resize the array
        T *tmp = new T[m_size + m_increment];

        //Copy the data to the new array
        for(int i = 0; i < m_size; ++i)
            tmp[i] = m_data[i];

        //Delete the old array, copy the new large array to the data 
        //pointer and set the new size to the old size + the 
        //incrementation.
        delete[] m_data;
        m_data = tmp;
        m_size += m_increment;

        //Set the data in the set
        m_data[m_elements++] = in;
        return true;
    }
}

//-----------------------------------------------------------------------------
// Search for an element in the set.
//-----------------------------------------------------------------------------
template<class T>
bool Set<T>::exists(const T& search) const
{
    if(m_elements == 0) {
        return false;
    }

    for(int i = 0; i < m_elements; ++i) {
        if(m_data[i] == search) {
            return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
// Get the number of elements in the set.
//-----------------------------------------------------------------------------
template<class T>
unsigned int Set<T>::getElements() const
{
    return m_elements;
}

//-----------------------------------------------------------------------------
// Get the number of places in the set
//-----------------------------------------------------------------------------
template<class T>
unsigned int Set<T>::getSize() const
{
    return m_size;
}

//-----------------------------------------------------------------------------
// Get the number of elements to increment the set by.
//-----------------------------------------------------------------------------
template<class T>
unsigned int Set<T>::getIncrement() const
{
    return m_increment;
}

//-----------------------------------------------------------------------------
// Get the array itself
//-----------------------------------------------------------------------------
template<class T>
T* Set<T>::getPointer()
{
    return m_data;
}

//-----------------------------------------------------------------------------
// Remove an element from the set. Returns true if the element is removed,
// returns false otherwise
//-----------------------------------------------------------------------------
template<class T>
bool Set<T>::remove(const T& elem)
{
    unsigned int i = 0;

    //Search for the element.
    while(i < m_elements && m_data[i] != elem) {
        ++i;
    }

    //The element doesn't exist.
    if(i == m_elements)
        return false;

    //Shuffle all the remaining data
    for(;i < m_size - 1; ++i)
        m_data[i] = m_data[i + 1];
    m_data[i] = NULL;
    m_elements--;

    return true;
}

//-----------------------------------------------------------------------------
// Removes all the data from the set
//-----------------------------------------------------------------------------
template<class T>
void Set<T>::removeAll()
{
    m_elements = 0;
    delete[] m_data;
    m_data = new T[m_size];
}
