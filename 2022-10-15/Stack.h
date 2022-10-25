// ke thua ideck
#include <iostream>
#include "./IDeck.h"
#include "./SLL.h"

using namespace std;

template <class T> class Stack : public IDeck<T> {
private:
  SLL<T> *list = new SLL<T>();

public:
  ~Stack() {
    delete this->list;
    list = nullptr;
  };
  void push(T item) { this->list->add(0, item); };
  T pop() { return this->list->removeAt(0); };
  T &peek() { return this->list->get(0); };
  bool empty() { return this->list->empty(); };
  int size() { return this->list->size(); };
  void clear() { return this->list->clear(); };
  bool remove(T item) {
    int deleted = false;
    while (this->contains(item)) {
      this->list->removeAt(this->list->indexOf(item));
      deleted = true;
    }
    return deleted;
  };
  bool contains(T item) { return this->list->contains(item); }

  void print() {
    for (int i = 0; i < this->size(); i += 1) {
      cout << this->list->get(i) << " ";
    }
    cout << endl;
  }
};