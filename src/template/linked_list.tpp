#pragma once
#include <cstddef>
#include <stdexcept>
#include "list_buffer.tpp"

template <typename T>
class LinkedList : public ListBuffer<T>
{
public:
    LinkedList() noexcept = default;
    LinkedList(const T& data);
    LinkedList(const std::size_t& length, const T& data);
    std::size_t length() const noexcept;
    bool isEmpty() const noexcept;
    T get(const std::size_t& position) const;
    void insertTail(const T& data);
    void insertHead(const T& data);
    void insert(const std::size_t& position, const T& data);
    void remove(const std::size_t& position);
};

template <typename T>
LinkedList<T>::LinkedList(const T& data) 
{
    this -> head = new typename ListBuffer<T>::Node(data);
    this -> tail = this -> head;
    this -> length_ = 1;
}

template <typename T>
LinkedList<T>::LinkedList(const std::size_t& length, const T& data)
{
    for (std::size_t i = 0; i < length; ++i)
        this -> insertTail(data);
}

template <typename T>
std::size_t LinkedList<T>::length() const noexcept
{
    return this -> length_;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
    return (this -> head == nullptr);
}

template <typename T>
T LinkedList<T>::get(const std::size_t& position) const
{
    if (position >= this -> length_)
        throw std::out_of_range("There is not element at the specified position.");
    typename ListBuffer<T>::Node* current = this -> head;
    for (std::size_t i = 1; i <= position; ++i)
        current = current -> next;
    return current -> data;
}

template <typename T>
void LinkedList<T>::insertTail(const T& data)
{
    if (this -> head == nullptr)
    {
        this -> head = new typename ListBuffer<T>::Node(data);
        this -> tail = this -> head;
    }
    else
    {
        this -> tail -> next = new typename ListBuffer<T>::Node(data);
        this -> tail = this -> tail -> next;    
    }    
    ++(this -> length_);   
}

template <typename T>
void LinkedList<T>::insertHead(const T& data)
{
    typename ListBuffer<T>::Node* nextOfInserted = this -> head;
    this -> head = new typename ListBuffer<T>::Node(data);
    this -> head -> next = nextOfInserted;
    if (this -> length_ == 0)
        this -> tail = this -> head;
    ++(this -> length_);   
}

template <typename T>
void LinkedList<T>::insert(const std::size_t& position, const T& data)
{
    if (position > this -> length_)
        throw std::out_of_range("Can't insert element at the specified position!");

    if (this -> length_ == 0 || position == 0)
        this -> insertHead(data);

    else if (this -> length_ == position)
        this -> insertTail(data);
    
    else
    {
        typename ListBuffer<T>::Node* previous = this -> head;
        for (std::size_t i = 1; i < position; ++i)
            previous = previous -> next;

        typename ListBuffer<T>::Node* nextOfInserted = previous -> next;
        previous -> next = new typename ListBuffer<T>::Node(data);
        previous -> next -> next = nextOfInserted;   
        ++(this -> length_);
    }
}

template <typename T>
void LinkedList<T>::remove(const std::size_t& position) 
{
    if (position >= this -> length_)
        throw  std::out_of_range("There is no element to remove at the specified position.");

    typename ListBuffer<T>::Node* removedElement = this -> head;
    typename ListBuffer<T>::Node* previous = this -> head;
    for (std::size_t i = 1; i <= position; ++i)
    {
        previous = removedElement;
        removedElement = removedElement -> next;
    }
        
    previous -> next = removedElement -> next;
    if (position == 0)
    {
        this -> head = this -> head -> next;
        if (this -> length_ == 1)
            this -> tail = nullptr;   
    }
    if (position == this -> length_ - 1)
        this -> tail = previous;

     delete removedElement;   
    --(this -> length_);
}