#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "--- Subject Test (MutantStack) ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    // TODO: Uncomment these lines after implementing iterators
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite) {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }

    std::stack<int> s(mstack);

    std::cout << "\n--- Comparison Test (std::list) ---" << std::endl;
    // TODO: Implement the same test with std::list to compare output

    return 0;
}
