//
// Created by mk on 21.04.2017.
//

#include "Comparable.h"

namespace academia {
    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) const {
        return false;
    }

    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) const {
        return false;
    }

    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) const {
        return false;
    }

    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) const {
        return false;
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) const {
        return false;
    }

    bool StudentComparator::operator()(const Student &left, const Student &right) {
        return false;
    }

}