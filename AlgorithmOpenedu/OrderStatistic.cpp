#include <fstream>

using namespace std;

void quicksort(int left, int right, int *a, int k1, int k2, std::ofstream &fout)
{
    if (k1 > right || k2 < left)
        return;
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
            }
            i++;
            j--;
        }
    }

    if (left < j)
    {
        quicksort(left, j, a, k1, k2, fout);
    }
    if (right > i)
    {
        quicksort(i, right, a, k1, k2, fout);
    }
}

int main()
{

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, k1, k2;
    fin >> n >> k1 >> k2;

    int *a = new int[n];

    int A, B, C;
    fin >> A >> B >> C >> a[0] >> a[1];

    for (int i = 2; i < n; ++i)
    {
        a[i] = a[i - 2] * A + B * a[i - 1] + C;
    }

    quicksort(0, n - 1, a, k1 - 1, k2 - 1, fout);

    for (int i = k1 - 1; i < k2; ++i)
    {
        fout << a[i] << " ";
    }

    delete[] a;
}