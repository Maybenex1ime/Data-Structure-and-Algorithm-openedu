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

    void set_parent(int paret)
    {
        parent = paret;
    }

    void delete_left()
    {
        children[0] = -1;
    }

    void delete_right()
    {
        children[1] = -1;
    }
};

void remove(int index, vector<Node *> &tree, int &count)
{
    if (tree.empty())
        return;
    queue<Node *> queue;
    queue.push(tree[0]);
    while (!queue.empty())
    {
        Node *vertex = queue.front();
        if (vertex->key == index)
        {
            Node *current_parent = tree[vertex->parent];
            if (tree[current_parent->children[0]]->key == vertex->key)
                tree[current_parent->children[0]]->delete_left();
            else
                tree[current_parent->children[0]]->delete_right();
        }
        else
        {
            for (size_t child : vertex->children)
            {
                if (child != -1)
                {
                    queue.push(tree[child]);
                }
            }
        }
        queue.pop();
    }
}

void set_parent(vector<Node *> &tree)
{
    if (tree.empty())
        return;
    queue<pair<Node *, int>> queue;
    queue.push(make_pair(tree[0], 0));
    while (!queue.empty())
    {
        Node *vertex = queue.front().first;
        int index = queue.front().second;
        for (size_t child : vertex->children)
        {
            tree[child]->set_parent(index);
            queue.push(make_pair(tree[child], child));
        }
        queue.pop();
    }
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Node *> nodes;

    int k, l, r;
    for (int i = 0; i < n; ++i)
    {
        cin >> k >> l >> r;
        nodes.push_back(new Node(k, l - 1, r - 1));
    }
    set_parent(nodes);
    int m, index;
    cin >> m;
    int count = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> index;
        remove(index, nodes, count);
        cout << count << "\n";
    }
}