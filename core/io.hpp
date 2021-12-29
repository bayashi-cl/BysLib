#pragma once
#include "core/stdlib.hpp"

namespace bys {
// pair
template <class T, class U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
    return is >> p.first >> p.second;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    return os << p.first << " " << p.second;
}

// STL container
struct is_container_impl {
    template <typename T>
    static auto check(T&& obj) -> decltype(obj.begin(), obj.end(), std::true_type{});
    template <typename T>
    static auto check(...) -> std::false_type;
};
template <typename T>
class is_container : public decltype(is_container_impl::check<T>(std::declval<T>())) {};

template <typename C, typename std::enable_if<is_container<C>::value && !std::is_same<C, std::string>::value &&
                                                  !std::is_same<C, std::wstring>::value,
                                              std::nullptr_t>::type = nullptr>
std::ostream& operator<<(std::ostream& os, const C& container) noexcept {
    if (container.empty()) return os;
    std::for_each(std::begin(container), std::prev(std::end(container)), [&](auto e) { os << e << ' '; });
    return os << *std::prev(std::end(container));
}

template <typename C, typename std::enable_if<is_container<C>::value && !std::is_same<C, std::string>::value &&
                                                  !std::is_same<C, std::wstring>::value,
                                              std::nullptr_t>::type = nullptr>
std::istream& operator>>(std::istream& is, C& container) {
    std::for_each(std::begin(container), std::end(container), [&](auto&& e) { is >> e; });
    return is;
}

// I/O helper
template <class T>
inline T input() {
    T n;
    cin >> n;
    return n;
}
template <class T>
inline vector<T> input(int n) {
    vector<T> res(n);
    cin >> res;
    return res;
}
template <class T>
inline vector<vector<T>> input(int n, int m) {
    vector res(n, vector<T>(m));
    cin >> res;
    return res;
}
template <class T, size_t N>
inline std::array<T, N> input() {
    std::array<T, N> res;
    cin >> res;
    return res;
}
template <class S, class T, class... Us>
std::tuple<S, T, Us...> input() {
    std::tuple<S, T, Us...> res;
    std::apply([](auto&... e) { (cin >> ... >> e); }, res);
    return res;
}
template <class... Ts>
void cinto(Ts&... args) {
    (cin >> ... >> args);
}

struct Print {
    std::ostream& os;
    string sep = " ", end = "\n";
    Print(std::ostream& os) : os(os) {}
    ~Print() { os << std::flush; }
    void operator()() { os << end; }
    template <class T>
    void operator()(const T& a) {
        os << a << end;
    }
    template <class T, class... Ts>
    void operator()(const T& a, const Ts&... b) {
        os << a;
        (os << ... << (os << sep, b));
        os << end;
    }
    template <class... Ts>
    void send(const Ts&... a) {
        operator()(a...);
        os << std::flush;
    }
} print(std::cout), debug(std::cerr);

inline void fastio() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(11);
    std::cerr << std::boolalpha;
}
}  // namespace bys
