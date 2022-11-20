template <class T>
void SLinkedList<T>::bubbleSort()
{
    int i = 0;
    Node* curr = head;
    while (curr != tail) {
        Node* curr2 = head;
        int j = 0;
        while (j < size()-i-1) {
            if (curr2->data > curr2->next->data) {
                T temp = curr2->data;
                curr2->data = curr2->next->data;
                curr2->next->data = temp;
            }
            curr2 = curr2->next;
            j += 1;
        }
        printList();
        curr = curr->next;
        i += 1;
    }
}
