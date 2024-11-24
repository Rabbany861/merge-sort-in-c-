#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
    int na = q - p + 1;
    int nb = r - q;

    int a[na], b[nb];


    for (int i = 0; i < na; i++)
    {
        a[i] = arr[p + i];
    }
    for (int i = 0; i < nb; i++)
    {
        b[i] = arr[q + 1 + i];
    }

    int i = 0, j = 0, k = p;
    while (i < na && j < nb)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }


    while (i < na)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < nb)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
