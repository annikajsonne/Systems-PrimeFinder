#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <math.h>
void runner(int threads, int* count, int min,int max);
int main() {
  int numThreads = 4;
  //pthread_t ths[numThreads];
  int min = 1000;
  int max = 1000000;
  //storing each thread's count in an array
  int* count = (int*)malloc(numThreads * sizeof(int));
  std::thread* ths[numThreads];
  for (int i = 0; i < numThreads; i++) {
    int start = (((max-min)/numThreads)*i)+min;
    int stop = (((max-min)/numThreads)*(i+1)+min);
    std::thread* th = new std::thread(runner, i, count, start, stop);
    ths[i] = th;
  }
  for (int i = 0; i<numThreads; i++) {
    ths[i]->join();
  }
  int nums = 0;
  for (int i = 0; i < numThreads; i++){
    nums += count[i];
  }
  std::cout << "Number of prime numbers: " << nums << "\n";
}
void runner(int threads, int* count, int min, int max) {
  //finding count of prime numbers
  count[threads] = 0;
  int temp = 0;
  for (int i = min; i <= max; i++) {
    temp = 0;
    int t = 0;
    for(int j = 2; j <= i/2 && t != 1; j++) {
      if(i%j == 0){
        temp = 1;
	t = 1;
      }
    }
    if(temp == 0 && i >= 2) {
      count[threads]++;
    }
  }
}
