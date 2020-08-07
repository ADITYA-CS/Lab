#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

template <class T>
void InsertionSort(vector<T> &A){
  int n = A.size();
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    T save = A[i];
    while (j >= 0 && A[j] > save) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = save;
  }
}

// test
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto &number : numbers) {
      cin >> number;
    }
    // Using chrono for recording time taken by InsertionSort()
    auto start = chrono::steady_clock::now();
    InsertionSort(numbers);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> time_taken = end - start;
    cout << "Time taken : " << time_taken.count() << " sec" << endl;

    cout << "Sorted List : " << endl;
    for (auto number : numbers) {
      cout << number << ' ';
    }
}
