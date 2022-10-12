LLNode* foldLinkedList(LLNode* head) {
    LLNode* current = head;
    int len = 0;
    while (current) {
        len+=1;
        current=current->next;
    }
    if (len == 0) return nullptr;
    int * arr = new int[len];
    int i = 0;
    while (head) {
        arr[i] = head->val;
        head=head->next;
        i += 1;
    }
    int mid = len / 2;
    LLNode* result = new LLNode();
    current = nullptr;
    if (len % 2 != 0) {
        current = result;
        current->val = arr[mid];
        mid += 1;
    };
    while (mid < len) {
        int sum = arr[mid] + arr[len-mid-1];
        if (!current) {
            current = result;
            current->val = sum;
        } else {
            current->next= new LLNode(sum, nullptr);
            current = current->next;
        }
        mid += 1;
    }
    return result;
}
