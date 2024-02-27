#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);
    double* arr = (double*)malloc((n + 1) * sizeof(double));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &arr[i]);
    }
    for (int j = 1; j <= n - 1; j++)
    {
        for (int k = j + 1; k <= n; k++)
        {
            if (arr[j] / k == arr[k] / j)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    free(arr);
    arr = NULL;
    return 0;

}