#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    // TODO: Define iterator typedefs here
    // Hint: access std::stack<T>::container_type::iterator

    // TODO: Implement begin(), end(), etc.
    // Hint: access the underlying container using this->c
};

#endif
