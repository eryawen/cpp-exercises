//
// Created by mk on 30.03.2017.
//
#include "XXX.h"

XXX make_copy(XXX xxx) {
    return xxx;
}

int main() {
    XXX old_xxx{};

    XXX new_xxx{old_xxx};

    XXX another_xxx{};

    another_xxx = new_xxx;

    another_xxx = std::move(new_xxx);

    XXX one_more = make_copy(another_xxx);

}