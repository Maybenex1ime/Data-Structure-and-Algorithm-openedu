#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    int dem = 0;
    int count = 0;

    char operation;
    int value;
    int *b = new int[1000001];
    for (int i = 0; i < n; ++i)
    {
        fin >> operation;
        if (operation == '+')
        {
            fin >> value;
            b[dem++] = value;
        }
        else
        {
            fout << b[count++] << '\n';
        }
    }
}