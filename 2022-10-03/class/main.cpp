#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int getMaxLessThan(Node* head, int lessThan) {
    int max = -INT_MAX;
    while (head) {
        if (head->data > max && head->data < lessThan) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

class SLL {
public:
    Node* head1;
    Node* head2;
public:
    void insert(int* arr, int size, Node*&head) {
        Node* curr = nullptr;
        int expectedMod = &head == &head1;
        for (int i = 0; i < size; i += 1) {
            if (arr[i] % 2 != expectedMod) continue;
             if (!curr) {
                if (!head) {
                    head = new Node();
                    curr = head;
                } else {
                    head->next = curr = new Node();
                }
            } else {
                curr->next = new Node{0, nullptr};
                curr = curr->next;
            }
            curr->data = arr[i];
        }
    };

    Node* merge(int size) {
        Node* res = nullptr;
        Node* curr = nullptr;
        int maxVal = INT_MAX;
        while (size > 0) {
            if (!curr) {
                curr = new Node{};
                res = curr;
            } else {
                curr->next = new Node{};
                curr = curr->next;
            }
            int max1 = getMaxLessThan(head1, maxVal);
            int max2 = getMaxLessThan(head2, maxVal);
            maxVal = max(max1, max2);
            curr->data = maxVal;
            size -= 1;
        }
        return res;     
    }
};

void printHead(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
   SLL sll = SLL();
   sll.insert(new int[6]{1,3,7,5,8,10}, 6, sll.head1);
   sll.insert(new int[5]{2,6,4,11,13}, 5, sll.head2);
   printHead(sll.head1);
   cout << endl;
   printHead(sll.head2);
   cout << endl;
   printHead(sll.merge(4));
}