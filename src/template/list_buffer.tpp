#pragma once
#include <utility>

template <typename T>
class ListBuffer
{
protected:
    class Node
    {
    public:
        T data;
        Node* next;

        Node(const T& data) noexcept;
    };

    Node* head;
    Node* tail;
    std::size_t length_;

    ListBuffer() noexcept;
    ListBuffer(const ListBuffer<T>& original);
    ListBuffer(ListBuffer<T>&& other);
    ListBuffer& operator = (const ListBuffer<T>& other);
    ListBuffer& operator = (ListBuffer<T>&& other);
    ~ListBuffer();
};

template <typename T>
ListBuffer<T>::Node::Node(const T& data) noexcept : data(data), next(nullptr) {}

template <typename T>
ListBuffer<T>::ListBuffer() noexcept: head(nullptr), tail(nullptr), length_(0) {}

template <typename T>
ListBuffer<T>::ListBuffer(const ListBuffer<T>& original) : head(nullptr), tail(nullptr), length_(0)
{
    Node* currentHead = (original.length_ == 0) ? nullptr : new Node(original.head -> data);
    Node* currentOriginal = original.head;
    Node* currentNode = currentHead;
    for (std::size_t i = 1; i < original.length_; ++i)
    {
        currentOriginal = currentOriginal -> next;
        currentNode -> next = new Node(currentOriginal -> data);
        currentNode = currentNode -> next;
    }

    this -> head = currentHead;
    this -> tail = currentNode;
    this -> length_ = original.length_;
}

template <typename T>
ListBuffer<T>::ListBuffer(ListBuffer<T>&& other) : head(nullptr), tail(nullptr), length_(0)
{
    std::swap(this -> head, other.head);
    std::swap(this -> tail, other.tail);
    std::swap(this -> length_, other.length_);
}

template <typename T>
ListBuffer<T>& ListBuffer<T>::operator = (const ListBuffer<T>& other)
{
    if (&other == this)
        return *this;

    ListBuffer<T> temp(other);
    std::swap(this -> head, temp.head);
    std::swap(this -> tail, temp.tail);
    std::swap(this -> length_, temp.length_);
    return *this;
}

template <typename T>
ListBuffer<T>& ListBuffer<T>::operator = (ListBuffer<T>&& other)
{
    if (&other == this)
        return *this;

    std::swap(this -> head, other.head);
    std::swap(this -> tail, other.tail);
    std::swap(this -> length_, other.length_);
    return *this;
}

template <typename T>
ListBuffer<T>::~ListBuffer()
{
    Node* current = this -> head;
    for (std::size_t i = 0; i < this -> length_; ++i)
    {
        this -> head = this -> head -> next;
        delete current;
        current = this -> head;
    }

    this -> head = nullptr;
    this -> tail = nullptr;
    this -> length_ = 0;
}