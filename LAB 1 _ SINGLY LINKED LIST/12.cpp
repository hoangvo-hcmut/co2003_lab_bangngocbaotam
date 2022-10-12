LLNode* reverseLinkedList(LLNode* head) {
    LLNode* prev = nullptr;
    LLNode* current = head;
    while (current) {
        LLNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
