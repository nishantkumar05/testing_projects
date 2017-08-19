//g++ inputOperator
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  using namespace std;
  vector<uint32_t> v = {10, 5, 2, 19, 1, 15, 16, 25};

  cout << "Vector =>";
  for(auto c : v) {
    cout << c << ",";
  }
  cout << endl; 

  cout << "Vector (iterators class)=>";
  for( vector<uint32_t>::iterator t = v.begin(); t != v.end() ; t++ ) {
    cout << *t << ","; 
  }
  cout << endl; 
  return 0;
}

/*
  How would iterator work roughly?

  template<typename _tp>
  class vector
  {
    public:
    typedef __iterator<_tp> iterator;
    iterator<any> begin();
    iterator<any> end();
  }


  template<typename t>
  class __iterator 
  {
   A(); ~A();
   t operator*() {  }
  };

*/
