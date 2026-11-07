#include <windows.h>
#include <iostream>
#include <string>

#include "injector.h"
#include "process.h"

int main() {
    SetConsoleTitle("Fortnite Cheat Loader");
    std::cout << "module (dll): ";
    std::string module;
    std::getline(std::cin, module);

    DWORD pid = Process::WaitFor("FortniteClient-Win64-Shipping.exe");
    if (!pid) {
        std::cout << "[-] process not found" << std::endl;
        return 1;
    }

    if (Injector::Inject(pid, module)) {
        std::cout << "[+] injected, press INSERT in game" << std::endl;
    } else {
        std::cout << "[-] injection failed" << std::endl;
        return 1;
    }

    std::cin.get();
    return 0;
}
