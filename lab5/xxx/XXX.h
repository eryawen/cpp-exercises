//
// Created by mk on 30.03.2017.
//

#include <string>
#include <cstring>
#include <algorithm>

using ::std::swap;

class XXX {
public:
    XXX();

    XXX(int param);

    XXX(const std::string name);

    XXX(const XXX &xxx);

    XXX(XXX &&xxx);

    XXX &operator=(const XXX &xxx);

    XXX &operator=(XXX &&xxx);

    ~XXX();

private:
    char *name_;
};

