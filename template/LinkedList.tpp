#pragma once
#include "Node.tpp"
#include <cstddef> //for std::size_t
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    std::size_t length_;

public:
    LinkedList() noexcept;
    LinkedList(const T &data) noexcept;
    LinkedList(const LinkedList<T> &original) noexcept;
    ~LinkedList();
    void insertTail(const T &data) noexcept;
    void insertHead(const T &data) noexcept;
    void insert(const std::size_t &position, const T &data);
    void remove(const std::size_t &position);
    bool isEmpty() const noexcept;
    T get(const std::size_t &position) const;
    std::size_t length() const noexcept;
    void printList() const noexcept;
};

template <typename T>
LinkedList<T>::LinkedList() noexcept: head(nullptr), tail(nullptr), length_(0) {}

template <typename T>
LinkedList<T>::LinkedList(const T &data) noexcept
{
    this -> head = new Node<T>(data);
    this -> tail = head;
    this -> length_ = 1;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &original) noexcept :head(nullptr), tail(nullptr), length_(0)
{
    Node<T> *current = original.head;
    for (std::size_t i = 0; i < original.length_; ++i)
    {
        this -> insertTail(current -> data);
        current = current -> next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = this -> head;
    for (std::size_t i = 0; i < this -> length_; ++i)
    {
        this -> head = this -> head -> next;
        delete current;
        current = this -> head;
    }
    this -> head = nullptr;
    this -> tail = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
    return (this -> head == nullptr);
}

template <typename T>
T LinkedList<T>::get(const std::size_t &position) const
{
    if (position >= this -> length_)
        throw std::out_of_range("There is not element at the specified position.");
    Node<T> *current = head;
    for (std::size_t i = 1; i <= position; ++i)
        current = current -> next;
    return current -> data;
}

template <typename T>
void LinkedList<T>::insertTail(const T &data) noexcept
{

    if (this -> head == nullptr)
    {
        this -> head = new Node<T>(data);
        this -> tail = head;
    }
    else
    {
        this -> tail -> next = new Node<T>(data);
        this -> tail = this -> tail -> next;    
    }    
    ++(this -> length_);   
}

template <typename T>
void LinkedList<T>::insertHead(const T &data) noexcept
{
    Node<T> *nextOfInserted = head;
    this -> head = new Node<T>(data);
    this -> head -> next = nextOfInserted;
    if (this -> length_ == 0)
        this -> tail = this -> head;
    ++(this -> length_);   
}

template <typename T>
void LinkedList<T>::insert(const std::size_t &position, const T &data)
{
    if (position > this -> length_)
        throw std::out_of_range("Can't insert element at the specified position!");

    if (this -> length_ == 0 || position == 0)
        this -> insertHead(data);

    else if (length_ == position)
        this -> insertTail(data);
    
    else
    {
        Node<T> *previous = head;
        for (std::size_t i = 1; i < position; ++i)
            previous = previous -> next;

        Node<T> *nextOfInserted = previous -> next;
        previous -> next = new Node<T>(data);
        previous -> next -> next = nextOfInserted;   
        ++(this -> length_);
    }
   
}

template <typename T>
std::size_t LinkedList<T>::length() const noexcept
{
    return this -> length_;
}

template <typename T>
void LinkedList<T>::printList() const noexcept
{
    Node<T> *current = head;
    std::cout << "\n";
    for (std::size_t i = 0; i < this -> length_; ++i)
    {
        std::cout << current -> data << " -> ";
        current = current -> next;
    }
    std::cout << ".\n";
}

template <typename T>
void LinkedList<T>::remove(const std::size_t &position) 
{
    if (position >= this -> length_)
        throw  std::out_of_range("There is no element to remove at the specified position.");

    Node<T> *removedElement = this -> head;
    Node<T> *previous = this -> head;
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