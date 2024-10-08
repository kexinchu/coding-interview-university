#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }X
    return true;
}

// Worker function that prints prime numbers
void print_primes(int limit) {
    for (int num = 2; num <= limit; ++num) {
        if (is_prime(num)) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    int limit;
    try {
        limit = std::stoi(argv[1]);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Please enter a valid integer." << std::endl;
        return 1;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Number out of range." << std::endl;
        return 1;
    }

    // Create a thread to print prime numbers
    std::thread prime_thread(print_primes, limit);
    prime_thread.join(); // Wait for the thread to finish

    return 0;
}