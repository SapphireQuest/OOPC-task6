#pragma once
#include <iostream>

class Matrix
{
    class Data_Block
    {
        private:
            double **data;
            int rows;
            int columns;
        public: 
            Data_Block(int rows, int columns);   
            ~Data_Block();
    };
    
    Data_Block* block;
    
    public:
        Matrix();


};