#include <fstream>
#include <string>

using namespace std;

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    string str;
    int n;
    fin >> n;

    char *a = new char[10001];

    for (int i = 0; i < n; ++i)
    {
        fin >> str;
        int dem = 0;
        bool accept = true;
        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == '(' || str[j] == '[')
            {
                str[dem++] = str[j];
            }
            else
            {
                if (str[j] == ')')
                {
                    if (str[--dem] != '(')
                    {
                        accept = false;
                        break;
                    }
                }
                if (str[j] == ']')
                {
                    if (str[--dem] != '[')
                    {
                        accept = false;
                        break;
                    }
                }
            }
        }
        if (dem != 0)
            accept = false;
        if (accept == true)
            fout << "YES"
                 << "\n";
        else
            fout << "NO"
                 << "\n";
    }
}