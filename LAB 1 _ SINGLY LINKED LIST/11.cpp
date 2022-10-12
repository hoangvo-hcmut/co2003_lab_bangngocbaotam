LLNode* replaceFirstGreater(LLNode* head) {
    LLNode* current = head;
    while (current) {
        int originalVal = current->val;
        current->val = 0;
        LLNode* index = current->next;
        while (index) {
            if (index->val > originalVal) {
                current->val = index->val;
                break;
            }
            index = index->next;
        }
        current = current->next;
    }
    return head;
}
