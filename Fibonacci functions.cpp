#include <bits/stdc++.h>
using  namespace std;

// Recursive function
long long fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
    //O(2^n)
}

// Dynamic programming function
long long fibdp(int n)
{
    if (n <= 1)
        return n;

    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
    //O(n)
}

//Matrix Method
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x; F[0][1] = y;
    F[1][0] = z; F[1][1] = w;
}

void power(long long F[2][2], int n) {
    if (n <= 1)
        return;
    long long M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

long long fibMatrix(int n) {
    if (n == 0)
        return 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

int main()
{

    while (true) 
    {
        int n;
        cout << "Enter a non-negative integer (or 'exit' to quit): ";
        if (!(cin >> n)||(n<0)) {
            cout<<"Exiting program."<<endl;
            break;
        }
        else
        {
            cout << "Fibonacci number (Recursive): " << fibRecursive(n) << endl;
            cout << "Fibonacci number (Dynamic Programming): " << fibdp(n) << endl;
            cout << "Fibonacci number (Matrix Method): " << fibMatrix(n) << endl;
        }
    }
    return 0;
}