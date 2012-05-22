#ifdef VECTOR_INCLUDE_FILE

template<typename T>
Vector<T>::Vector (const size_t& initial_capacity)
    : elements_in_vector (0), vector_capacity (initial_capacity), elements (new T[initial_capacity])
{}

template<typename T>
void Vector<T>::append (const T& element)
{
    elements[elements_in_vector] = element;
    ++elements_in_vector;
}

template<typename T>
T& Vector<T>::element_at (const size_t& i) const
{
    return elements[i];
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

#else // VECTOR_INCLUDE_FILE
#error "Only include this file from vector.h"
#endif // VECTOR_INCLUDE_FILE
