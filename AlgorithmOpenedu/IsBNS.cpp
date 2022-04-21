#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int key;
    size_t children[2];
    int parent;
    Node(int key, size_t left, size_t right) : key(key)
    {
        children[0] = left;
        children[1] = right;
    }
};

bool isBST(int index, int range_min, int range_max, vector<Node *> nodes)
{

    if (index == -1)
        return true;
    Node *currentNode = nodes[index];
    if (currentNode->key < range_min || currentNode->key > range_max)
        return false;

    return (isBST(currentNode->children[0], range_min, currentNode->key - 1, nodes) && isBST(currentNode->children[1], currentNode->key + 1, range_max, nodes));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Node *> nodes;
    if (n == 0)
    {
        nodes.push_back(new Node(0, -1, -1));
    }
    int k, l, r;
    for (int i = 0; i < n; ++i)
    {
        cin >> k >> l >> r;
        nodes.push_back(new Node(k, l - 1, r - 1));
    }
    if (isBST(0, -99999, 999999, nodes) == true)
        cout << "YES";
    else
        cout << "NO";
}