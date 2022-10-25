#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class SLL {
private:
    Node* head;
public:
    void insert(int * arr, int size) {
        Node* curr;
        if (!head) {
            head = new Node{arr[0], nullptr};
            curr = head;
        } else {
            for (int i = 1; i < size; i += 1) {
                curr->next = new Node{arr[i], nullptr};
                curr = curr->next;
            }
        }
    }

    void insertPos(int data, int pos) {
        Node* curr = head;
        if (pos == 0) {
            head = new Node{data, head->next};
            return;
        };
        while (pos > 1) {
            curr = curr->next;
            pos -= 1;
        }
        curr->next = new Node{data, curr->next ? curr->next->next : nullptr};
    }

    // k pai position lool
    void deletePos(int data) {

    }
};
