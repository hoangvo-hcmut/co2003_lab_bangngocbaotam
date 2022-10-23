template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    Node* current = head;
    while (index > 0) {
        current = current->next;
        index -= 1;
    }
    int data = current->data;
    if (current->previous != nullptr) {
        current->previous->next = current->next;
    } else {
        // current is head
        head = current->next;
    }
    if (current->next != nullptr) {
        current->next->previous = current->previous;
    } else {
        // current is tail
        tail = current->previous;
    }
    count -= 1;
    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
     Node* current = head;
     int index = 0;
     while (current != nullptr) {
         if (current->data == item) {
             removeAt(index);
             return true;
         }
         current = current->next;
         index += 1;
     }
     return false;
}

template<class T>
void DLinkedList<T>::clear(){
    while (count > 0) {
        removeAt(0);
    }
}
