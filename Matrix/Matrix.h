#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:

    Matrix(int r = 0, int c = 0) {
        rows = r;
        cols = c;

        data = new T * [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
    }

 
    ~Matrix() {
        delete[] data;
    }

    void clear() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;
        }
        data = nullptr;
        rows = cols = 0;
    }

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void randomFill(int minVal = 0, int maxVal = 10) {
        srand(time(0));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = minVal + rand() % (maxVal - minVal + 1);
    }


    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }


    T getMax() const {
        T mx = data[0][0];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] > mx)
                    mx = data[i][j];

        return mx;
    }

    T getMin() const {
        T mn = data[0][0];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] < mn)
                    mn = data[i][j];

        return mn;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];

        return result;
    }


    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;

                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }

        return result;
    }

    Matrix operator/(const Matrix& other) {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] / other.data[i][j];

        return result;
    }
};

