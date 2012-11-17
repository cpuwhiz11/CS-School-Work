//This is an example of an interface file in c++ 


class ticket {

public :

  virtual ticket() ;
  virtual void buy( int ) = 0 ;
  virtual void sell( int ) = 0 ;
  virtual string get_info() = 0 ;

}
