//
// Created by mk on 20.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H

#include <vector>
#include "../../lab6/academia/StudentRepository.h"

namespace academia {
    class Student;

    class Query {
    public:
        virtual bool Accept(const Student &student) const = 0;

        virtual ~Query() {};
    };

    class ByFirstName : public Query {
    public:
        ByFirstName(std::string firstName) : firstName_{firstName} {}

        bool Accept(const Student &student) const override;

        ~ByFirstName() {}

    private:
        std::string firstName_;
    };

    class ByLastName : public Query {
    public:
        ByLastName(std::string lastName) : lastName_{lastName} {}

        bool Accept(const Student &student) const override;

        ~ByLastName() {}

    private:
        std::string lastName_;
    };

    class ByOneOfPrograms : public Query {
    public:
        bool Accept(const Student &student) const override;

        ByOneOfPrograms(std::initializer_list<std::string> programs) : programs_{programs} {}

        ~ByOneOfPrograms() {}

    private:
        std::vector<std::string> programs_;
    };

    class ByYearLowerOrEqualTo : public Query {
    public:
        bool Accept(const Student &student) const override;

        ByYearLowerOrEqualTo(int year) : year_{year} {}

        ByYearLowerOrEqualTo() {}

    private:
        int year_;
    };

    class OrQuery : public Query {
    public:
        bool Accept(const Student &student) const override;

        OrQuery(std::unique_ptr<Query> first, std::unique_ptr<Query> second);

    private:
        std::unique_ptr<Query> fst;
        std::unique_ptr<Query> snd;
    };

    class AndQuery : public Query {
    public:
        bool Accept(const Student &student) const override;

        AndQuery(std::unique_ptr<Query> first, std::unique_ptr<Query> second);

    private:
        std::unique_ptr<Query> fst;
        std::unique_ptr<Query> snd;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
