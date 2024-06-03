#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void *cek_prima(void *arg) {
    int num = *((int *)arg);
    if (is_prime(num)) {
        printf("%d prima\n", num);
    } else {
        printf("%d bukan prima\n", num);
    }
    pthread_exit(NULL);
}

int main() {
    int nums[] = {12, 43, 49};
    int num_threads = sizeof(nums) / sizeof(nums[0]);
    
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, cek_prima, (void *)&nums[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
