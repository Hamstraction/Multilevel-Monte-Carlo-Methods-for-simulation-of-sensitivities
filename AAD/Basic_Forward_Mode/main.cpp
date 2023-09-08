#include <iostream>
#include "dual.h"

//
//Example of forward mode automatic differenciation
//

#include <mpi.h>
int main(){
  MPI_Init(NULL, NULL);
	
  //derivative=1 tells which variable to diff wrt
  Dual x(5, 1);
  Dual y(6);

  //fuction example
  Dual f = pow(x,2)*y;

  //derivative of f wrt x at pt (5,6)
  std::cout << f.getDerivative() << std::endl;

  MPI_Finalize();
}
