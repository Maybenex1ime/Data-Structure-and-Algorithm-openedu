#include <fstream>

void insertionsort(int n, int *m, std::ofstream &fout)
{
    int i, j, temp, x, y, k;

    for (j = 1; j < n; ++j)
    {
        for (i = j - 1; i >= 0 && m[i] > m[i + 1]; --i)
        {
            k = i;
            while (m[k - 1] >= m[k])
            {
                k--;
                if (k == 0)
                    break;
            }

            temp = m[i + 1];
            m[i + 1] = m[k];
            m[k] = temp;
            fout << "Swap elements at indices " << k + 1 << " and " << i + 2 << ".\n";
            i = k;
        }
    }
}

void quicksort(int left, int right, int *a, std::ofstream &fout)
{
    int middle = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i < j)
    {
        while (a[i] < middle)
        {
            i++;
        }
        while (a[j] > middle)
        {
            j--;
        }

        if (i <= j)
        {
            if (a[i] != a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                if (i != j)
                {
                    fout << "Swap elements at indices " << i + 1 << " and " << j + 1 << ".\n";
                }
            }
            i++;
            j--;
        }
    }

    if (left < j)
    {
        quicksort(left, j, a, fout);
    }
    if (right > i)
    {
        quicksort(i, right, a, fout);
    }
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    int *m = new int[n];

    for (int i = 0; i < n; ++i)
        fin >> m[i];

    quicksort(0, n - 1, m, fout);

    fout << "No more swaps needed.\n";

    for (int i = 0; i < n; ++i)
        fout << m[i] << ' ';
    fout << '\n';

    delete[] m;

    return 0;
}