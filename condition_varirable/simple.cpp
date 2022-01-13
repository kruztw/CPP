#include <iostream>
#include <condition_variable>
#include <thread>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

constexpr int thread_num = 3;

condition_variable cv;
mutex cv_m;

std::vector<bool> oks(thread_num);
 
void handler(const int tid)
{
    unique_lock<mutex> lk(cv_m);
    cerr << tid << ": Waiting\n";
    cv.wait(lk, [&]{return oks[tid];});   // wait for notification and return value must be true, or it will keep locking
    cerr << tid << ": ok\n";
}
 
void signals()
{

    std::this_thread::sleep_for(1s);
    for (int i = 0; i < thread_num; ++i)
        oks[i] = true;

    {
        oks[1] = false;
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notifying...\n";
        cv.notify_all();
    }

    {
        std::this_thread::sleep_for(1s);
        oks[1] = true;
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notify again ...\n";
        cv.notify_one(); // notify_all also works
    }
}
 
int main()
{
    std::thread t1(handler, 0), t2(handler, 1), t3(handler, 2), t4(signals);
    t1.join(); 
    t2.join(); 
    t3.join();
    t4.join();
}
