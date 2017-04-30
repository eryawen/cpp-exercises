//
// Created by mk on 20.04.2017.
//

#ifndef JIMP_EXERCISES_FILLER_H
#define JIMP_EXERCISES_FILLER_H

#include <vector>
#include <random>
#include <memory>

using ::std::unique_ptr;
using ::std::default_random_engine;
using ::std::uniform_int_distribution;

namespace arrays {

    class Filler {
    public:
        virtual int Value(int index) const = 0;

        Filler() {};
    };


    class UniformFill : public Filler {
    public:
        UniformFill(int value = 0) : value_{value} {}

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public Filler {
    public:
        IncrementalFill(int start, int step = 1) : start_{start}, step_{step} {}

        int Value(int index) const override;

    private:
        int start_;
        int step_;
    };

    class RandomFill : public Filler {
        RandomFill() {};

        int Value(int index) const override;

    public:
        RandomFill(unique_ptr<default_random_engine> random_engine,
                   unique_ptr<uniform_int_distribution<int>> int_distribution);

    private:
        unique_ptr<default_random_engine> random_engine_;
        unique_ptr<uniform_int_distribution<int>> int_distribution_;
    };


    class SquaredFill : public Filler {
    public:
        SquaredFill(int a = 1, int b = 0) : a_{a}, b_{b} {}

        int Value(int index) const override;

    private:
        int a_;
        int b_;
    };

}
#endif //JIMP_EXERCISES_FILLER_H

/*
 *
 * jednorone (zawsze ta sama wartość), z wartością domyślną 0
z inkrementacją (uwzględniająca wartość początkową start i krok step, który ma wartość domyślną 1)
za pomocą generatora liczb losowych
z kwadratem indeksu (a*index^2+b), zarówno a i b mogą przyjąć domyślne wartości
 *
 */