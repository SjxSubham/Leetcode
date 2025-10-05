#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long total_sum = n * (n + 1) / 2;
    // Sum of numbers divisible by m
    long long k = n / m; 
    long long div_sum = m * (k * (k + 1) / 2);

    // Sum of numbers not divisible by m
    long long non_div_sum = total_sum - div_sum;

    // Absolute difference
    long long result = abs(div_sum - non_div_sum);

    cout << result << endl;
    return 0;
}
