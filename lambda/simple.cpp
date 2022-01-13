#include <iostream>

using namespace std;

int main()
{
  // auto var = [outside var](parameter) { expression };  

  int a = 1, b = 2;
  auto foo1 = [&a, &b]() { cout << "a + b = " << a + b << endl; };  // pass by reference
  auto foo2 = [a, b]() { cout << "a + b = " << a + b << endl; };    // pass by value
  auto foo3 = [&]() { cout << "a + b = " << a + b << endl; };       // pass by reference
  
  auto foo4 = [](int a, int b) { cout << "a + b = " << a + b << endl; };

  foo1();
  foo2();
  foo3();
  foo4(10, 20);
}
