//
// Created by mk on 11.05.2017.
//

#include <set>
#include <map>
#include <vector>

#include <algorithm>
#include <numeric>

#include "Algo.h"

namespace algo {
    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set keys;
        std::for_each(m.begin(), m.end(), [](const std::pair<std::string, int> &p) { keys.insert(p.first); });
        return keys;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector values;
        std::for_each(m.begin(), m.end(), [](std::pair<std::string, int> p) { values.(p.first); });
        return values;
    }
    //back_inserter

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        std::map<std::string, int> values;
//        std::for_each(m.begin(), m.end(),
//                      [](std::pair<std::string, int> p) { if (p.second % divisor == 0) values.insert(p); });
        std::copy_if(m.begin(), m.end(), values.begin(),
                     [](std::pair<std::string, int> p) { return p.second % divisor == 0; });
        return values;
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end(), std::greater<int>());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> values;
        std::copy(v.begin(), v.end(), values.begin());
        SortInPlace(&values);
        return values;
    }

    bool pairCompare(const std::pair<int, int> &firstElem, const std::pair<int, int> &secondElem) {
        return firstElem.second < secondElem.second;

    }

    bool tupleCompare(const std::tuple<int, int, int> &firstElem, const std::tuple<int, int, int> &secondElem) {
        return std::get<2>(firstElem) < std::get<2>(secondElem);
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end());
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), pairCompare);
    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(), tupleCompare);
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> values;
        std::transform(v.begin(), v.end(), values.begin(), [](auto p) { return std::to_string(p); });
        return values;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
//todo
    }

    int Sum(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 0);
    }

    int Product(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(std::begin(v), std::end(v), element) != v.end();
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        //todo
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return false;
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {

    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        return std::vector<int>();
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
//        std::copy_if(v.begin(), m.end(), values.begin(),
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}