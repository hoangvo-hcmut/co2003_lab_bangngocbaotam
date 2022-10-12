LLNode* rotateLinkedList(LLNode* head, int k) {
    if (k == 0 || !head) return head;
    LLNode* current = head;
    int count = 0;
    while (true) {
        count += 1;
        if (current->next == nullptr) {
            // current is tail
            // link with head
            current->next = head;
            break;
        }
        current = current->next;
    }
    k = k % count;
    // current at tail
    for (int i = 0; i < count-k; i += 1) {
         current = current->next;
    }
    LLNode* result = current->next;
    current->next = nullptr;
    return result;
}
