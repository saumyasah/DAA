#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n,i;
    cout<<"Enter size of array";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cout<<"Elements";
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}