template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    add(count, e);
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index == 0) {
        Node* node = new Node(e);
        node->next = head;
        if (count == 0) {
            head = tail = node;
        } else {
            head->previous = node;
        }
        head = node;
    } else if (index == count) {
        Node* node = new Node(e);
        node->previous = tail;
        if (count == 0) {
            head = tail = node;
        } else {
            tail->next = node;
        }
        tail = node;
    } else {
        Node* current = head;
        while (index > 1) {
            current = current->next;
            index -= 1;
        }
        Node* node = new Node(e);
        node->previous = current;
        node->next = current->next;
        current->next = node;
        node->next->previous = node;
    }
    count += 1;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
