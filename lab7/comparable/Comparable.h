//
// Created by mk on 21.04.2017.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

namespace academia {
    class StudentComparator {
        virtual bool IsLess(const Student &left, const Student &right) const = 0;

        bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameAscending : public StudentComparator {
        bool IsLess(const Student &left, const Student &right) const override;
    };

    class ByFirstNameDescending : public StudentComparator {
        bool IsLess(const Student &left, const Student &right) const override;
    };

    class ByLastNameAscending : public StudentComparator {
        bool IsLess(const Student &left, const Student &right) const override;
    };

    class ByProgramAscendingEmptyFirst : public StudentComparator {
        bool IsLess(const Student &left, const Student &right) const override;
    };

    class ByProgramAscendingEmptyLast : public StudentComparator {
        bool IsLess(const Student &left, const Student &right) const override;
    };
}
#endif //JIMP_EXERCISES_COMPARABLE_H

/*
 * ByFirstNameAscending
ByFirstNameDescending
ByLastNameAscending
ByProgramAscendingEmptyFirst, porównuje kierunki studiów alfabetycznie ale przesuwa na początek nieustawiony program (string pusty)
ByProgramAscendingEmptyLast, j.w. ale przesuwa na koniec nie ustawiony program studiów
[1 plus] w programie main wykorzystać wybrany porównywacz do posortowania wektora studentów (algorytm sort z biblioteki algorithm)
 */