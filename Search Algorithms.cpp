#include <bits/stdc++.h>
using namespace std;

//sequential search loop
bool seq_search_loop(int arr[], int sz, int n) {
    for (int i = 0; i < sz; i++)
        if (arr[i] == n) return true;
    return false;
}

// sequential search recersion
bool seq_search_rec(int arr[], int sz, int n, int i = 0) {
    if (i >= sz) return false;
    if (arr[i] == n) return true;
    return seq_search_rec(arr, sz, n, i + 1);
}

// binary search loop
bool binary_search_loop(int arr[], int sz, int n) {
    int start = 0, end = sz - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == n) return true;
        else if (arr[mid] < n) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

// binary search recersion
bool binary_search_rec(int arr[], int start, int end, int n) {
    if (start > end) return false;
    int mid = (start + end) / 2;
    if (arr[mid] == n) return true;
    else if (arr[mid] < n) return binary_search_rec(arr, mid + 1, end, n);
    else return binary_search_rec(arr, start, mid - 1, n);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int n;

    cout << "Enter the number that you need to check it exist or not: ";
    cin >> n;

    cout << "Sequential Search (Loop): "
         << (seq_search_loop(arr, sz, n) ? "Found" : "Not Found") << endl;

    cout << "Sequential Search (Recursion): "
         << (seq_search_rec(arr, sz, n) ? "Found" : "Not Found") << endl;

    cout << "Binary Search (Loop): "
         << (binary_search_loop(arr, sz, n) ? "Found" : "Not Found") << endl;

    cout << "Binary Search (Recursion): "
         << (binary_search_rec(arr, 0, sz - 1, n) ? "Found" : "Not Found") << endl;

    return 0;
}