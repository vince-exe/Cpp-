#include "stack.hpp"

#include <iostream>

template<class T> void stk::Stack<T>::push(T item) {
    this->stack.appendEnd(item);
}

template<class T> int stk::Stack<T>::len() {
    return this->stack.lenght();
}

template<class T> T stk::Stack<T>::pop() {
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
    return this->stack.getItem(this->len() - 1);
}