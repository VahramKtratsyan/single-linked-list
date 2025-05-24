#pragma once

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data) noexcept;
};

template <typename T>
Node<T>::Node(T data) noexcept : data(data), next(nullptr) {}