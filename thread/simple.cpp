#include <iostream>
#include <thread>


void handler()
{
    std::cout << "hello world\n";
}

void handler2(int arg1, int arg2)
{
    std::cout << "arg1 = " << arg1 << ", arg2 = " << arg2 << std::endl;
}

int main() 
{
  std::thread t1(handler), t2(handler2, 1, 2);
  t1.join();
  t2.join();

  return 0;
}
