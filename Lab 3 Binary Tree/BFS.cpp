// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS()
{
    queue<Node*> q = queue<Node*>();
    q.push(root);
    cout << root->value << " ";
    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        if (n->pLeft != nullptr) {
            cout << n->pLeft->value << " ";
            q.push(n->pLeft);
        }
        if (n->pRight != nullptr) {
            cout << n->pRight->value << " ";
            q.push(n->pRight);
        }
    }
    
}
// STUDENT ANSWER END
