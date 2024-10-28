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

    omp_set_num_threads(8); // Set the number of threads

    // Timing with OpenMP
    double start_time = omp_get_wtime();
    int result_size = NA - NF + 1;

    // Convolution (Parallelized)
#pragma omp parallel for
    for (int i = 0; i < result_size; i++)
    {
        int sum = 0; // Initialize result to 0

        for (int j = 0; j < NF; j++)
        {
            sum += A[i + j] * F[j];
        }
        R_parallel[i] = sum;
    }

    double end_time = omp_get_wtime();
    double total_time = end_time - start_time;

    // Print results
    printf("Parallel result:\n");
    for (int i = 0; i < result_size; i++)
    {
        printf("%d\n", R_parallel[i]);
    }
    printf("Total time for parallel execution: %f seconds\n", total_time);

    // ---- free memory ----
    free(F);
    free(A);
    free(R_parallel);
    // ---- end free ----

    return 0;
}