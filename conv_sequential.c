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
        scanf("%d", &F[i]);
    }

    int FF[NF];
    for (int i = 0; i < NF; i++)
    {
        FF[i] = F[NF - 1 - i];
    }

    // Start timing for sequential convolution
    clock_t start_seq = clock();

    // Convolution
    for (int i = 0; i <= NA - NF; i++)
    {
        R_seq[i] = 0; // Initialize result to 0
        for (int j = 0; j < NF; j++)
        {
            R_seq[i] += A[i + j] * FF[j];
        }
    }

    // End timing for sequential convolution
    clock_t end_seq = clock();
    double seq_time = (double)(end_seq - start_seq) / CLOCKS_PER_SEC;

    printf("Sequential result:\n");
    for (int i = 0; i <= NA - NF; i++)
    {
        printf("%d \n", R_seq[i]);
    }
    printf("\nTotal time for sequential execution: %f seconds\n", seq_time);

    // ---- free memory ----
    free(F);
    free(A);
    free(R_seq);
    // ---- end free ----
    return 0;
}
