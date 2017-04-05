//
// Created by mk on 30.03.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


#include <experimental/string_view>
#include <string>
#include <set>

namespace pool {
    class TextPool {
    public:
        TextPool();

        TextPool(TextPool &&textPool);

        TextPool(const TextPool &textPool) = delete;

        TextPool(const std::initializer_list<std::string> &words);

        TextPool &operator=(TextPool &&textPool);

        TextPool &operator=(const TextPool &textPool);

        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<std::string> words;
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H