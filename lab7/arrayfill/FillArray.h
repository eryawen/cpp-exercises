//
// Created by mk on 20.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H


#include "Filler.h"

namespace arrays {

    class FillArray {
    public:
        FillArray(int size, const Filler &filler, std::vector<int> *array);
    };

}
#endif //JIMP_EXERCISES_ARRAYFILL_H
