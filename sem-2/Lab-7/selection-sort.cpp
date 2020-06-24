#include <iostream>
using namespace std;
template<class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
void selection_sort(T *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[i], &arr[min_index]);
    }
}

template<class T>
void reverse_selection_sort(T *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int max_index = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[max_index])
                max_index = j;
        }
        swap(&arr[i], &arr[max_index]);
    }
}


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
    selection_sort(name,5);
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
    reverse_selection_sort(reverse,5);
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
    selection_sort(number,7);
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
    reverse_selection_sort(number2,7);
    for(int i = 0; i < 6; i++)
    {
        cout << number2[i] << ", ";
    }
    cout << number2[6];
    cout <<"\n";
}
