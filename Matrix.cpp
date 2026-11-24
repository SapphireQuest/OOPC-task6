#include "Matrix.h" 
#include <iostream>

Matrix::Data_Block::Data_Block(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    data = new double*[rows*columns];
}       