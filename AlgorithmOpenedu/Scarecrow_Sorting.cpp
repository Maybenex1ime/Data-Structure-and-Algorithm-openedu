#include <fstream>

void quicksort(int left, int right, int *a, int k, std::ofstream &fout)
{

    if (left == right)
        return;

    int middle = a[left];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (a[i] < middle)
        {
            i += k;
        }
        while (a[j] > middle)
        {
            j -= k;
        }

        if (i <= j)
        {
            if (a[i] != a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            i += k;
            j -= k;
        }
    }
    quicksort(left, i - k, a, k, fout);
    quicksort(i, right, a, k, fout);
}

bool asNees(int *a, int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, k;
    fin >> n >> k;

    int *a = new int[n];

    for (int i = 0; i < n; ++i)
        fin >> a[i];

    if (k < n)
    {
        int r = ((int)(n - 1) / k) * k;

        for (int i = 0; i < k; ++i)
        {
            quicksort(i, r, a, k, fout);
            r++;
            if (r > n - 1)
                r -= k;
        }
    }

    if (asNees(a, n) == true)
        fout << "YES";
    else
        fout << "NO";

    return 0;
}