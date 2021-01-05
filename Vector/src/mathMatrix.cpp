#include "mathMatrix.h"

double & mathMatrix::at(int i, int j) const {
  return _content[(i-1) * _column + (j-1)];//[row][column];
}

mathVector mathMatrix::row(int input) const {
  return mathVector(_content + (input-1)*_column, _column);
}

mathVector mathMatrix::column(int input) const {
  mathVector r(_row);
  for(int i=1;i<=_row;i++){
    r.component(i-1) = _content[(i-1) * _column + input - 1];
  }
  return r;
}

mathMatrix mathMatrix::operator * (mathMatrix const & input) {
  mathMatrix result = mathMatrix(this->_row, input._column);
  for(int i=1;i<=_row;i++){
    for(int j=1;j<=input._column;j++){
      result.at(i, j) = dot(row(i), input.column(j));
    }
  }
  return result;
}