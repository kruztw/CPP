#include <iostream>
#include <chrono>
#include <thread>

int main()
{
  printf("wait a second ...\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));
}
