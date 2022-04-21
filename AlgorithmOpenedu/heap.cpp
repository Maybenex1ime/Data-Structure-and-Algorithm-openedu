#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    long long *a = new long long[1000001];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    bool heap = true;
    for (int i = 1; i <= n; ++i)
    {
        if (2 * i <= n && 2 * i + 1 <= n)
        {
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
            {
                heap = false;
                break;
            }
        }
    }
    if (heap == true)
        cout << "YES";
    else
        cout << "NO";
}
