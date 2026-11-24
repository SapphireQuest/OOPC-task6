#include "Matrix.h" 
#include <iostream>

Matrix::Data_Block::Data_Block(int rows, int columns)
{
    refcount = 1;
    this->rows = rows;
    this->columns = columns;
    data = new double*[rows];
    data[0] = new double[rows*columns];

    for(int i = 1; i < rows; i++)
    {
        data[i] = data[i-1] + columns;
    }
}       

Matrix::Data_Block::~Data_Block()
{
    delete[] data[0];
    delete[] data;
}