#pragma once
#include <iostream>

class Matrix
{
    class Data_Block;
    class Proxy;
    
    Data_Block* block;
    static bool isSizeValid(int rows, int columns); 
    void release();

    public:
        Matrix(int rows, int columns, double value = 0);
        Matrix(const Matrix& m);
        ~Matrix();
        Matrix& operator=(const Matrix& m);
        Proxy operator()(int row, int column);
        double read(int row, int column) const;
        void write(int row, int column, double value);
};

class Matrix::Data_Block
{
    public:
        double **data;
        int rows;
        int columns;
        int refcount;

        Data_Block(int rows, int columns, double value);
        ~Data_Block();
    private:
        Data_Block(const Data_Block& d);
        Data_Block& operator=(const Data_Block& d);
};

class Matrix::Proxy
{
    friend class Matrix;

    Matrix& m;

    int row, column;
    double value;
    Proxy();
    ~Proxy();
};