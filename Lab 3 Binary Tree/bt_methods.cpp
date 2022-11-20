// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

int getHeight(Node* n = nullptr) {
    if (n == nullptr) n = root;
    return max(n->pLeft ? getHeight(n->pLeft) : 0,n->pRight ? getHeight(n->pRight) : 0) + 1;
    
}

string getPreOrder(Node* node) {
    if (node == NULL) 
        return "";
    return to_string(node->value) + " " +  getPreOrder(node->pLeft) + getPreOrder(node->pRight);
}

string preOrder() {
   return getPreOrder(root);
}

string getInOrder(Node* node) {
    if (node == NULL) 
        return "";
    return getInOrder(node->pLeft) + to_string(node->value) + " " + getInOrder(node->pRight);
}

string inOrder() {
    return getInOrder(root);
}

string getPostOrder(Node* node) {
    if (node == NULL) 
        return "";
    return getPostOrder(node->pLeft) + getPostOrder(node->pRight) + to_string(node->value) + " ";
}

string postOrder() {
    return getPostOrder(root);
}

// STUDENT ANSWER END
