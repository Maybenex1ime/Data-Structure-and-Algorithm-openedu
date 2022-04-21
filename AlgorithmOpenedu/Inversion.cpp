#include <fstream>

long long merge(int *a, int l, int m, int r, std::ofstream &fout)
{
    int i, j, k;
    long long inv;
    int lsize = m - l + 1, rsize = r - m;
    int *left_array = new int[lsize];
    int *right_array = new int[rsize];

    for (i = 0; i < lsize; ++i)
        left_array[i] = a[l + i];
    for (j = 0; j < rsize; ++j)
        right_array[j] = a[m + 1 + j];

    i = 0, j = 0, k = l, inv = 0;

    while (i < lsize && j < rsize)
    {
        if (left_array[i] <= right_array[j])
            a[k++] = left_array[i++];
        else
        {
            a[k++] = right_array[j++];
            inv += lsize - i;
        }
    }

    while (i < lsize)
        a[k++] = left_array[i++];
    while (j < rsize)
        a[k++] = right_array[j++];

    // fout << l + 1 << " " << r + 1 << " " << a[l] << " " << a[r] << " " << inv << "\n";

    delete left_array;
    delete right_array;

    return inv;
}

long long mergesort(int *a, int l, int r, std::ofstream &fout)
{
    if (l >= r)
        return 0;

    int m = (r + l) / 2;
    long long inv = 0;

    inv += mergesort(a, l, m, fout);
    inv += mergesort(a, m + 1, r, fout);

    inv += merge(a, l, m, r, fout);
    return inv;
}

void inversion(int *a, int n, std::ofstream &fout)
{
    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
                result++;
        }
    }
    fout << result << "\n";
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, result = 0;
    fin >> n;
    int *array = new int[n];

    for (int i = 0; i < n; ++i)
        fin >> array[i];

    // inversion(array, n, fout);

    fout << mergesort(array, 0, n - 1, fout) << '\n';

    delete[] array;

    return 0;
}