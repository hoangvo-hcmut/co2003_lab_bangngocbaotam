void LinkedList::partition(int k) {
    LinkedList::Node * nodeI = nullptr;
    LinkedList::Node * nodeII = nullptr;
    LinkedList::Node * nodeIII = nullptr;
    LinkedList::Node * lastNodeI  = nullptr;
    LinkedList::Node * lastNodeII  = nullptr;
    LinkedList::Node * lastNodeIII  = nullptr;
    
    LinkedList::Node* current = head;
    while (current) {
        LinkedList::Node* newNode = new LinkedList::Node(current->value);
        if (current->value < k) {
            if (lastNodeI == nullptr) {
                lastNodeI = nodeI = newNode;
            } else {
                lastNodeI->next =newNode;
                lastNodeI=lastNodeI->next;
            }
        } else if (current->value == k) {
            if (lastNodeII == nullptr) {
                lastNodeII = nodeII = newNode;
            } else {
                lastNodeII->next = newNode;
                lastNodeII=lastNodeII->next;
            }
        } else {
            if (lastNodeIII == nullptr) {
                lastNodeIII = nodeIII = newNode;
            } else {
                lastNodeIII->next = newNode;
                lastNodeIII=lastNodeIII->next;
            }
        }
        current = current->next;
    }
    if (lastNodeI) {
        lastNodeI->next = nodeII ? nodeII : nodeIII;
    }
    if (lastNodeII) {
        lastNodeII->next = nodeIII;
    }
    head = nodeI ? nodeI : (nodeII ? nodeII : nodeIII);
    tail = lastNodeIII ? lastNodeIII : (lastNodeII ? lastNodeII : lastNodeI);
}
