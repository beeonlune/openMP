#include <stdio.h>
#include <omp.h>

int main() {
  int shared_var = 0;
  omp_lock_t semaphore; // Объявление семафора типа omp_lock_t
  omp_init_lock(&semaphore); 

  #pragma omp parallel num_threads(4)
  {
    int thread_id = omp_get_thread_num();

    omp_set_lock(&semaphore); // Блокировка семафора
    {
      shared_var++;
      printf("Поток %d: shared_var = %d\n", thread_id, shared_var);
    }
    omp_unset_lock(&semaphore); // Разблокировка семафора
  }

  omp_destroy_lock(&semaphore); // Очистка семафора

  return 0;
}
