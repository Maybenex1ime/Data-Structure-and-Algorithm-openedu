#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int key;
    size_t children[2];
    Node(int key, size_t left, size_t right) : key(key)
    {
        children[0] = left;
        children[1] = right;
    }
};

int height(vector<Node *> &tree)
{
    if (tree.empty())
    {
        return 0;
    }

    int max_distance = 0;
    queue<pair<Node *, int>> queue;
    queue.push(make_pair(tree[0], 1));

    while (!queue.empty())
    {
        Node *vertex = queue.front().first;
        int distance = queue.front().second;
        max_distance = max(max_distance, distance);
        for (size_t child : vertex->children)
        {
            if (child != -1)
            {
                queue.push(make_pair(tree[child], distance + 1));
            }
        }
        queue.pop();
    }

    return max_distance;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int *l = new int[200001];
    int *r = new int[200001];
    int *k = new int[200001];
    cin >> n;
    vector<Node *> nodes;

    for (int i = 0; i < n; ++i)
    {
        cin >> k[i] >> l[i] >> r[i];
        nodes.push_back(new Node(k[i], l[i] - 1, r[i] - 1));
    }

    cout << height(nodes);
}