#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *R_parallel = malloc(sizeof(int) * (NA - NF + 1));

    for (int i = 0; i < NA; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < NF; i++)
    {
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc ----

    // Reverse filter F into FF
    int FF[NF];
    for (int i = 0; i < NF; i++)
    {
        FF[i] = F[NF - 1 - i];
    }

    omp_set_num_threads(8); // Set the number of threads

    // Timing with OpenMP
    // double start_time = omp_get_wtime();

// Convolution (Parallelized)
#pragma omp parallel for
    for (int i = 0; i <= NA - NF; i++)
    {
        R_parallel[i] = 0; // Initialize result to 0
        for (int j = 0; j < NF; j++)
        {
            R_parallel[i] += A[i + j] * FF[j];
        }
    }

    // double end_time = omp_get_wtime(); // End time for parallel
    // double total_time = end_time - start_time;

    printf("Parallel result:\n");
    for (int i = 0; i <= NA - NF; i++)
    {
        printf("%d\n", R_parallel[i]);
    }
    // printf("Total time for parallel execution: %f seconds\n", total_time);

    // ---- free memory ----
    free(F);
    free(A);
    free(R_parallel);
    // ---- end free ----

    return 0;
}
