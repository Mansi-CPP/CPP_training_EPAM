raw method
#include <iostream>

int allocationCount = 0;  // Global counter for memory allocations

// Overloading global new operator
void* operator new(std::size_t size) {
    allocationCount++;
    std::cout << "[ALLOC] Allocated " << size << " bytes. Total Allocations: " << allocationCount << "\n";
    return malloc(size);  // Use malloc to allocate raw memory
}

// Overloading global delete operator
void operator delete(void* ptr) noexcept {
    allocationCount--;
    std::cout << "[FREE] Memory Freed. Remaining Allocations: " << allocationCount << "\n";
    free(ptr);  // Free raw memory
}

// Function that creates and does not free memory (memory leak)
void createMemoryLeak() {
    int* leak1 = new int(10); // Leaked memory (never deleted)
    int* leak2 = new int[5];  // Leaked memory (never deleted)
}

// Function that properly allocates and deallocates memory
void createNoLeak() {
    int* safe1 = new int(20);
    int* safe2 = new int[5];

    delete safe1;    // Properly freeing memory
    delete[] safe2;  // Using delete[] for arrays
}

int main() {
    createMemoryLeak(); // This will cause a memory leak

    if (allocationCount > 0) {
        std::cout << "\n⚠️ Memory Leak Detected! " << allocationCount << " allocations not freed.\n";
    } else {
        std::cout << "\n✅ No Memory Leak Detected!\n";
    }

    // Now calling a function with proper memory management
    createNoLeak();

    if (allocationCount > 0) {
        std::cout << "\n⚠️ Memory Leak Still Present! " << allocationCount << " allocations not freed.\n";
    } else {
        std::cout << "\n✅ All Memory Freed Correctly!\n";
    }

    return 0;
}
