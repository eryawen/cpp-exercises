//
// Created by mk on 01.04.2017.
//

#ifndef JIMP_EXERCISES_GREATESTPRODUCT_H
#define JIMP_EXERCISES_GREATESTPRODUCT_H

#include <vector>

long GreatestProduct(const std::vector<int> &numbers, int k);

bool isPossibleToGetPositiveResult(unsigned long neg_size, unsigned long pos_size, int k);

long findMaxPositiveValue(std::vector<int> &negative, std::vector<int> &positive, int k);

long findMaxNegativeValue(std::vector<int> &negative, std::vector<int> &positive, int k);

long multiplyVectorElements(std::vector<int> &numbers, int start_index, int end_index);

#endif //JIMP_EXERCISES_GREATESTPRODUCT_H
