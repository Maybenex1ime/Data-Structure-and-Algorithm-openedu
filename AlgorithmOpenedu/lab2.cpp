#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b;
    cin >> a;
    cin >> b;
    cout << a + b * b;
}
