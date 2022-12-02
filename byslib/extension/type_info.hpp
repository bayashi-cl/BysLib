#pragma once
#include <cxxabi.h>

#include <string>
#include <typeinfo>

namespace bys {
template <class T> std::string get_typename(T const& v) {
    int status;
    return abi::__cxa_demangle(typeid(v).name(), 0, 0, &status);
}
}  // namespace bys
