//
// Created by mk on 12.04.2017.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

#include <iostream>

namespace datastructures {
    class Counts {
    public:
        Counts() : word_count(1) {}

        Counts(int n) : word_count(n) {};

        bool operator==(const Counts &other) const;

        bool operator<(const Counts &other) const;

        bool operator>(const Counts &other) const;

        Counts operator++(int);

        int get() const { return word_count; };

        friend std::ostream &operator<<(std::ostream &os, const Counts &counts);

    private:
        int word_count;
    };

    std::ostream &operator<<(std::ostream &os, const Counts &counts);

}

#endif //JIMP_EXERCISES_COUNTS_H
