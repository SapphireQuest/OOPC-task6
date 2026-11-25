#include "Matrix.h" 
#include <iostream>

Matrix::Data_Block::Data_Block(int rows, int columns, double value)
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

    //TODO writing value into block 
}       

Matrix::Data_Block::~Data_Block()
{
    delete[] data[0];
    delete[] data;
}

Matrix::Matrix(int rows, int columns, double value)
{
    if(!isSizeValid(rows, columns))
    {
        //TODO throw error
    }
    block = new Data_Block(rows, columns, value);
}

Matrix::~Matrix()
{
    
    delete block;
}

bool Matrix::isSizeValid(int rows, int columns) const
{
    return rows > 0 && columns > 0;
}


Matrix::Matrix(const Matrix& m)
{
    m.block->refcount ++;
    this->block = m.block;
}
