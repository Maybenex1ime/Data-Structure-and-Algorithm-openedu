#include <stdio.h>
#include <iostream>

using namespace std;

int binary_search_first(int request, int *array, int left, int right)
{
    if (left >= right)
    {
        if (array[left] != request)
            return -1;
        else
            return left + 1;
    }
    int mid = (left + right) / 2;
    if (array[mid] >= request)
        return binary_search_first(request, array, left, mid);
    else
        return binary_search_first(request, array, mid + 1, right);
}

int binary_search_last(int request, int *array, int left, int right)
{
    if (left >= right)
    {
        if (array[right] != request)
            return -1;
        else
            return right + 1;
    }
    int mid = left + (right - left + 1) / 2;
    // cout << mid << " " << left << " " << right << " ";
    if (array[mid] <= request)
        return binary_search_last(request, array, mid, right);
    else
        return binary_search_last(request, array, left, mid - 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int *array = new int[100001];
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> array[i];
    int m;
    cin >> m;
    int request;
    for (int i = 0; i < m; ++i)
    {
        cin >> request;
        int first = binary_search_first(request, array, 0, n - 1);
        int last = binary_search_last(request, array, first - 1, n - 1);
        cout << first << " " << last << "\n";
    }
}