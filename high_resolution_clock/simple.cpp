#include <iostream>
#include <thread>
#include <chrono>

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = t2 - t1;
    std::cout << "Waited " << elapsed.count() << " ms\n";

    return 0;
}
