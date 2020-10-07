#pragma once

#include <exception>
#include <string>

#define EXCEPTOR(CLASSNAME, WHATSTR) \
    class CLASSNAME : public std::exception \
    { \
        const std::string str = WHATSTR; \
    public: \
        const char* what() const { return str.c_str(); } \
    }
