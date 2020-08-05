#include <iostream>
using namespace std;

template<class T>
void reverseMerge(T arr[], int lo, int mid, int up);
template<class T>
void merge(T arr[], int lo, int mid, int up);

template<class T>
void reverseMergeSort(T arr[], int lo, int up)
template<class T>
void mergeSort(T arr[], int lo, int up)

int main()
{
    /*****************************************************************/
    string name[5] = {"Neo", "Trinity", "Morpheus", "Smith", "Cypher"};
    string reverse[5];
    cout << "Input : ";
    for(int i = 0; i < 5; i++)
    {
        cout << name[i] << ", ";
        reverse[i] = name[i];
    }
    cout << "\nOutput : ";
    mergeSort(name,0, 5);
    for(int i = 0; i < 4; i++)
    {
        cout << name[i] << ", ";
    }
    cout << name[4] << "\n\n";
    /*****************************************************************/


    cout << "Non-Increasing order\nInput : ";
    for(int i = 0; i < 5; i++)
    {
        cout << reverse[i] << ", ";
    }
    cout <<"\nOutput : ";
    reverseMergeSort(reverse, 0, 5);
    for(int i = 0; i < 4; i++)
    {
        cout << reverse[i] << ", ";
    }
    cout << reverse[4] << "\n\n";

    /*****************************************************************/
    int number[7] = {39, 26, 45, 1, 8, 82, 11};
    int number2[7];
    cout << "Input : ";
    for(int i = 0; i < 7; i++)
    {
        cout << number[i] << ", ";
        number2[i] = number[i];
    }
    cout << "\nOutput : ";
    mergeSort(number, 0, 7);
    for(int i = 0; i < 6; i++)
    {
        cout << number[i] << ", ";
    }
    cout << number[6];
    cout <<"\n\n";

    /*****************************************************************/

    cout << "Non-Increasing order\nInput : ";
    for(int i = 0; i < 7; i++)
    {
        cout << number2[i] << ", ";
    }
    cout << "\nOutput : ";
    reverseMergeSort(number2, 0, 7);
    for(int i = 0; i < 6; i++)
    {
        cout << number2[i] << ", ";
    }
    cout << number2[6];
    cout <<"\n";
}




template<class T>
void reverseMerge(T arr[], int lo, int mid, int up)
{
    int n1 = mid - lo + 1;
    int n2 = up - mid;

    T L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[lo + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = lo;
    while(i < n1 && j < n2)
    {
        if(L[i] > R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }
    while(j < n2)
    {
        arr[k++] = R[j++];
    }
}

template<class T>
void reverseMergeSort(T arr[], int lo, int up)
{
    if(lo < up)
    {
        int mid = lo + (up - lo)/2;
        reverseMergeSort(arr, lo, mid);
        reverseMergeSort(arr, mid+1, up);
        reverseMerge(arr, lo, mid, up);
    }
}

template<class T>
void merge(T arr[], int lo, int mid, int up)
{
    int n1 = mid - lo + 1;
    int n2 = up - mid;

    T L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[lo + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = lo;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }
    while(j < n2)
    {
        arr[k++] = R[j++];
    }
}

template<class T>
void mergeSort(T arr[], int lo, int up)
{
    if(lo < up)
    {
        int mid = lo + (up - lo)/2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, up);
        merge(arr, lo, mid, up);
    }
}
