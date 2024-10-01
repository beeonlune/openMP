#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 4;
    int num_iterations = 65;
    int chunk_size[] = {1, 2};

    omp_set_num_threads(num_threads);

    printf("Static:\n");
    #pragma omp parallel for schedule(static, chunk_size[0])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");

    #pragma omp parallel for schedule(static, chunk_size[1])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");


    printf("Dynamic:\n");
    #pragma omp parallel for schedule(dynamic, chunk_size[0])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");

    #pragma omp parallel for schedule(dynamic, chunk_size[1])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");

    printf("Guided:\n");
    #pragma omp parallel for schedule(guided, chunk_size[0])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");

    #pragma omp parallel for schedule(guided, chunk_size[1])
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\n");

    printf("Default:\n");
    #pragma omp parallel for
    for (int i = 0; i < num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
    }

    return 0;
}
