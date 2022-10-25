#include "./IList.h"
#include <exception>

template <class T> class Node {
public:
  T val;
  Node<T> *next;

  Node(T val) {
    this->val = val;
    this->next = nullptr;
  }

  Node(T val, Node<T> *next) {
    this->val = val;
    this->next = next;
  }
};

template <class T> class SLL : public IList<T> {
private:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  int count = 0;

public:
  ~SLL() { clear(); };
  /* add(T e): append item "e" to the list
   */
  void add(T e) { return add(count, e); };

  /* add(int index, T e): insert item "e" at location "index";
   *      location is an integer started from 0
   */
  void add(int index, T e) {
    if (index < 0 || index > count) {
      throw std::out_of_range("");
    }
    if (index == 0) {
      this->head = new Node<T>(e, head);
      if (tail == nullptr)
        tail = head;
    } else {
      Node<T> *current = head;
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

  /* removeAt(int index): remove the item at location "index"
   *
   * return:
   *  >> the item stored at index
   *  >> throw an exception (std::out_of_range) if index is invalid
   */
  T removeAt(int index) {
    if (index < 0 || index > count) {
      throw std::out_of_range("");
    }
    count -= 1;
    if (index == 0) {
      int val = head->val;
      head = head->next;
      if (count == 0) {
        head = tail = nullptr;
      }
      return val;
    } else {
      Node<T> *prev = nullptr;
      Node<T> *current = head;
      while (index > 0) {
        prev = current;
        current = current->next;
        index -= 1;
      }
      prev->next = current->next;
      if (current == tail) {
        tail = prev;
      }
      return current->val;
    }
  };

  /* empty(): return true if the list is empty; otherwise, return false
   */
  bool empty() { return count == 0; };

  /* size(): return number of items stored in the list
   */
  int size() { return count; };

  /* clear(): make the list empty by clearing all data and putting the list to
   * the initial condition
   */
  void clear() {
    Node<T> *current = head;
    while (current) {
      Node<T> *next = current->next;
      delete current;
      current = next;
    }
    head = tail = nullptr;
    count = 0;
  };

  /* get(int index): return a reference to the item at location "index"
   *      if index is invalid, this function will throw an exception
   * "std::out_of_range"
   *
   * NOTE: programmers can change the item returned by this function
   */
  T &get(int index) {
    if (index >= count) {
      throw std::out_of_range("");
    }
    Node<T> *current = head;
    while (index) {
      current = current->next;
      index -= 1;
    }
    return current->val;
  };

  /* indexOf(T item): return the index of item
   *      if item is not found, then return -1
   */
  int indexOf(T item) {
    Node<T> *current = head;
    for (int i = 0; i < count; i += 1) {
      if (item == current->val)
        return i;
      current = current->next;
    }
    return -1;
  };

  /* contains(T item): return true if the list contains "item", else: return
   * false
   */
  bool contains(T item) { return (indexOf(item) != -1); };
};