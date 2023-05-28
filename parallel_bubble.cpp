#include <iostream>
#include <omp.h>
using namespace std;
void parallelBubbleSort(int arr[], int n)
{
    bool swapped = true;
#pragma omp parallel
    {
        while (swapped)
        {
            swapped = false;
#pragma omp for
            for (int i = 0; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
#pragma omp for
            for (int i = 1; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {2,14,6,76,3,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    parallelBubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
