//
// Created by mk on 12.04.2017.
//
#include "Counts.h"

namespace datastructures {
    bool Counts::operator==(const Counts &other) const {
        return word_count == other.word_count;
    }

    bool Counts::operator<(const Counts &other) const {
        return word_count < other.word_count;
    }

    bool Counts::operator>(const Counts &other) const {
        return word_count > other.word_count;
    }

    Counts Counts::operator++(int) {
        Counts copy = (*this);
        word_count++;
        return copy;
    }

    std::ostream &operator<<(std::ostream &os, const Counts &counts) {
        os << counts.word_count;
        return os;
    }
}