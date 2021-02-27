#include <iostream>

class Matrix
{
private:
    size_t _rows;
    size_t _cols;
    double** _data;

    inline void checkIdx(size_t const Rows,size_t const Cols)const
    {
        if ((Rows >= _rows) || (Cols >= _cols))
            throw "Out of bounds!\n";
    }


public:
    //Constructors
    Matrix() //default
    {
        _rows = 0;
        _cols = 0;
        _data = nullptr;
    }

    Matrix(size_t Rows, size_t Cols) //accepts sizes
    {
        _rows = Rows;
        _cols = Cols;
        _data = new double* [Rows];
        for (size_t idx = 0; idx < Rows; ++idx)
            _data[idx] = new double[Cols];
    }

    Matrix(size_t Rows, size_t Cols,double** arr) : Matrix(Rows, Cols) //accepts an array
    {
        for (size_t i = 0; i < Rows; ++i)
            for (size_t j = 0; j < Cols; ++j)
                _data[i][j] = arr[i][j];
    }

    Matrix(Matrix const& source) : Matrix(source._rows, source._cols, source._data) //copy
    {
        std::cout << "Copy!\n";
    }

    //Destructor
    ~Matrix()
    {
        for (size_t idx = 0; idx < _rows; ++idx)
            delete[] _data[idx];
        delete[] _data;
    }

    //getters
    size_t getRows() const { return _rows; }
    size_t getCols() const { return _cols; }


    //Methods
    void changeValue(size_t const Row, size_t const Col, double kVal)
    {
        checkIdx(Row, Col);
        _data[Row][Col] = kVal;
    }

    double getValue(size_t const Row, size_t const Col)const
    {
        checkIdx(Row, Col);
        return _data[Row][Col];
    }

    void Print()const
    {
        for (size_t i = 0; i < _rows; ++i)
        {
            for (size_t j = 0; j < _cols; ++j)
                std::cout << _data[i][j] << '\t';
            std::cout << '\n';
        }
    }

    double Norm()const
    {
        double norm = 0;
        for (size_t i = 0; i < _rows; ++i)
            for (size_t j = 0; j < _cols; ++j)
                norm += _data[i][j]*_data[i][j];
        return sqrt(norm);
    }

    Matrix transposed()const
    {
        Matrix trans(_cols, _rows);
        for (size_t i = 0; i < _cols; ++i)
            for (size_t j = 0; j < _rows; ++j)
                trans._data[i][j] = _data[j][i];
        return trans;
    }

    void FillRandom(const int Lb, const int Ub)
    {
        for (size_t i = 0; i <_rows; ++i)
            for (size_t j = 0; j < _cols; ++j)
                _data[i][j] = rand() % (Ub - Lb + 1) + Lb;
    }
};

//operators
inline std::ostream& operator<<(std::ostream& out, Matrix const& arr)
{
    for (size_t i = 0; i < arr.getRows(); ++i)
    {
        for (size_t j = 0; j < arr.getCols(); ++j)
            out << arr.getValue(i,j) << '\t';
        out << '\n';
    }
    return out;
}

inline std::istream& operator>>(std::istream& in, Matrix& arr) 
{
    double x;
    std::cout << "Input the array elements separated by a space: ";
    for (size_t i = 0; i < arr.getRows(); ++i)
        for (size_t j = 0; j < arr.getCols(); ++j)
        {
            in >> x;
            arr.changeValue(i, j, x);
        }
    return in;
}

inline Matrix operator+(Matrix const& a, Matrix const& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        throw "Matrices of different sizes\n";
    size_t rows = a.getRows();
    size_t cols = a.getCols();
        
    Matrix sum(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            sum.changeValue(i, j, a.getValue(i, j) + b.getValue(i, j));

    return sum;
}

inline Matrix operator-(Matrix const& a, Matrix const& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        throw "Matrices of different sizes\n";
    size_t rows = a.getRows();
    size_t cols = a.getCols();

    Matrix sub(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            sub.changeValue(i, j, a.getValue(i, j) - b.getValue(i, j));

    return sub;
}

inline Matrix operator*(Matrix const& a, Matrix const& b)
{
    if (a.getCols() != b.getRows())
        throw "Incorrect size of the matrices\n";
    size_t rows = a.getRows();
    size_t cols = b.getCols();
    size_t k = a.getCols();
    double element = 0;

    Matrix prod(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
        {
            for (size_t idx = 0; idx < k; ++idx)
                element += a.getValue(i, idx) * b.getValue(idx, j);

            prod.changeValue(i, j, element);
            element = 0;
        }

    return prod;
}

int main()
{
    size_t rows, cols;
    std::cout << "Input the number of rows ";
    std::cin >> rows;
    std::cout << "Input the number of columns ";
    std::cin >> cols;

    Matrix example(rows,cols);
    example.FillRandom(-50, 50);
    example.Print();
    std::cin >> example;
    std::cout << example;
    
    std::cout << example + example; 
    std::cout << example - example; 
    std::cout << example * example;

    /*std::cout << "Number of rows: " << example.getRows() << '\n';
    std::cout << "Number of columns: " << example.getCols() << '\n';

    std::cout << "Input row number ";
    std::cin >> rows;
    std::cout << "Input column number ";
    std::cin >> cols;
    std::cout << "Your element: " << example.getValue(rows,cols) << '\n';

    std::cout << "The norm of the matrix: " << example.Norm() << '\n';

    example.transposed().Print();*/

    system("pause");
    return 0;
}