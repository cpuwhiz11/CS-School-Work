//This is an example of an abstract class in c++

class savingsAcc {

public :

  savingAcc( double = 0 ) ;
  virtual double getbal() ;
  virtual void printBal() = 0 ; 

private :

  double bal ; 

}
