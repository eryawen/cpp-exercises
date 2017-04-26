//
// Created by mk on 05.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <string>
#include <memory>
#include <vector>
#include <set>
#include "Word.h"
#include "Counts.h"

using datastructures::Word;

namespace datastructures {
    class WordCounter {
    public:

        WordCounter();

        WordCounter(const std::initializer_list<Word> &words);

        int operator[](const std::string &word);

        std::set<Word> words();

        int distinctWords();

        int totalWords();

        static void FromInputStream(const std::istream &data); //todo

        friend std::ostream &operator<<(std::ostream &os, WordCounter &wordCounter);

    private:
        std::vector<std::pair<Word, Counts>> words_with_count;

        void addWord(const Word &word);
    };

    std::ostream &operator<<(std::ostream &os, WordCounter &wordCounter);


}
#endif //JIMP_EXERCISES_WORDCOUNTER_H


