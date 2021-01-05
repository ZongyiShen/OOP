#ifndef MATRIX
#define MATRIX
#include "vector.h"
#include "dot.h"

class mathMatrix{
   private:
     int _row;
     int _column;
     double *_content;
   public:
     mathMatrix(double *a[], int row, int column){
       this->_row = row;
       this->_column = column;

       _content = new double [row * column];
       for(int i = 0; i < row; i++){
         for(int j = 0; j < column; j++){
           _content[i * column + j] = a[i][j];
         }
       }
     }

     mathMatrix(int row, int column){
       this->_row = row;
       this->_column = column;
       _content = new double [row * column];
       for(int i = 0; i < row * column; i++){
         _content[i] = 0.0;
       }

     }

     ~mathMatrix(){
       if(_content != NULL){
         delete [] _content;
       }
     }

     double & at(int i, int j) const ;
     mathVector row(int input) const ;
     mathVector column(int input) const ;
     mathMatrix operator * (mathMatrix const & input) ;

};








#endif
