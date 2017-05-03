//
// Created by mk on 01.04.2017.
//

#include "GreatestProduct.h"
#include <cstdlib>
#include <algorithm>

long GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> positive;
    std::vector<int> negative;
    for (int n : numbers) {
        if (n < 0) {
            negative.push_back(abs(n));
        } else {
            positive.push_back(n);
        }
    }

    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end());

    return (isPossibleToGetPositiveResult(negative.size(), positive.size(), k))
           ? findMaxPositiveValue(negative, positive, k)
           : findMaxNegativeValue(negative, positive, k) * (-1);
}

bool isPossibleToGetPositiveResult(unsigned long neg_size, unsigned long pos_size, int k) {
    return !((pos_size == 0 && k % 2 != 0) || ((pos_size + neg_size == k + 1) && (k % 2 != 0)));
}

long findMaxPositiveValue(std::vector<int> &negative, std::vector<int> &positive, int k) {
    int result = 1;
    long pos_index = positive.size() - 1;
    long neg_index = negative.size() - 1;
    int elementsToMultiply = k;
    if (k % 2 != 0) {
        result *= positive[pos_index];
        elementsToMultiply--;
        pos_index--;
    }
    while (elementsToMultiply > 0) {
        if (pos_index <= 0) {
            return result * multiplyVectorElements(negative, neg_index - elementsToMultiply + 1, neg_index);
        }
        if (neg_index <= 0) {
            return result * multiplyVectorElements(positive, pos_index - elementsToMultiply + 1, pos_index);
        }
        int pos_result = positive[pos_index] * positive[pos_index - 1];
        int neg_result = negative[neg_index] * negative[neg_index - 1];
        if (pos_result > neg_result) {
            pos_index -= 2;
            result *= pos_result;
        } else {
            neg_index -= 2;
            result *= neg_result;
        }
        elementsToMultiply -= 2;
    }
    return result;
}

long findMaxNegativeValue(std::vector<int> &negative, std::vector<int> &positive, int k) {
    int result = 1, pos_index = 0, neg_index = 0;
    long pos_max_index = positive.size() - 1;
    long neg_max_index = negative.size() - 1;

    for (int elementsToMultiply = k; elementsToMultiply > 0; elementsToMultiply--) {
        if (pos_index >= pos_max_index) {
            return result * multiplyVectorElements(negative, neg_index, neg_index + elementsToMultiply - 1);
        }
        if (neg_index == neg_max_index) {
            return result * multiplyVectorElements(positive, pos_index, pos_index + elementsToMultiply - 1);
        }
        int pos = positive[pos_index];
        int neg = negative[neg_index];
        if (pos < neg) {
            pos_index++;
            result *= pos;
        } else {
            neg_index++;
            result *= neg;
        }
        elementsToMultiply--;
    }
    return result;
}

long multiplyVectorElements(std::vector<int> &numbers, int start_index, int end_index) {
    int result = 1;
    for (int index = start_index; index <= end_index; index++) {
        result *= numbers[index];
    }
    return result;
}