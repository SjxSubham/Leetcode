#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Total sum of numbers from 1 to n
    long long totalSum = n * (n + 1) / 2;

    // Sum of numbers divisible by m
    long long countDiv = n / m;
    long long divSum = m * countDiv * (countDiv + 1) / 2;

    // Difference between divisible and non-divisible sums
    long long result = abs(2 * divSum - totalSum);

    cout << result << "\n";
    return 0;
}
