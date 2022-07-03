#include <iostream>

#include <exception>


namespace sle  {

    class IndexError : public std::exception {
        public:
            const char * what() const throw() {
                return "Index Out Of Range";
            }
    };


    class CompareError : public std::exception {
        public:
            const char * what() const throw() {
                return "Can not compare the two lists";
            }
    };

    class ItemNotFound : public std::exception {
        public:
            const char * what() const throw() {
                return "Item Not Found";
            }
    };  
}