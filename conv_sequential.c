#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);

    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *R_seq = malloc(sizeof(int) * (NA - NF + 1));

    for (int i = 0; i < NA; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < NF; i++)
    {
        scanf("%d", &F[NF - i - 1]); // Read filter in reverse
    }

    // Start timing for sequential convolution
    clock_t start_seq = clock();

    // Convolution
    int result_size = NA - NF + 1;

    for (int i = 0; i < result_size; i++)
    {
        int sum = 0; // Initialize result to 0

        for (int j = 0; j < NF; j++)
        {
            sum += A[i + j] * F[j];
        }
        R_seq[i] = sum;
    }

    // End timing for sequential convolution
    clock_t end_seq = clock();
    double seq_time = (double)(end_seq - start_seq) / CLOCKS_PER_SEC;

    // Print results
    printf("Sequential result:\n");
    for (int i = 0; i < result_size; i++)
    {
        printf("%d\n", R_seq[i]);
    }
    printf("Total time for sequential execution: %f seconds\n", seq_time);

    // ---- free memory ----
    free(F);
    free(A);
    free(R_seq);
    // ---- end free ----

    return 0;
}
