//
// Created by mk on 05.04.2017.
//

#include "WordCounter.h"
#include <fstream>
#include <algorithm>
//#include </boost/foreach.hpp>
using datastructures::Word;
using datastructures::Counts;

namespace datastructures {
    WordCounter::WordCounter() {
        //todo
    }

    WordCounter::WordCounter(const std::initializer_list<Word> &words) {
        for (const Word &word : words) {
            addWord(word);
        }
    }

    int WordCounter::operator[](const std::string &word) {
        for (auto &word_count : words_with_count) {
            if (word_count.first == word) {
                return word_count.second.get();
            }
        }
    }

    std::set<Word> WordCounter::words() {
        std::set<Word> words;
        for (auto pair : words_with_count) {
            words.insert(pair.first);
        }
        return words;
    }

    int WordCounter::distinctWords() {
        return words_with_count.size();
    }

    int WordCounter::totalWords() {
        int size = 0;

        for (auto &word_with_count : words_with_count) {
            size += word_with_count.second.get();
        }
        return size;
    }

    void WordCounter::FromInputStream(const std::istream &data) {
    }

    void WordCounter::addWord(const Word &word) {
        if (!Word::wordContainsOnlyLetters(word)) {
            return;
        }
        for (auto &word_count : words_with_count) {
            if (word_count.first == word) {
                word_count.second++;
                return;
            }
        }
        words_with_count.push_back(std::make_pair(Word(word), Counts()));
    }

    std::ostream &operator<<(std::ostream &os, WordCounter &wordCounter) {
        std::sort(wordCounter.words_with_count.begin(), wordCounter.words_with_count.end(),
                  [](auto &left, auto &right) {
                      return left.second > right.second;
                  });

        for (const auto &pair : wordCounter.words_with_count) {
            os << pair.first << " " << pair.second << std::endl;
        }
        return os;
    }
}
//todo: check if << works, add tests with non-alphabetic characters