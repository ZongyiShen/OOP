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
     mathMatrix(double a[][3], int row, int column){
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

     double & at(int i, int j) const {
       return _content[(i-1) * _column + (j-1)];//[row][column];
     }

     mathVector row(int input) const {
       return mathVector(_content + (input-1)*_column, _column);
     }

     mathVector column(int input) const {
       mathVector r(_row);
       for(int i=1;i<=_row;i++){
         r.component(i-1) = _content[(i-1) * _column + input - 1];
       }
       return r;
     }

     mathMatrix operator * (mathMatrix const & input) {
       mathMatrix result = mathMatrix(this->_row, input._column);
       for(int i=1;i<=_row;i++){
         for(int j=1;j<=input._column;j++){
           result.at(i, j) = dot(row(i), input.column(j));
         }
       }
       return result;
     }
};
#endif
