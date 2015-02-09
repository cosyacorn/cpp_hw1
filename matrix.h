#ifndef matrix_h
#define matrix_h
#include<iostream>

class Matrix{

private:
  double* elem;
  int n_row, n_col;

public:
 Matrix(int row, int col) : elem(new double[row*col]), n_row(row), n_col(col){
    for (int i=0;i<row*col;i++){
      elem[i]=0;
    }
  }

  ~Matrix()
    {
      delete[] elem;
    }


  //not needed but was useful when wirting the program for checking things
  void printout(){
    for(int i=0; i<n_row*n_col; i++){
      std::cout << elem[i] << " ";
      if((i+1)%n_col==0)
	std::cout << std::endl;
    }
  }
  double& operator() (int i, int j);
  const double& operator() (int i, int j) const;
  int nrow() const;
  int ncol() const;
  Matrix& operator*=(double d);
};

void multiply(const Matrix& A, const Matrix& B, Matrix& C);
void add(const Matrix& A, const Matrix& B, Matrix& C);
std::ostream& operator << (std::ostream& strm, const Matrix& mat);
std::istream& operator >> (std::istream& strm, Matrix& mat);
bool operator != (const Matrix& A, const Matrix& B);
bool operator == (const Matrix& A, const Matrix& B);

#endif
