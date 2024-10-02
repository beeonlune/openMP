#include <stdio.h>
#include <omp.h>

int main() {
  #pragma omp parallel num_threads(2)
  {
    int thread_id_1 = omp_get_thread_num();
    int num_threads_1 = omp_get_num_threads();

    printf("Level 1, thread %d иof %d\n", thread_id_1, num_threads_1);

    #pragma omp parallel num_threads(2)
    {
      int thread_id_2 = omp_get_thread_num();
      int num_threads_2 = omp_get_num_threads();

      printf("  Level 2, thread %d of %d\n", thread_id_2, num_threads_2);

      #pragma omp parallel num_threads(2)
      {
        int thread_id_3 = omp_get_thread_num();
        int num_threads_3 = omp_get_num_threads();

        printf("    Level 3, thread %d of %d\n", thread_id_3, num_threads_3);
      }
    }
  }

  return 0;
}
