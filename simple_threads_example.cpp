/*
тз:
1. создать 3 потока по примеру с пары
-1) 1 и 2 потоки запускаются одновременно
-2) а третий запускается сразу после окончания работы 1-го потока
*/
#include <iostream>
#include <thread>
#include <chrono>

void some_func() {
    for (int i = 0; i < 10; i++) {
        std::cout << "id потока: " << std::this_thread::get_id() << "   Номер итерации в потоке: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main(){
    setlocale(0, "ru");
    std::thread thread1(some_func);
    std::thread thread2(some_func);
    thread1.join();
    std::thread thread3(some_func);
    thread2.join();
    thread3.join();
    return 0;
}
