#ifdef STACK_INCLUDE_FILE

template<typename T>
System::Stack<T>::Stack (const size_t& size)
    : elements_on_stack (0), max_elements_on_stack (size)
{
    elements = new T[size];
}

template<typename T>
System::Stack<T>::~Stack ()
{
    delete[] elements;
}

template<typename T>
void System::Stack<T>::push (const T& element)
{
    if (elements_on_stack == max_elements_on_stack)
        throw std::overflow_error ("Can not push on a full stack");

    elements[elements_on_stack] = element;
    ++elements_on_stack;
}

template<typename T>
T& System::Stack<T>::pop ()
{
    if (elements_on_stack == 0)
        throw std::underflow_error ("Can not pop empty stack");

    --elements_on_stack;
    return elements[elements_on_stack];
}

template<typename T>
T& System::Stack<T>::peak () const
{
    if (elements_on_stack == 0)
        throw std::logic_error ("Can not peak on empty stack");

    return elements[elements_on_stack - 1];
}

template<typename T>
size_t System::Stack<T>::size () const
{
    return elements_on_stack;
}

template<typename T>
size_t System::Stack<T>::max_size () const
{
    return max_elements_on_stack;
}

#else // STACK_INCLUDE_FILE
#error "Never include this file anywhere but stack.h"
#endif // STACK_INCLUDE_FILE
