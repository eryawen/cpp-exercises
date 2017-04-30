//
// Created by mk on 12.04.2017.
//
#include "Word.h"

namespace datastructures {
    bool Word::operator==(const Word &other) const {
        return word.compare(other.word) == 0;
    }

    bool Word::operator<(const Word &other) const {
        return word.compare(other.word) > 0;
    }

    bool Word::operator>(const Word &other) const {
        return word.compare(other.word) < 0;
    }

    bool Word::wordContainsOnlyLetters(const Word &word) {
        for (char &c : word.get()) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Word &word) {
        os << word.word;
        return os;
    }

}