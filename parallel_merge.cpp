#include <iostream>
#include <omp.h>
using namespace std;

void merge(int arr[] , int s , int e)
{
    int mid = s+ (e-s)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    int L[len1];
    int R[len2];

    int sindex = s;
    for(int i =0 ; i<len1 ; i++)
    {
        L[i] = arr[sindex++];
    }

    sindex = mid+1;
    for(int i =0 ; i<len2 ; i++)
    {
        R[i] = arr[sindex++];
    }

    int mainindex = s;
    int ind1 = 0;
    int ind2 = 0;

    while(ind1 < len1 && ind2 <len2)
    {
        if(L[ind1] < R[ind2])
        {
            arr[mainindex++] = L[ind1++];
        }
        else
        {
            arr[mainindex++] = R[ind2++];
        }
    }

    while(ind1 < len1)
    {
        arr[mainindex++] = L[ind1++];
    }

    while(ind2 < len2)
    {
        arr[mainindex++] = R[ind2++];
    }

}

void parallelMergeSort(int arr[] , int s , int e)
{
    if(s < e)
    {
        int mid = s+ (e-s) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
                parallelMergeSort(arr , s , mid);

            #pragma omp section
            parallelMergeSort(arr , mid+1 , e);
        }
        merge(arr, s, e);
    }

}

int main()
{
    int arr[] = {5, 3, 8, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    parallelMergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}