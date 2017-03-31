//
// Created by mk on 30.03.2017.
//

#include "TextPool.h"

namespace pool {
    TextPool::TextPool() {
    }

    TextPool::TextPool(const std::initializer_list<std::string> &words) {
        for (const std::string &w : words) {
            Intern(w);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        std::set<std::string>::iterator it;
        for (it = words.begin(); it != words.end(); ++it) {
            if (std::string(str).compare(*it) == 0) {
                return *it;
            }
        }
        words.insert(str);
        return std::experimental::string_view(str);
    }

    TextPool::~TextPool() {
    }

    TextPool::TextPool(TextPool &&textPool) {
        std::swap(words, textPool.words);
    }

    TextPool &TextPool::operator=(TextPool &&textPool) {
        if (this == &textPool) {
            return *this;
        }
        std::swap(words, textPool.words);
        textPool.words.clear(); //todo
        return *this;
    }

    size_t TextPool::StoredStringCount() const {
        return words.size();
    }

    TextPool &TextPool::operator=(const TextPool &textPool) {
        if (this == &textPool) {
            return *this;
        }
        words = textPool.words;
        return *this;
    }
}

