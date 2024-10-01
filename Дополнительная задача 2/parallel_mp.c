#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        int level1_thread_num = omp_get_thread_num();
        int level1_num_threads = omp_get_num_threads();

        printf("Level 1: Thread %d of %d\n", level1_thread_num, level1_num_threads);

        #pragma omp parallel num_threads(2)
        {
            int level2_thread_num = omp_get_thread_num();
            int level2_num_threads = omp_get_num_threads();

            printf("Level 2: Thread %d of %d (ancestor thread %d of %d)\n",
                   level2_thread_num, level2_num_threads,
                   omp_get_ancestor_thread_num(1), omp_get_team_size(1));

            #pragma omp parallel num_threads(3)
            {
                int level3_thread_num = omp_get_thread_num();
                int level3_num_threads = omp_get_num_threads();

                printf("Level 3: Thread %d of %d (ancestor thread %d of %d, ancestor thread %d of %d)\n",
                       level3_thread_num, level3_num_threads,
                       omp_get_ancestor_thread_num(2), omp_get_team_size(2),
                       omp_get_ancestor_thread_num(1), omp_get_team_size(1));
            }
        }
    }

    return 0;
}
