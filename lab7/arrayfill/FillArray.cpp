//
// Created by mk on 20.04.2017.
//

#include <vector>
#include "FillArray.h"

namespace arrays {
    FillArray::FillArray(int size, const Filler &filler, std::vector<int> *array) {
        array->clear();
        array->reserve(size);
        for (int i = 0; i < size; i++) {
            array->emplace_back(filler.Value(i));
        }

    };
}