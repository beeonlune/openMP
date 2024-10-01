#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  int N = atoi(argv[1]);
  double sum = 0.0;

  #pragma omp parallel reduction(+:sum)
  {
    int thread_id = omp_get_thread_num();
    int num_threads = omp_get_num_threads();

    // Вычисляем часть суммы для каждого потока
    for (int i = thread_id + 1; i <= N; i += num_threads) {
      sum += 1.0 / i;
    }
  }

  printf("Sum (from 1 to %d) 1/n = %.10f\n", N, sum);

  return 0;
}
