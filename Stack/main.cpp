#include <iostream>

#include "stack.hpp"
#include "stack.cpp"

/*
Founder: Vincenzo Caliendo

Last Update: 1 / 07 / 2022

Project Creation: 1 / 07 / 2022
*/

int main() {
    /* declare the stack */
    stk::Stack<int> stack;

    /* push the items */
    stack.push(10);
    stack.push(10);
    stack.push(25);
    stack.push(500);

    /* print the items (without removing it) */
    for(int i = 0; i < stack.len(); i++) 
        std::cout<<"\n"<<stack.get();

    /* print the size of the stuck */
    std::cout<<"\n"<<stack.len();

    /* pop the last element */
    std::cout<<"\n"<<stack.pop();

    /* clear the stack */
    stack.clear();

    /* 
       this file take care of let you see how to basically use this library
       not all the implemented functions are tested here
    */
    return 0;
}