#ifdef VECTOR_INCLUDE_FILE

template<typename T>
Vector<T>::Vector (const size_t& initial_capacity, const size_t& increment_by)
    : elements_in_vector (0),
      vector_capacity (initial_capacity),
      vector_increment (increment_by),
      elements (new T[initial_capacity])
{}

template<typename T>
Vector<T>::~Vector ()
{
    delete[] elements;
}

template<typename T>
void Vector<T>::append (const T& element)
{
    if (elements_in_vector == vector_capacity)
        resize ();

    elements[elements_in_vector] = element;
    ++elements_in_vector;
}

template<typename T>
T& Vector<T>::element_at (const size_t& i) const
{
    if (i >= elements_in_vector)
        throw std::out_of_range ("index is out of the vector range");

    return elements[i];
}

template<typename T>
T Vector<T>::remove_at (const size_t& i)
{
    if (i >= elements_in_vector)
        throw std::out_of_range ("index is out of the vector range");

    T element = elements[i];
    rearrange (i);
    --elements_in_vector;

    return element;
}

template<typename T>
size_t Vector<T>::size () const
{
    return elements_in_vector;
}

template<typename T>
size_t Vector<T>::capacity () const
{
    return vector_capacity;
}

template<typename T>
void Vector<T>::resize ()
{
    if (vector_increment == 0)
        throw std::overflow_error ("This vector can not be resised");

    T* new_elements = new T[vector_capacity + vector_increment];
    std::copy (elements, &(elements[elements_in_vector]), new_elements);

    delete[] elements;
    elements = new_elements;
    vector_capacity += vector_increment;
}

template<typename T>
void Vector<T>::rearrange (size_t from)
{
    for (; from < elements_in_vector - 1; ++from)
        elements[from] = elements[from+1];
}

#else // VECTOR_INCLUDE_FILE
#error "Only include this file from vector.h"
#endif // VECTOR_INCLUDE_FILE
