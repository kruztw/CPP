#include <iostream>
#include <thread>


void handler()
{
    std::cout << "hello world\n";
}

int main() 
{
  std::thread t1(handler);
  t1.join();

  return 0;
}
