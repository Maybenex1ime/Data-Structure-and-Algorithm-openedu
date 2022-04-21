#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{

    ifstream in;
    in.open("input.txt");
    int n;
    in >> n;
    int m;
    in >> m;
    auto firstArr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        in >> firstArr[i];
    }

    auto secondArr = new int[m];
    for (int i = 0; i < m; ++i)
    {
        in >> secondArr[i];
    }

    sort(firstArr, firstArr + n);
    sort(secondArr, secondArr + m);
    in.close();
    auto *arr = new int[m * n];
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[k] = firstArr[i] * secondArr[j];
            k++;
        }
    }
    int count = m * n;
    cout << endl;
    int d = 8, w = 32;
    int *c = new int[256];
    int *b = new int[count];
    for (int p = 0; p < 4; p++)
    {
        for (int i = 0; i < 256; ++i)
            c[i] = 0;
        for (int i = 0; i < count; ++i)
        {
            b[i] = 0;
        }

        for (int i = 0; i < count; i++)
            c[(arr[i] >> d * p) & ((1 << d) - 1)]++;
        for (int i = 1; i < 1 << d; i++)
            c[i] += c[i - 1];
        for (int i = count - 1; i >= 0; i--)
            b[--c[(arr[i] >> d * p) & ((1 << d) - 1)]] = arr[i];

        for (int i = 0; i < count; ++i)
        {
            arr[i] = b[i];
        }
    }

    ofstream out;
    out.open("output.txt");
    long long sum = 0;
    for (int i = 0; i < count; i += 10)
    {
        sum += arr[i];
    }
    out << sum;
    out.close();

    return 0;
}