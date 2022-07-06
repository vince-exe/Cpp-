#pragma once

namespace stn {
    template<typename T> class Node {
        public:
            T data;
            Node* next;
            Node() : data(), next(nullptr) {}
    };
}

namespace stl {
    template <class T> class List {
        private:
            stn::Node<T>* head;

            stn::Node<T>* end_;

            size_t lenght_;

            constexpr void setHead(stn::Node<T>* newAddress);
            constexpr void setEnd(stn::Node<T>* newAddress);

            stn::Node<T>* getEnd();

        public:
            /*default constructor*/
            List();

            /*create and initialize a list with n values, the values will be added at the start of the list*/
            List(const int iterate,const T& value);

            /*create and initilize a list with n values, if end is True the values will be added at the end of the list, else..*/
            List(const int iterate, const T& value, bool end);

            /* return the value at the given index
               Note:
                    if the index doesn't exist, the method will raise an sle::IndexError() exception*/
            T operator[](int index);

            /* appen the given value at the END of the list */
            void operator+=(const T& value);
            
            /* compare (the nodes value) of two lists
               Note:
                    if the lists are of different length, the method will raise an sle::CompareError() exception
            */
            inline bool operator==(stl::List<T>& right);

            /* returns a list linked by the sum of the nodes of the two given lists 
               Note:
                    the nodes will be added at the end of the new list
            */
            stl::List<T> operator+(stl::List<T> right);

            /* check if the len of the left side list is greater than the len of the other list*/
            constexpr bool operator>(const stl::List<T>& right);

            /* check if the len of the left side list is lower than the len of the other list */
            constexpr bool operator<(const stl::List<T>& right);

            /* copy the nodes value of a list into another list
               Note:
                    the nodes value will be added at the end of the new list 
            */
            stl::List<T> operator=(stl::List<T> right);

            /*append the item to the start of the list*/
            void appendStart(const T& value);

            /*free the list*/
            void free();    

            /*append the item to the end of the list*/
            void appendEnd(const T& value);
            
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

            /**
             * @brief remove the item in the list with that value, return true if the item has been successfully removed
             *  equality operator required
             * @param value 
             * @return true if success
             */
            bool remove(const T& value);

            /**
             * @brief changes first  of value with new value
             * 
             * @param value 
             * @param newValue 
             * @return true if success
             */
            bool replace(const T& value, const T& newValue);

            /**
             * @brief replaces all appearance of value with newvalue
             * 
             * @param value 
             * @param newValue 
             * @return true if at least one node has been changed  
             */
            bool replaceAll(const T& value, const T& newValue);

            /**
             * @brief removes all appearances of value
             * 
             * @param value 
             */
            void removeAll(T value);

            /**
             * @brief returns data of first element, element removed from list
             * 
             * @return T 
             */
            T popFront();

            /**
             * @brief returns data of last element, element removed from list
             * 
             * @return T 
             */
            T popEnd();

            /**
             * @brief returns first appearance of value in list, equality operator required
             * 
             * @param value 
             * @return position 
             */
            int find(const T& value);
            
            /**
             * @brief returns number of nodes with given value, queality operator required
             * 
             * @param value 
             * @return amount 
             */
            int count(const T& value);

            /*
            return the item at the given position
            WARNING: It's different from "getItem" because this method check if the given index exist
            
            Case: Index Greater Than List Lenght: the method will return the item at the first position
            Case: Index Negative: the method will return the item at the first position
            */
            T getItem(int index);

            /*return the lenght of the list*/
            int lenght();
    };
}