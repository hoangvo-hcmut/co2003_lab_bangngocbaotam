template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node* current = head;
    while (index > 0) {
        current = current->next;
        index -= 1;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    Node* current = head;
    while (index > 0) {
        current = current->next;
        index -= 1;
    }
    current->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == item) return index;
        index += 1;
        current = current->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return (indexOf(item) != -1);
}
