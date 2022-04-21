#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

double find(double *array, int n)
{
    double l = 0;
    double r = array[0];
    while (r - l > 0.000000001)
    {
        array[1] = (l + r) / 2;
        bool Up = true;
        for (int i = 2; i < n; ++i)
        {
            array[i] = 2 * array[i - 1] + 2 - array[i - 2];
            if (array[i] < 0)
            {
                Up = false;
                break;
            }
        }

        if (Up == true)
        {
            r = array[1];
        }
        else
            l = array[1];
    }
    return array[n - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    double *array = new double[1001];
    cin >> n >> array[0];
    double B = find(array, n);
    cout.precision(30);
    cout << B;
}