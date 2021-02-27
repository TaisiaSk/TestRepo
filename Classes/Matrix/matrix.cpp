#include <iostream>
#include "matrix.h"

void matrixToTriangle(size_t const size, double** arr)
{
    double koificient;
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i][i] == 0)
            for (size_t l = 0; l < size; ++l)
                if (arr[l][i] != 0)
                    for (size_t k = 0; k < size; ++k)
                        arr[i][k] += arr[l][k];

        for (size_t j = i + 1; j < size; j++)
        {
            koificient = -arr[j][i] / arr[i][i];
            for (size_t k = i; k < size; ++k)
                arr[j][k] += arr[i][k] * koificient;
        }
    }
}

inline void Matrix::checkIdx(size_t const Rows, size_t const Cols)const
{
    if ((Rows >= _rows) || (Cols >= _cols))
        throw "Out of bounds!\n";
}

void Matrix::changeValue(size_t const Row, size_t const Col, double kVal)
{
    checkIdx(Row, Col);
    _data[Row][Col] = kVal;
}

double Matrix::getValue(size_t const Row, size_t const Col)const
{
    checkIdx(Row, Col);
    return _data[Row][Col];
}

void Matrix::Print()const
{
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
            std::cout << _data[i][j] << '\t';
        std::cout << '\n';
    }
}

double Matrix::Norm()const
{
    double norm = 0;
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            norm += _data[i][j] * _data[i][j];
    return sqrt(norm);
}

Matrix Matrix::transposed()const
{
    Matrix trans(_cols, _rows);
    for (size_t i = 0; i < _cols; ++i)
        for (size_t j = 0; j < _rows; ++j)
            trans._data[i][j] = _data[j][i];
    return trans;
}

void Matrix::FillRandom(const int Lb, const int Ub)
{
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            _data[i][j] = rand() % (Ub - Lb + 1) + Lb;
}

double Matrix::det() const
{
    if (_rows != _cols)
        throw "Matrix must be square\n";

    Matrix tmp(*this);
    matrixToTriangle(_rows, tmp._data);
    double det = 1;
    for (size_t i = 0; i < _rows; ++i)
        det *= tmp._data[i][i];
    return det;
}