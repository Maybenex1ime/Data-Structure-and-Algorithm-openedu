#include <iostream>
#include <fstream>
using namespace std;

void merge(int *a, int left, int mid, int right, std::ofstream &fout)
{
    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; ++i)
    {
        leftArray[i] = a[left + i];
    }
    for (int i = 0; i < subArrayTwo; ++i)
    {
        rightArray[i] = a[mid + 1 + i];
    }
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexofMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            a[indexofMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            a[indexofMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexofMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        a[indexofMergedArray] = leftArray[indexOfSubArrayOne];
        indexofMergedArray++;
        indexOfSubArrayOne++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        a[indexofMergedArray] = rightArray[indexOfSubArrayTwo];
        indexofMergedArray++;
        indexOfSubArrayTwo++;
    }
    fout << left + 1 << " " << right + 1 << " " << a[left] << " " << a[right] << "\n";
    delete leftArray;
    delete rightArray;
}

void merge_sort(int left, int right, int *a, std::ofstream &fout)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;

    merge_sort(left, mid, a, fout);
    merge_sort(mid + 1, right, a, fout);

    merge(a, left, mid, right, fout);
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; ++i)
        fin >> a[i];

    merge_sort(0, n - 1, a, fout);
    for (int i = 0; i < n; ++i)
    {
        fout << a[i] << " ";
    }
}
