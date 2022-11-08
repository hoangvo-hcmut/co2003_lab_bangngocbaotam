#include <iostream>
using namespace std;
template<typename T>
class SLL {
public:
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node(T data, Node* next = nullptr) {
            this->data=data;
            this->next=next;
        }
    friend class SLL<T>;
    };
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
    SLL() {
    
    }

  void add(T e) { return add(count, e); };

  /* add(int index, T e): insert item "e" at location "index";
   *      location is an integer started from 0
   */
  void add(int index, T e) {
    if (index < 0 || index > count) {
      throw std::out_of_range("");
    }
    if (index == 0) {
      this->head = new Node(e, head);
      if (tail == nullptr)
        tail = head;
    } else {
      Node *current = head;
      while (index > 1) {
        current = current->next;
        index -= 1;
      }
      current->next = new Node(e, current->next);
      if (current == tail) {
        tail = current->next;
      }
    }
    count += 1;
  };

    bool empty() { return count == 0; };

    int size() { return count; };

    void clear() {
        Node *current = head;
        while (current) {
        Node *next = current->next;
        delete current;
        current = next;
        }
        head = tail = nullptr;
        count = 0;
    };

    T &get(int index) {
        if (index >= count) {
            throw std::out_of_range("");
        }
        Node *current = head;
        while (index) {
            current = current->next;
            index -= 1;
        }
        return current->data;
    };

    void set(int index, T data) {
        if (index >= count) {
            throw std::out_of_range("");
        }
        Node *current = head;
        while (index) {
            current = current->next;
            index -= 1;
        }
        current->data = data;
    }

    int insertionSort() {
        int count = 0;
        for (int i = 1; i < size(); i ++) {
            T key = get(i);
            int j;
            for (j = i - 1; j >= 0 && get(j) > key; j -= 1) {
                set(j+1, get(j));
                count += 1;
            }
            set(j+1, key);
            print();
        }
        return count;
    }

    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    SLL<int> list;
    list.add(5);
    list.add(1);
    list.add(-2);
    list.add(4);
    list.add(3);
    cout << "initial: ";
    list.print();
    int count = list.insertionSort();
    cout << "swap count: " << count << endl;
    cout << "result: ";
    list.print();
}