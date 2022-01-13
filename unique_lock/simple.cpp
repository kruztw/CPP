#include <iostream>        
#include <thread>          
#include <mutex>           

using namespace std;

mutex mtx;

void print_block (int n, char c)
{
  unique_lock<mutex> lck(mtx);
  for (int i = 0; i < n; ++i)
    cout << c;
 
  cout << '\n';
}

int main ()
{
  thread t1(print_block, 50, '*');
  thread t2(print_block, 50, '$');

  t1.join();
  t2.join();

  return 0;
}
