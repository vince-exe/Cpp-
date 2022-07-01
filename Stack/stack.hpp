#pragma once

#include <iostream>

#include "./List-C++/list.hpp"
#include "./List-C++/list.cpp"

namespace stk {

    template <class T> class Stack {
        private:
            /* create the list object */
            stl::List<T> stack;
        
        public:
            /* push an item in the stack */
            void push(T item);

            /* return the last element of the stack */
            T pop();

            /* return the number of element of the stack */
            int len();

            /* search for an item in the stack and return his position
               if the item doesn't exist in the stack then the method will return -1

               Warning: Use this method with basic types otherwise you have to overload the == operator
            */
            int search(T item);

            /* check if the stack is empty, return True if it is */
            int empty();

            /* clear the stack */
            void clear();

            /* return the memory address of a new stuck with the items of the current stack */
            stk::Stack<T> clone();

            /* return the number of items that have the given value

                WARNING: Use this method with basic types otherwise you have to overload the == operator
            */
            int count(T item);      

            /* return the last element of the stack without remove it */
            T get();
    };

}