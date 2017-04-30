//
// Created by mk on 05.04.2017.
//

#include "Zipper.h"

namespace datastructures {

    std::vector<std::pair<std::string, int>>
    Zipper::zip(const std::vector<std::string> &words, const std::vector<int> &numbers) {
        std::vector<std::pair<std::string, int>> vector;
        auto iter_words = words.begin();
        auto iter_numbers = numbers.begin();

        while (iter_words != words.end() && iter_numbers != numbers.end()) {
            vector.push_back({*iter_words, *iter_numbers});
            iter_words++;
            iter_numbers++;
        }

        while (iter_words != words.end()) {
            vector.push_back({*iter_words, 0});
            iter_words++;
        }
        while (iter_numbers != numbers.end()) {
            vector.push_back({"", *iter_numbers});
            iter_numbers++;
        }
        return vector;
    }
}