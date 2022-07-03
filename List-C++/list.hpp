#pragma once

#include <iostream>

#include <memory>


namespace stn {
    template<typename var> struct Node {
        var data;
        struct Node* next;
    };
}

namespace stl {
    template <class T> class List {
        private:
            struct stn::Node<T>* head;

            struct stn::Node<T>* end_;

            int lenght_;

            void setHead(stn::Node<T>* newAddress);
            void setEnd(stn::Node<T>* newAddress);

            stn::Node<T>* getEnd();

        public:
            /*default constructor*/
            List();

            /*create and initialize a list with n values, the values will be added at the start of the list*/
            List(int iterate, T value);

            /*create and initilize a list with n values, if end is True the values will be added at the end of the list, else..*/
            List(int iterate, T value, bool end);

            /* return the value at the given index
               Note:
                    if the index doesn't exist, the method will raise an sle::IndexError() exception*/
            T operator[](int index);

            /* appen the given value at the END of the list */
            void operator+=(T value);
            
            /* compare (the nodes value) of two lists
               Note:
                    if the lists are of different length, the method will raise an sle::CompareError() exception
            */
            inline bool operator==(stl::List<T> right);

            /* returns a list linked by the sum of the nodes of the two given lists 
               Note:
                    the nodes will be added at the end of the new list
            */
            stl::List<T> operator+(stl::List<T> right);

            /* check if the len of the left side list is greater than the len of the other list*/
            bool operator>(stl::List<T> right);

            /* check if the len of the left side list is lower than the len of the other list */
            bool operator<(stl::List<T> right);

            /* copy the nodes value of a list into another list
               Note:
                    the nodes value will be added at the end of the new list 
            */
            stl::List<T> operator=(stl::List<T> right);

            /*append the item to the start of the list*/
            void appendStart(T value);

            /*free the list*/
            void free();    

            /*append the item to the end of the list*/
            void appendEnd(T value);
            
            /*return the address of memory of the first element in the list*/
            stn::Node<T>* begin();

            /*move the given pointer to the next node of the list*/
            stn::Node<T>* next(stn::Node<T>* it);

            /*
            return the memory address of the item at the given index
            WARNING:
                case Index-Greater: the method will return the last memory address of the list
                case Index-Negative: the method will return the first memory address of the list
            */
            stn::Node<T>* getItemAddress(int index);

            /*
            check if the given pointer point to the end of the list
            
            True: The pointer does.
            False: The pointer doesn't
            */
            bool end(stn::Node<T>* it);

            /*
            remove the item in the list with that value, return true if the item has been successfully removed
            WARNING: This method return only the first item that has the given value,
                     If there are other items with the given value, they will not be removed
                     Use this method only if your list is one of this type: (int, char, string, bool, float, double)
                     otherwise you have to overload the == operator
            */
            bool remove(T value);

            /*
            change the value of a node with the given value, return true if the operation went succesfully else return false
            NOTE: If the list has more nodes with the given value, it will be modified only the first node the the method find
                  If you want something else check replaceAll();
            */
            bool replace(T value, T newValue);

            /*change the value of all the nodes of the list that have the given value, return true if at least one of this has been modified, else return false*/
            bool replaceAll(T value, T newValue);

            /*
            remove all the items the has as value the given value.
            WARNING: Use this method only if your list is one of this type (int, char, string bool, float, double)
            otherwise you have to overload the == operator
            */
            void removeAll(T value);

            /*
            return the first element of the list (head), and reduce the lenght of 1
            */
            T popFront();

            /*return the last element of the list, and reduce the lenght of 1*/
            T popEnd();

            /*
            Search in the list the item that has the given value and return his position,
            if the method doesn't find anithing it will raise an sle::ItemNotFound() exception

            WARNING: use this method only if your list is one of this type (int, char, string, bool, float, double)
            otherwise you have to overload the == operator
            */
            int find(T value);
            
            /*
            this method iterate throw the list and return the number of nodes that have as value the given value
            WARNING: use this method onlt if your list is one of this type (int, char, string, bool, float, double)
            */
            int count(T value);

            /*
            return the item at the given position
            WARNING: It's different from "getItem" because this method check if the given index exist
            
            Case: Index Greater Than List Lenght: the method will return the item at the first position
            Case: Index Negative: the method will return the item at the first position
            */
            T getItem2(int index);

            /*return the lenght of the list*/
            int lenght();
    };
}