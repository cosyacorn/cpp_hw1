#include<iostream>
using namespace std;
#include "matrix.h"

int main(int argc, char* argv[]){

  if(argc!=3){
    cout << "Correct usage " << argv[0] << " #rows #cols"<< endl;
    return 1;
  }else{
    int rows, cols;

    srand48(time(NULL));
    rows=atoi(argv[1]);
    cols=atoi(argv[2]);
    
    Matrix mc2(rows, cols);
    mc2.printout();

    return 0;
  }
}
