#include <iostream>
#include <unordered_map>
#include <cstdlib>  // For malloc & free
#include <new>      // For std::bad_alloc

struct Allocation {
    size_t size;
    const char* file;
    int line;
};

std::unordered_map<void*, Allocation> allocMap;

// Logs allocation with file & line number
void logAllocation(void* ptr, size_t size, const char* file, int line) {
    allocMap[ptr] = { size, file, line };
}

// Removes entry from allocation map
void logDeallocation(void* ptr) {
    allocMap.erase(ptr);
}

// Checks for leaks
void checkLeaks() {
    if (allocMap.empty()) {
        std::cout << "✅ No memory leaks detected!\n";
        return;
    }
    std::cerr << "⚠️ MEMORY LEAKS DETECTED:\n";
    for (const auto& entry : allocMap) {
        std::cerr << "  → Leak: " << entry.second.size << " bytes at "
            << entry.second.file << ":" << entry.second.line
            << " (" << entry.first << ")\n";
    }
}

// Overloaded new operators
void* operator new(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (!ptr) throw std::bad_alloc();
    logAllocation(ptr, size, file, line);
    return ptr;
}

void* operator new[](size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (!ptr) throw std::bad_alloc();
    logAllocation(ptr, size, file, line);
    return ptr;
}

// Overloaded delete operators
void operator delete(void* ptr) noexcept {
    if (ptr) {
        logDeallocation(ptr);
        free(ptr);
    }
}

void operator delete[](void* ptr) noexcept {
    if (ptr) {
        logDeallocation(ptr);
        free(ptr);
    }
}

// Macro for tracking allocations
#define new new(__FILE__, __LINE__)

int main() {
    int* p1 = new int(10);      // Leak (not deleted)
    int* p2 = new int(20);      // Properly deleted
    int* arr = new int[5];      // Leak (not deleted)

    delete p2;                  // Correct deletion

    checkLeaks(); // Reports leaks

    return 0;
}
