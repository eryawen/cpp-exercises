//
// Created by mk on 05.04.2017.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <string>
#include <vector>

namespace datastructures {
    struct Zipper {
        static std::vector<std::pair<std::string, int>>
        zip(const std::vector<std::string> &words, const std::vector<int> &numbers);
    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
