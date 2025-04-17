#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n = 0, m = 0, i = 0, j = 0, k = 0;
    printf("Enter number of processes and resources:\n");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], avail[m];
    int need[n][m];

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available matrix:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finish[n];
    int safeSeq[n];
    int count = 0;

    for (i = 0; i < n; i++)
        finish[i] = false;

    while (count < n)
    {
        bool found = false;
        for (i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m)
                {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
        {
            printf("System is not in safe state.\n");
            return 1;
        }
    }

    printf("System is in safe state.\n");
    printf("Safe sequence is: ");
    for (i = 0; i < n; i++)
    {
        printf("P%d", safeSeq[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}
