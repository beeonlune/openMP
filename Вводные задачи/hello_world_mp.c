#include <stdio.h>
#include <omp.h>

int main() {
  // Получаем количество доступных потоков
  int num_threads = omp_get_num_threads();

  #pragma omp parallel
  {
    // Получаем номер текущего потока
    int thread_id = omp_get_thread_num();

    printf("Поток %d: Hello World!\n", thread_id);
  }

  return 0;
}
