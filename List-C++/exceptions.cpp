#include <iostream>

#include <exception>


namespace sle  {

    class IndexError : public std::exception {
        public:
            const char * what() const throw() {
                return "Index Out Of Range";
            }
    };
}