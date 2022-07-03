#include <iostream>
#include <list>

#include "list.hpp"
#include "list.cpp"

/*
file created for testing the List 

Version: BETA

Methods Tested:

    appendStart();

    appendEnd();

    lenght();

    getItem2();

    remove();

    begin();

    end();

    next();

    find();

    getItem();

    getItemAddress();

    removeAll();

    count();

    replace();

    replaceAll();

    popFront();

    popEnd();

Founder: Vincenzo Caliendo

Third Part Programs:

    valgrind: used to test if the list cause memory leaks.

Last Update: 15 / 05 / 2022 / 17:28
*/


int main() {
    /*declare the list with the type that you want*/
    stl::List<int> lista;
    
    /*append the items (start or end)*/
    lista.appendStart(5);
    lista.appendStart(10);
    lista.appendEnd(20);
    lista.appendEnd(10);

    /*print the lenght of the list*/
    std::cout<<"\nLenght of the list: "<<lista.lenght()<<std::endl;

    /*print the list with a simple for*/
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista[i]<<std::endl;
    }

    /*remove the items from the list and check if they are been removed*/
    if(lista.remove(5)) {
        std::cout<<"\nItem succesfully removed"<<std::endl;
    }
    lista.remove(10);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista[i]<<std::endl;
    }

    /*
    if you want to have more control on your nodes, you can use stn::Node namespace (namespace built into list.hpp)
    to declare a node and move it with the showen methods!!
    */
    std::cout<<std::endl;

    int i=0;
    for(stn::Node<int>* node = lista.begin(); !lista.end(node); node = lista.next(node), i++) {
        node->data = i;
    }

    std::cout<<"\nPrint the list after the modify"<<std::endl;
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista[i]<<std::endl;
    }

    try {
        /*find the position of the items in the list*/
        std::cout<<"\nPosition of the item that has 0 as value: "<<lista.find(0)<<std::endl;
    }
    catch(sle::ItemNotFound()) {
        std::cout<<"\nThe item doesn't exist";
    }
    
    /*free the list*/
    lista.free();
    
    lista.appendEnd(1);
    lista.appendEnd(1);
    lista.appendEnd(1);
    lista.appendEnd(2);
    
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\nitem: "<<lista[i];
    }

    lista.removeAll(1); 

    lista.appendEnd(5);
    lista.appendEnd(10);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\nitem: "<<lista[i];
    }


    
    std::cout<<std::endl;


    for(int i=0; i<10; i++) {
        lista.appendEnd(10);
    }

    std::cout<<"\nHow many nodes with the 10 value are there??: "<<lista.count(10);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    }

    std::cout<<"\nFirst element of the list: "<<lista.popFront();

    lista.appendEnd(56);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    } 
    
    std::cout<<"\nLast element of the list: "<<lista.popEnd()<<std::endl;
    
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    }

    /*replace the item with value 56*/
    std::cout<<"replaced item: "<<lista.replace(10, 156);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    }

    lista.free();

    /*replace all the elements*/
    for(int i=0; i<10; i++) {
        lista.appendEnd(11);
    }
    stn::Node<int>* node = lista.begin();
    node->data = 56;

    std::cout<<"\nBefore the replace\n";
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    }

    lista.replaceAll(11, 8);

    std::cout<<"\nAfter the replace\n";
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<"\n"<<lista[i];
    }
    
    lista.free();

    /*testing new constructor*/
    stl::List<int> list(8, 50);

    std::cout<<"\nNew list's lenght: "<<list.lenght();
    for(int i=0; i<list.lenght(); i++) std::cout<<"\n"<<list[i];

    /*testing another constructor overload*/
    stl::List<int> list2(5, 100, true);

    std::cout<<"\nNew list's lenght: "<<list2.lenght();
    for(int i=0; i<list2.lenght(); i++) std::cout<<"\n"<<list2[i];

    /*free all the lists*/
    lista.free();
    list.free();
    list2.free();

    return 0;
}