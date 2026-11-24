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

            Data_Block(int rows, int columns);

            ~Data_Block();
        private:
            Data_Block(const Data_Block& d);
            Data_Block& operator=(const Data_Block& d);

    };
    
    Data_Block* block;
    
    public:
        Matrix(int rows, int columns);
        ~Matrix();


};