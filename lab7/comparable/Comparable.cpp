//
// Created by mk on 21.04.2017.
//

#include "Comparable.h"
#include "../../lab6/academia/StudentRepository.h"

namespace academia {
    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) const {
        return left.Last_name() < right.Last_name();
    }

    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) const {
        if (left.Program() == "") return true;
        if (left.Program() == "") return false;
        return left.Program() < right.Program();
    }

    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) const {
        return left.First_name() > right.First_name();
    }

    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) const {
        return left.First_name() < right.First_name();
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) const {
        if (left.Program() == "") return false;
        if (left.Program() == "") return true;
        return left.Program() < right.Program();
    }

    bool StudentComparator::operator()(const Student &left, const Student &right) {
        return this->IsLess(left, right);
    }


}

/*
 * ByFirstNameAscending
ByFirstNameDescending
ByLastNameAscending
ByProgramAscendingEmptyFirst, porównuje kierunki studiów alfabetycznie ale przesuwa na początek nieustawiony program (string pusty)
ByProgramAscendingEmptyLast, j.w. ale przesuwa na koniec nie ustawiony program studiów
[1 plus] w programie main wykorzystać wybrany porównywacz do posortowania wektora studentów (algorytm sort z biblioteki algorithm)
 */