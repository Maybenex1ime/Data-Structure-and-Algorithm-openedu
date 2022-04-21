#include <fstream>

using namespace std;

void anti_quicksort(int n, std::ofstream &fout)
{
    if (n == 1)
    {
        fout << "1\n";
        return;
    }

    int *a = new int[n];
    a[0] = 1;
    a[1] = 2;

    int temp;

    for (int i = 2; i < n; ++i)
    {
        a[i] = i + 1;
        temp = a[i / 2];
        a[i / 2] = a[i];
        a[i] = temp;
    }

    for (int i = 0; i < n; ++i)
        fout << a[i] << " ";
    fout << "\n";
}

int main()
{

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    anti_quicksort(n, fout);
}