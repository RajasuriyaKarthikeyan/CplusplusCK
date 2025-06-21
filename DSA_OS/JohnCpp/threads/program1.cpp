#include <iostream>
#include <thread>

void hello(){
    std::cout << "Hello program function" << std::endl;
}

int main()
{
    std::thread t(hello);
    t.join();
    return 0;
}