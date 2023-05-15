#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct symbol
{
    char ch;
    int freq;
} Symbol;
void merge(Symbol arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Symbol L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].freq <= R[j].freq)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(Symbol arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void sortByFrequency(char arr[], int n)
{
    int i, j;
    Symbol symbols[256] = {{0, 0}};

    for (i = 0; i < n; i++)
    {
        symbols[arr[i]].ch = arr[i];
        symbols[arr[i]].freq++;
    }
    mergeSort(symbols, 0, 255);
    for (i = 0; i <= 255; i++)
    {
        if (symbols[i].freq > 0)
        {
            for (j = 0; j < symbols[i].freq; j++)
            {
                printf("%c ", symbols[i].ch);
            }
        }
    }
}
int main()
{
    int n, i;
    char arr[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf(" %c", &arr[i]);
    printf("Sorted array by frequency:\n");
    sortByFrequency(arr, n);
    return 0;
}
