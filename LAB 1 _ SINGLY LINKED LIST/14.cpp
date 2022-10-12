void LinkedList::replace(LinkedList* linked_list, int low, int high) {
    if (low < 0) low = 0;
    Node* current = head;
    Node* prevLow = nullptr;
    int index = 0;
    while (index < low) {
        prevLow = current;
        current = current->next;
        index += 1;
    }
    
    if (prevLow != nullptr) {
       prevLow->next = linked_list->head;
    } else {
       head = linked_list->head;
    }
    
    Node* currHigh = current;
    while (index < high) {
       currHigh = currHigh->next;
       index += 1;
    }
    
    if (currHigh) {
        linked_list->tail->next = currHigh->next;
    } else {
        tail = linked_list->tail;
    }
    // size = low + linked_list->size + (size - high);
}
