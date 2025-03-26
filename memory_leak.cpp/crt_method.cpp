#include <iostream>
#include <crtdbg.h>  // CRT Debugging Library

#define _CRTDBG_MAP_ALLOC  // Enables memory leak tracking

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Enable leak checking

    int* a = new int(42);  // Memory allocated but NOT deleted (intentional leak)
    int* b = new int[5];   // Memory allocated but NOT deleted (intentional leak)

    // Uncomment to fix leaks
    // delete a;
    // delete[] b;

    _CrtDumpMemoryLeaks(); // Dumps memory leak report at the end

    return 0;
}