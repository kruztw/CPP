#include <iostream>

using namespace std;

class MyClass
{
public:
  MyClass(int n): val(n) {}
  explicit MyClass(int a, int b): val(a+b) {}   // Now, implicit conversion doesn't work.  

  void printVal() const {
    cout << "val = " << val << endl;
  }


private:
  int val;
};

int main()
{
  // Implicit conversion
  MyClass obj1 = 1;
  obj1.printVal();

  // Explicit conversion
  MyClass obj2 = 2;
  obj2.printVal();


  // Not work
  // MyClass obj3 = {1, 2};
  // obj3.printVal();

  MyClass obj4(1, 3);
  obj4.printVal();
}
