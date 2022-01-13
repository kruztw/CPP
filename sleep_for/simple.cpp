#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals; // ns us ms s min...

int main()
{
  printf("wait a second ...\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));

  printf("wait a second again ...\n");
  std::this_thread::sleep_for(1s);
}
