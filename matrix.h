#ifndef matrix_h
#define matrix_h

class Matrix{
private:
  double** elem;
  int nrow, ncol;
public:
  Matrix(int row, int col){
    nrow=row;
    ncol=col;
    elem=new double*[nrow];
    for(int i=0; i<nrow; i++){
      elem[i]=new double[ncol];
      for(int j=0; j<ncol; j++){
	elem[i][j]=drand48();
      }
    }
  }

  ~Matrix()
    {
      for(int i=0; i<nrow; i++)
	delete elem[i];
      delete elem;
    }

  void printout(){
    for(int i=0; i<nrow; i++){
      for(int j=0; j<ncol; j++){
	cout << elem[i][j] << " ";
      }
      cout << endl;
    }
  }
};
#endif
