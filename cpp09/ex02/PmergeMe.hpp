#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // Main driver
    void run(int argc, char **argv);

private:
    // Templated or separate functions for sorting
    void sortVector(std::vector<int> &v);
    void sortDeque(std::deque<int> &d);

    // Helpers for Ford-Johnson
    void mergeInsertionSortVector(std::vector<int> &v);
    void mergeInsertionSortDeque(std::deque<int> &d);

    std::vector<int> generateJacobsthal(size_t n);

    // Binary search insertion
    void binarySearchInsertionVector(std::vector<int> &mainChain, int element);
    void binarySearchInsertionDeque(std::deque<int> &mainChain, int element);
};

#endif
