#include "bys.hpp"
#include "linalg.hpp"

using namespace bys;
int main() {
    Matrix<int> mat(2, 2);
    mat[0][0] = 1;
    print(mat[0][0]);

    return 0;
}
