#include <stdio.h>
#include <iostream>

using namespace std;

static int HASHCOUNT = 1007;
static int KEY = 65535;

class Node
{
private:
    Node *next;
    long long value;
    string stringa;

public:
    Node()
    {
        next = 0;
        value = 0;
        stringa = ' ';
    }

    Node(Node *n, long long v, string s)
    {
        next = n;
        value = v;
        stringa = s;
    }

    Node(string s, long long v)
    {
        value = v;
        stringa = s;
    }

    ~Node() {}

    long long get_value()
    {
        return value;
    }

    Node *get_next()
    {
        return next;
    }

    void set_stringa(string s)
    {
        stringa = s;
    }

    string get_stringa()
    {
        return stringa;
    }
};

int getHashCode(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        ans += 31 * ans + s[i];
        ans %= HASHCOUNT;
    }
    return ans;
}

void push(string s, int value, int *hashed, string *hashedKey)
{
    int x = getHashCode(s);
    if (hashedKey[x] == " ")
    {
        hashed[x] = value;
        hashedKey[x] = s;
    }
    while (hashedKey[x] != " ")
    {
        x++;
    }
    hashed[x] = value;
    hashedKey[x] = s;
    return;
};

int find(string s, string *hashedKey, int *hashed)
{
    int x = getHashCode(s);
    while (hashedKey[x] != " ")
    {
        if (hashedKey[x] == s)
        {
            return hashed[x];
        }
        x++;
    }
    return -1;
}

int convertToInt(string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;

    int *hashed = new int[1008];
    string *hashedKey = new string[1008];
    string *StringList = new string[50];
    int *queue = new int[100005];
    int *reg = new int[26];

    for (int i = 0; i < 1007; ++i)
        hashedKey[i] = " ";

    int count = 0;
    while (cin >> s)
    {
        if (s[0] == ':')
        {
            push(s.substr(1), count, hashed, hashedKey);
        }
        else
        {
            StringList[count] = s;
            count++;
        }
    }

    string cur;
    int x, y;
    int countQueue = 0;
    int firstQueue = 0;
    for (int i = 0; i < count; i++)
    {
        cur = StringList[i];
        switch (cur[0])
        {
        case '+':
        {
            queue[countQueue++] = (queue[firstQueue++] + queue[firstQueue++]) % KEY;
            break;
        }
        case '-':
        {
            queue[countQueue++] = (queue[firstQueue++] - queue[firstQueue++]) % KEY;
            break;
        }
        case '*':
        {
            queue[countQueue++] = (queue[firstQueue++] * queue[firstQueue++]) % KEY;
            break;
        }
        case '/':
        {
            if (queue[firstQueue + 1] == 0)
            {
                queue[countQueue++];
            }
            else
                queue[countQueue++] = (queue[firstQueue++] / queue[firstQueue++]) % KEY;
            break;
        }
        case '%':
        {
            if (queue[firstQueue + 1] == 0)
            {
                queue[countQueue++];
            }
            else
                queue[countQueue++] = (queue[firstQueue++] % queue[firstQueue++]) % KEY;
            break;
        }
        case '>':
        {
            reg[cur[1] - 'a'] = queue[firstQueue++];
            break;
        }
        case '<':
        {
            queue[countQueue++] = reg[cur[1] - 'a'];
            break;
        }
        case 'P':
        {
            if (cur.length() == 1)
                cout << queue[firstQueue++];
            else
                reg[cur[1] - 'a'];
            break;
        }

        case 'C':
        {
            char c = (char)(cur.length() == 1 ? queue[firstQueue++] : reg[cur[1] - 'a']) & 255;
            cout << c;
            break;
        }

        case 'J':
        {
            i = find(cur.substr(1), hashedKey, hashed) - 1;
            break;
        }
        case 'Z':
        {
            if (reg[cur[1] - 'a'] == 0)
            {
                i = find(cur.substr(2), hashedKey, hashed) - 1;
            }
            break;
        }
        case 'E':
        {
            if (reg[cur[1] - 'a'] == reg[cur[2] - 'a'])
            {
                i = find(cur.substr(3), hashedKey, hashed) - 1;
                break;
            }
        }
        case 'G':
        {
            if (reg[cur[1] - 'a'] > reg[cur[2] - 'a'])
            {
                i = find(cur.substr(3), hashedKey, hashed) - 1;
                break;
            }
        }
        default:
        {
            queue[countQueue++] = convertToInt(cur);
        }
        }
    }

    return 0;
}