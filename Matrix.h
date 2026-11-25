#pragma once
#include <iostream>

class Matrix
{
    class Data_Block
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
    
    Data_Block* block;
    bool isSizeValid(int rows, int columns) const; 

    public:
        Matrix(int rows, int columns, double value = 0);
        Matrix(const Matrix& m);
        ~Matrix();
};