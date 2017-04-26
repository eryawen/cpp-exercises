//
// Created by mk on 12.04.2017.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {
    class Word {
    public:
        Word(const std::string &word_) : word(word_) {};

        bool operator==(const Word &other) const;

        bool operator<(const Word &other) const;

        bool operator>(const Word &other) const;

        std::string get() const { return word; };

        static bool wordContainsOnlyLetters(const Word &word);

        friend std::ostream &operator<<(std::ostream &os, const Word &word);

    private:
        std::string word;
    };

    std::ostream &operator<<(std::ostream &os, const Word &word);
}

#endif //JIMP_EXERCISES_WORD_H
