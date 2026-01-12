#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char **argv) {
    if (argc < 2) {
        // No arguments provided
        return;
    }

    _vec.clear();
    _deq.clear();

    // 1. Parsing
    for (int i = 1; i < argc; i++) {
        char *endptr;
        long val = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
            std::cerr << "Error: invalid argument." << std::endl;
            return;
        }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    // Print Before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
        if (i > 20) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;

    // 2. Sorting Vector
    clock_t startVec = clock();
    sortVector(_vec);
    clock_t endVec = clock();

    // 3. Sorting Deque
    clock_t startDeq = clock();
    sortDeque(_deq);
    clock_t endDeq = clock();

    // 4. Print Results
    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
        if (i > 20) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

void PmergeMe::sortVector(std::vector<int> &v) {
    mergeInsertionSortVector(v);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &v) {
    if (v.size() < 2) return;

    // Handle straggler
    bool hasStraggler = (v.size() % 2 != 0);
    int straggler = -1;
    if (hasStraggler) straggler = v.back();

    // Create Pairs
    std::vector<int> larger_elements;
    std::vector<int> smaller_elements;
    std::vector<std::pair<int, int> > pairs;

    size_t limit = v.size() - (hasStraggler ? 1 : 0);
    for (size_t i = 0; i < limit; i += 2) {
        if (v[i] > v[i+1]) {
            pairs.push_back(std::make_pair(v[i], v[i+1]));
            larger_elements.push_back(v[i]);
            smaller_elements.push_back(v[i+1]);
        } else {
            pairs.push_back(std::make_pair(v[i+1], v[i]));
            larger_elements.push_back(v[i+1]);
            smaller_elements.push_back(v[i]);
        }
    }

    // Recursively sort largest elements
    mergeInsertionSortVector(larger_elements);

    // Re-map smaller elements to the sorted chain
    std::vector<int> mainChain = larger_elements;
    std::vector<int> pending;

    std::vector<std::pair<int, int> > temp_pairs = pairs;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < temp_pairs.size(); ++j) {
            if (temp_pairs[j].first == mainChain[i]) {
                pending.push_back(temp_pairs[j].second);
                std::swap(temp_pairs[j], temp_pairs.back());
                temp_pairs.pop_back();
                break;
            }
        }
    }

    if (!pending.empty()) {
        mainChain.insert(mainChain.begin(), pending[0]);
    }

    std::vector<int> jacobsthal_indices = generateJacobsthal(pending.size());
    size_t p_idx = 1;
    size_t j_idx = 2;

    while (p_idx < pending.size()) {
        size_t next_jacob_idx = (j_idx < jacobsthal_indices.size()) ? jacobsthal_indices[j_idx] : pending.size();
        size_t right_bound = std::min(next_jacob_idx, pending.size());

        if (right_bound > p_idx) {
             for (size_t i = right_bound; i > p_idx; --i) {
                 binarySearchInsertionVector(mainChain, pending[i - 1]);
             }
        }
        p_idx = right_bound;
        j_idx++;
    }

    if (hasStraggler) {
        binarySearchInsertionVector(mainChain, straggler);
    }

    v = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &d) {
    mergeInsertionSortDeque(d);
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &d) {
    if (d.size() < 2) return;

    bool hasStraggler = (d.size() % 2 != 0);
    int straggler = -1;
    if (hasStraggler) straggler = d.back();

    std::deque<int> larger_elements;
    std::deque<std::pair<int, int> > pairs;
    size_t limit = d.size() - (hasStraggler ? 1 : 0);

    for (size_t i = 0; i < limit; i += 2) {
        if (d[i] > d[i+1]) {
            pairs.push_back(std::make_pair(d[i], d[i+1]));
            larger_elements.push_back(d[i]);
        } else {
            pairs.push_back(std::make_pair(d[i+1], d[i]));
            larger_elements.push_back(d[i+1]);
        }
    }

    mergeInsertionSortDeque(larger_elements);

    std::deque<int> mainChain = larger_elements;
    std::deque<int> pending;
    std::deque<std::pair<int, int> > temp_pairs = pairs;

    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < temp_pairs.size(); ++j) {
            if (temp_pairs[j].first == mainChain[i]) {
                pending.push_back(temp_pairs[j].second);
                std::swap(temp_pairs[j], temp_pairs.back());
                temp_pairs.pop_back();
                break;
            }
        }
    }

    if (!pending.empty()) {
        mainChain.insert(mainChain.begin(), pending[0]);
    }

    std::vector<int> jacobsthal_indices = generateJacobsthal(pending.size());
    size_t p_idx = 1;
    size_t j_idx = 2;

    while (p_idx < pending.size()) {
        size_t next_jacob_idx = (j_idx < jacobsthal_indices.size()) ? jacobsthal_indices[j_idx] : pending.size();
        size_t right_bound = std::min(next_jacob_idx, pending.size());

        if (right_bound > p_idx) {
             for (size_t i = right_bound; i > p_idx; --i) {
                 binarySearchInsertionDeque(mainChain, pending[i - 1]);
             }
        }
        p_idx = right_bound;
        j_idx++;
    }

    if (hasStraggler) {
        binarySearchInsertionDeque(mainChain, straggler);
    }
    d = mainChain;
}

std::vector<int> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    int prev = 0;
    int curr = 1;
    while (curr < (int)n) {
        int next = curr + 2 * prev;
        if (next > (int)n) next = n;
        jacob.push_back(next);
        prev = curr;
        curr = next;
        if (curr == (int)n) break;
    }
    return jacob;
}

void PmergeMe::binarySearchInsertionVector(std::vector<int> &mainChain, int element) {
    int left = 0;
    int right = mainChain.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mainChain[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    mainChain.insert(mainChain.begin() + left, element);
}

void PmergeMe::binarySearchInsertionDeque(std::deque<int> &mainChain, int element) {
    int left = 0;
    int right = mainChain.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mainChain[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    mainChain.insert(mainChain.begin() + left, element);
}
