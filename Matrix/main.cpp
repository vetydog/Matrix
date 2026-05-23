#include "Matrix.h"

int main() {

    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A.randomFill(1, 5);
    B.randomFill(1, 5);

    cout << "Matrix A:\n";
    A.print();

    cout << "Matrix B:\n";
    B.print();

    Matrix<int> C = A + B;

    cout << "A + B:\n";
    C.print();

    cout << "Max in A: " << A.getMax() << endl;
    cout << "Min in A: " << A.getMin() << endl;

}