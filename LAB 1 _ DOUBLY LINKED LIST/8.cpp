/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int l, int r) {
        if(!head || !head->right || l==r)
            return head;

        ListNode* prev = nullptr;
        ListNode* current = nullptr;
        
        for (int i = 0; i < l; i+=1) {
            if (current == nullptr) current = head;
            else {
                prev = current;
                current = current->right;
            };
        }
        
        ListNode* start = current;
        for (int i = l; i < r; i += 1) {
            current = current->right;
        }
        ListNode* end = current;
        
        if (prev != nullptr) {
            prev->right = end;
        } else {
            // is head
            head = end;
        }
        if (end->right) {
            end->right->left = start;
        } else {
        }
        
        prev = end->right;
        while (start != end) {
            ListNode* next = start->right;
            start->right = prev;
            start->left = next;
            prev = start;
            start = next;
        }
        start->right = prev;
        
        return head;
}
