#include<iostream>
using namespace std;
#include "matrix.h"
#include<limits>
#include<cmath>

double& Matrix::operator() (int i, int j){
  return elem[i*n_col+j];
}

const double& Matrix::operator() (int i, int j) const{
  return elem[i*n_col+j];
}


int Matrix::nrow() const{
  return n_row;
}


int Matrix::ncol() const{
  return n_col;
}


Matrix& Matrix::operator*= (double d){
  for(int i=0;i<n_row*n_col;i++){
    elem[i]=d*elem[i];
  }
  return *this;
}


void multiply(const Matrix& A, const Matrix& B, Matrix& C){
  if(A.ncol()==B.nrow() && A.nrow()==C.nrow() && B.ncol()==C.ncol()){
    for(int i=0;i<A.nrow();i++){
      for(int j=0;j<B.ncol();j++){
	C(i,j)=0;
	for(int k=0;k<A.ncol();k++){
	  C(i,j)+=A(i,j)*B(i,j);
	}
      }
    }
  }else
    cout<< "number of columns in A must be same as number of rows in B. And C must have same number of rows as A, and columns as B" <<endl;
}


void add(const Matrix& A, const Matrix& B, Matrix& C){
  if(A.nrow()==B.nrow() && B.nrow()==C.nrow() && A.ncol()==B.ncol() && B.ncol()==C.ncol()){
    for(int i=0;i<A.nrow();i++){
      for(int j=0;j<A.ncol();j++){
	C(i,j)=A(i,j)+B(i,j);
      }
    }
  }
  else
    cout<<"Matrices must be of the same size for addition"<<endl;
}


std::ostream& operator << (std::ostream& strm, const Matrix& mat){
  for(int i=0;i<mat.nrow();i++){
    for(int j=0;j<mat.ncol();j++){
      strm << mat(i,j) << " ";
    }
    strm << endl;
  }
  return strm;
}


std::istream& operator >> (std::istream& strm, Matrix& mat){
 for(int i=0;i<mat.nrow();i++){
    for(int j=0;j<mat.ncol();j++){
      strm >> mat(i,j);
    }
 }
 return strm;
}


bool operator != (const Matrix&A, const Matrix& B){
  if(A.nrow()==B.nrow() && A.ncol()==B.ncol()){
    for(int i=0;i<A.nrow();i++){
      for(int j=0;j<B.ncol();j++){
	if(std::abs(A(i,j)-B(i,j))>(std::abs(std::min(A(i,j),B(i,j)))*std::numeric_limits <double>::epsilon()*20.0)){
	  return true;
	  break;
	}
      }
    }
  }
return false;
}


bool operator == (const Matrix& A, const Matrix& B){
  if(A!=B)
    return false;
  else
    return true;
}



int main(){

  Matrix A(2,2), B(2,2), C(2,2), D(2,2);

  cout<<"Enter entries for 2 by 2 matrix A" <<endl;

  cin >> A;
  //A.printout();

  cout<<"Enter entries for 2 by 2 matrix B" <<endl;

  cin >> B;


  if(A!=B){
    cout<<"A is not equal to B" <<endl;
  }

  if(A==B){
    cout<<"A is equal to B"<<endl;
  }


  cout << "The matrix A is:"<<endl;
  cout << A;
  cout << "The matrix B is:"<<endl;
  cout << B;


  multiply(A,B,C);
  cout<<"A multiplied by B is:"<<endl;

  cout << C;

  cout<<"A plus B is:"<<endl;
  add(A, B, D);

  cout << D;

  A*=2;

  cout<<"2*A is:"<<endl;
  cout << A;
  return 0;
 
}
