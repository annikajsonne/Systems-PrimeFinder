#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int num;
int numThreads;
int diff;
int isprime;
int* primeA;

void* prime(void* arg) {
  int n = *((int*)arg);
  int low = (n-1) * diff + 1; //calculating range for each thread. So, each thread operates over a splitted range of numbers.
  int high = n * diff;
  for(int i = low; i <= high; i++) {
    isprime = 0;
    for(int j = 2; j <= i/2 && (isprime != 1); j++) {
      if(i%j == 0) {
	isprime = 1; //not prime
	primeA[i] = 1;
      }
    }
  }
}
int main(int argc, char *argv[]) {
    num = atoi(argv[1]);
    numThreads = atoi(argv[2]);
    int arr[num];
    pthread_t threads[numThreads];
    primeA = (int*)malloc(num + 1 * sizeof(int));
    diff = num/numThreads;   //split the range of numbers for each thread
    int excess = num % numThreads;
    if(numThreads > num) {
      numThreads = excess;
    }
    int i;
    for(i = 0; i < numThreads; i++){
      arr[i] = i+1;
      pthread_create(&threads[i],NULL,&prime,&arr[i]);
    }
    for(int j = 0; j < numThreads; j++)
       pthread_join(threads[j],NULL);
    i = 2;
    while(i <= num) {
      if(primeA[i] != 1)
      i++;
    }
    printf("%d\n", i);
    free(primeA);
    return 0;
}
