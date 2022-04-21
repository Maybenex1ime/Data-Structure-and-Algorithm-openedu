#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    double a[10001];
    int c[10001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        c[i] = i;
    }
    for (int i = 2; i <= n; ++i)
    {
        int j = i - 1;
        while (j > 0 && a[j] > a[j + 1])
        {
            double temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            int temp1 = c[j];
            c[j] = c[j + 1];
            c[j + 1] = temp1;
            j--;
        }
    }

    cout << c[1] << " " << c[(n + 1) / 2] << " " << c[n];
}
