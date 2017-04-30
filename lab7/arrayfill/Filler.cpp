//
// Created by mk on 20.04.2017.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include <random>
#include "Filler.h"

namespace arrays {
    int UniformFill::Value(int index) const {
        return value_;
    }


    int IncrementalFill::Value(int index) const {
        return start_ + index * step_;
    }

    int RandomFill::Value(int index) const {
        return (*int_distribution_)(*random_engine_);
    }


    RandomFill::RandomFill(unique_ptr<default_random_engine> random_engine,
                           unique_ptr<uniform_int_distribution<int>> int_distribution) {
        this->random_engine_ = move(random_engine);
        this->int_distribution_ = move(int_distribution);
    }


    int SquaredFill::Value(int index) const {
        return a_ * index * index + b_;
    }


}