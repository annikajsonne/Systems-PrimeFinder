# C++ Prime Finder

*This program showcases a prime number finder, offering both single-threading and multi-threading functionalities.*

## Purpose
The primary objective of this program is to demonstrate the effectiveness of threading in accelerating prime number finding algorithms.

## Functionalities

1. **Prime Checking Function**:
   - Write a function to determine if a number is prime by checking divisibility.
2. **Finding Primes in a Range**:
   - Implement code to find primes in a given range and measure execution time.

## Threading

- **Threaded Implementation**:
  - Divide the prime range into blocks for multiple threads.
  - Each thread reports progress and results, aggregated by the main thread.
- **Results Verification**:
  - Ensure consistency between serial and threaded results.
  - Measure execution time for threaded version.
