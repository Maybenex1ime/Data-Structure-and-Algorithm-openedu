// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

const std::string filein = "input.txt";
const std::string fileout = "output.txt";
std::ofstream ofstr;
std::ifstream ifstr(filein);

void PrintArray(std::pair<std::string, int> *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i].first << " " << arr[i].second << std::endl;
    }
}

void countSort(std::pair<std::string, int> *a, int size, size_t k)
{
    std::pair<std::string, int> *b = NULL;
    int *c = NULL;
    b = new std::pair<std::string, int>[size];
    c = new int[30];

    for (int i = 0; i < 30; i++)
    {
        c[i] = 0;
        // cout << c[i] << "\n";
    }
    for (int j = 0; j < size; j++)
    {
        c[k < a[j].first.size() ? (int)(unsigned char)a[j].first[k] - 97 + 1 : 0]++; // a[j] is a string
                                                                                     // cout << c[a[j]] << endl;
    }

    for (int f = 1; f < 30; f++)
    {
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--)
    {
        b[c[k < a[r].first.size() ? (int)(unsigned char)a[r].first[k] - 97 + 1 : 0] - 1] = a[r];
        c[k < a[r].first.size() ? (int)(unsigned char)a[r].first[k] - 97 + 1 : 0]--;
    }

    for (int l = 0; l < size; l++)
    {
        a[l] = b[l];
    }

    // avold memory leak
    delete[] b;
    delete[] c;
}

void radixSort(std::pair<std::string, int> *b, int max, int phase)
{
    // size_t max = getMax(b, r);
    for (size_t digit = max; digit > max - phase; digit--)
    { // size_t is unsigned, so avoid using digit >= 0, which is always true
        countSort(b, max, digit - 1);
    }
}

int main()
{

    ofstr.open(fileout);
    int n, m, k;

    if (ifstr.is_open())
    {
        ifstr >> m >> n >> k;
        std::pair<std::string, int> *arr = new std::pair<std::string, int>[m];
        for (int i = 0; i < m; i++)
        {
            arr[i].first.resize(n);
        }
        std::string s = "";
        std::getline(ifstr, s);
        for (int i = 0; i < n; i++)
        {
            std::getline(ifstr, s);
            for (int j = 0; j < m; j++)
            {
                arr[j].first[i] = s[j];
                arr[j].second = j + 1;
            }
            // std::cout << s << std::endl;
        }
        // PrintArray(arr, m);
        radixSort(arr, m, k);
        // PrintArray(arr, m);
        for (int i = 0; i < m; i++)
        {
            // std::cout << arr[i].first << std::endl;
            ofstr << arr[i].second << " ";
        }
        delete[] arr;
        ifstr.close();
        ofstr.close();
    }

    return 0;
}
