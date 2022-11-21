#pragma once
#include <limits>
#include <memory>
#include <type_traits>

namespace bys {
template <class T>
class BinaryTrie {
    static_assert(std::is_integral_v<T>, "T is not integral");
    static constexpr int B = std::numeric_limits<T>::digits;

    struct Node;
    using Ptr = std::shared_ptr<Node>;

    struct Node {
        Ptr left, right;
        int count = 0;
    };

    Ptr root;

    Ptr add(Ptr now, T val, int b) {
        if (not now) now = std::make_shared<Node>();
        now->count += 1;
        if (b >= 0) {
            if ((val >> b) & (T)1) {
                now->left = add(now->left, val, b - 1);
            } else {
                now->right = add(now->right, val, b - 1);
            }
        }
        return now;
    }

    Ptr sub(Ptr now, T val, int b) {
        if (not now) return nullptr;
        now->count -= 1;
        if (now->count == 0) return nullptr;
        if (b >= 0) {
            if ((val >> b) & (T)1) {
                now->left = sub(now->left, val, b - 1);
            } else {
                now->right = sub(now->right, val, b - 1);
            }
        }
        return now;
    }

   public:
    BinaryTrie() {}
    void insert(T x) { root = add(root, x, B - 1); }
    auto erase(T x) { root = sub(root, x, B - 1); }

    // auto bisect_left();
    // auto bisect_right();

    bool contain(T val) const {
        if (not root) return false;

        Ptr now = root;
        for (int i = B - 1; i >= 0; --i) {
            now = (val >> i) & (T)1 ? now->left : now->right;
            if (not now) return false;
        }
        return true;
    }
    int count(T val) const {
        if (not root) return 0;

        Ptr now = root;
        for (int i = B - 1; i >= 0; --i) {
            now = (val >> i) & (T)1 ? now->left : now->right;
            if (not now) return 0;
        }
        return now->count;
    }
    std::size_t size() const noexcept { return root ? root->count : 0; }
    // auto operator[]();
};
}  // namespace bys
