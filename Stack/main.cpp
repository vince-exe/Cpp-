#include <iostream>

#include "stack.hpp"
#include "stack.cpp"


/*
Founder: Vincenzo Caliendo

Last Update: 2 / 07 / 2022

Project Creation: 1 / 07 / 2022

Note: 
       this file take care of let you see how to basically use this library
       not all the implemented functions are tested here
    
*/


int main() {
    /* declare the stack */
    stk::Stack<int> stack;

    /* push the items */
    stack.push(10);
    stack.push(10);
    stack.push(25);
    stack.push(500);
    
    std::cout<<"\nGet Element With Brackets: " << stack[3];

    /* print the items (without removing it) */
    for(int i = 0; i < stack.len(); i++) 
        std::cout<<"\nItem: "<< i + 1 << " "<<stack.get();

    /* print the size of the stuck */
    std::cout<<"\nStack Len: "<<stack.len();

    /* pop the last element */
    std::cout<<"\nLast Element: "<<stack.pop();

    /* clear the stack */
    stack.clear();
    

    /* How To Use Library Exceptions */
    try {
        /* dangerous code, we are trying to pop an element from an empty stack */
        std::cout<<stack.pop();
    }
    catch(ste::GetItemError) {
        /* message to show */
    }
    
    try {
        /* dangerous code, we are trying to get an element in a index out of range */
        std::cout<<stack[100];
    }
    catch(ste::IndexError) {
        /* message to show */
    }

    return 0;
}