#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int a[1001];
    int b[1001];
    int c[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        c[i] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        int j = i - 1;
        while (j > 0 && a[j] > a[j + 1])
        {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            j--;
        }
        c[i] = j + 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << c[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
}
