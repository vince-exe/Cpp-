#include "stack.hpp"

#include "./Exceptions/excpetions.cpp"

#include <iostream>


template<class T> T &stk::Stack<T>::operator[](int index) {
    /* check the index */
    if (index < 0 or index >= this->len()) {
        throw ste::IndexError();
    }

    int i = 0;
    stn::Node<T>* node = nullptr;

    /* move the node at the given index */
    for(node = this->stack.begin(); i < index; node = this->stack.next(node), i++);

    /*return the value of the node at the given index */
    return node->data;
}

template<class T> void stk::Stack<T>::push(T item) {
    this->stack.appendEnd(item);
}

template<class T> int stk::Stack<T>::len() {
    return this->stack.lenght();
}

template<class T> T stk::Stack<T>::pop() {
    /* if the stack is empty throw the GetItemError Exception */
    if (this->empty()) {
        throw ste::GetItemError();
    }

    return this->stack.popEnd();
}

template<class T> int stk::Stack<T>::search(T item) {
    return this->stack.find(item);
}

template<class T> int stk::Stack<T>::empty() {
    return (this->stack.lenght()) ? 0 : 1;
}

template<class T> void stk::Stack<T>::clear() {
    this->stack.free();
}

template<class T> stk::Stack<T> stk::Stack<T>::clone() {
    stk::Stack<T> newStack;
    int i = 0;

    /* iterate over the list */
    for(stn::Node<T>* node = this->stack.begin(); i < this->len(); node = this->stack.next(node), i++) {
        newStack.push(node->data);
    }

    /* return the memory address of the new stack */
    return newStack;
}

template<class T> int stk::Stack<T>::count(T item) {
    return this->stack.count(item);
}

template<class T> T stk::Stack<T>::get() {
    /* if the stack is empty throw the GetItemError Exception */
    if (this->empty()) {
        throw ste::GetItemError();
    }

    return this->stack.getItem(this->len() - 1);
}