#include <iostream>
#include <string>

int main() {
    const std::string appName = "hello-windows";
    std::cout << "Hello from " << appName << "!" << std::endl;
    std::cout << "If you can read this, the Windows GitHub Action built the executable successfully." << std::endl;
    return 0;
}
