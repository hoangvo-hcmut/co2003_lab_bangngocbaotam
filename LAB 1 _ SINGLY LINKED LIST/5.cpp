void reduceDuplicate(Node* root)
{
    Node* current = root;
    Node* prev = nullptr;
    while (current) {
        if (prev != nullptr && current->getData() == prev->getData()) {
            prev->setNext(current->getNext());
        } else {
           prev = current;          
        }
        current = current->getNext();
    }
}
