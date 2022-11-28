#pragma once
#include "../core/int_alias.hpp"
#include "printer.hpp"
#include "scanner.hpp"

/**
 * @file io.hpp
 * @brief I/O
 */
namespace bys {
template <class... Args> std::string debugfmt(i32 line, Args&&... args) {
    std::stringstream ss;
    Printer printer(ss);
    ss << "📌 line" << std::setw(4) << line << ": ";
    printer.set_sep("\n             ", " ", " ");
    printer.print(std::forward<Args>(args)...);
    return ss.str();
}

Printer print(std::cout), debug(std::cerr);
Scanner scanner(std::cin);

#ifdef LOCAL
//! @brief デバッグ用出力 ジャッジ上では何もしない。
#define DEBUG(...)                                  \
    {                                               \
        debug.cat(debugfmt(__LINE__, __VA_ARGS__)); \
        debug.flush()                               \
    }
#else
#define DEBUG(...)
#endif
#define DEBUGCASE(casenum, ...) \
    if (TESTCASE == casenum) DEBUG(__VA_ARGS__)
//! @brief printしてreturnする。
#define EXIT(...)           \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
}  // namespace bys
