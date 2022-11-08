#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class BTree
{
public:
    class BNode
    {
    public:
        T data;
        BNode *left;
        BNode *right;
        BNode(T data, BNode *left = nullptr, BNode *right = nullptr)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

public:
    BNode *root = nullptr;

public:
    void insert(T data)
    {
        queue<BNode **> q;
        q.push(&root);
        while (true)
        {
            BNode **nPtr = q.front();
            if (*nPtr == nullptr)
            {
                *nPtr = new BNode(data);
                break;
            }
            q.pop();
            q.push(&((*nPtr)->left));
            q.push(&((*nPtr)->right));
        }
    }

    void printPostfix(BNode *root)
    {
        if (root == nullptr) return;
        printPostfix(root->left);
        printPostfix(root->right);
        cout << root->data << " ";

    }
};

int main()
{
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(6);
    tree.insert(4);
    tree.printPostfix(tree.root);
}