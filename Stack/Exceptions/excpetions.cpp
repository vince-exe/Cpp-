#include <iostream>

#include <exception>


/* Standard Stack Exception namespace */
namespace ste {
    
    class GetItemError : public std::exception {
        public:
            const char * what() const throw() {
                return "Can't get items from empty stack";
            }
    };


    class IndexError : public std::exception {
        public:
            const char * what() const throw() {
                return "Index out of range";
            }
    };

}
