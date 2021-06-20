// https://zhuanlan.zhihu.com/p/227924915

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <thread>
#include <chrono>

using namespace std;

void AlarmHandler(int signum)
{
  cout << "Got a alarm signal" << std::endl;
}

void TestAlarm()
{
  struct sigaction sig;
  sig.sa_handler = AlarmHandler;
  sig.sa_flags = 0;
  sigemptyset(&sig.sa_mask);

  struct sigaction old;
  sigaction(SIGALRM, &sig, &old);                                            // old 會被寫入之前的 sigaction
  cout << "A SIGALRM handler has registered" << endl;

  alarm(3);
  pause();

  cout << "Raise another alarm signal, in 2 second later" << endl;
  alarm(2);

  cout << "Start sleep 10s ..." << endl;
  sleep(10);
  //std::this_thread::sleep_for(std::chrono::seconds(10));                    // 扎扎實實睡 10s , sighandler 仍然會執行, 執行完會繼續睡

  cout << "Exit sleep 10s ..." << endl;
  cout << "Exit..." << endl;

  sigaction(SIGALRM, &old, NULL);                                             // 復原
}

int main(int argc, char* argv[])
{
  TestAlarm();
  return 0;
}
