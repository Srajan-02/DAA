#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortPartialArray(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                if (j > 0 && arr[j] < arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
                if (j < n - 2 && arr[j + 2] < arr[j + 1])
                {
                    swap(&arr[j + 2], &arr[j + 1]);
                }
            }
        }
    }
}
int main()
{
    int n, i;
    printf("Enter the size of the partial array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the partial array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortPartialArray(arr, n);
    printf("Sorted Partial Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
