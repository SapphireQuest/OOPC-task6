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

    for(int i = 0; i < rows*columns; i++)
    {
        data[0][i] = value;
    }
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
    this->release(); 
}

bool Matrix::isSizeValid(int rows, int columns) 
{
    return rows > 0 && columns > 0;
}


Matrix::Matrix(const Matrix& m)
{
    m.block->refcount++;
    this->block = m.block;
}

Matrix& Matrix::operator=(const Matrix& m)
{
    m.block->refcount++;
    this->release();
    this->block = m.block;
    return *this;
}

void Matrix::release()
{
    block->refcount--;
    if(block->refcount == 0)
    {
        delete block;
    }
}