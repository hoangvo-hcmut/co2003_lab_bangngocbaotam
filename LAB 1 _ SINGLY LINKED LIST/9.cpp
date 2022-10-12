template <class T>
T SLinkedList<T>::removeAt(int index)
{
  count -= 1;
  if (index == 0)
  {
    int val = head->data;
    head = head->next;
    if (count == 0)
      head = tail = nullptr;
    return val;
  }
  else
  {
    Node *prev = nullptr;
    Node *current = head;
    while (index > 0)
    {
      prev = current;
      current = current->next;
      index -= 1;
    }
    prev->next = current->next;
    if (current == tail)
    {
      tail = prev;
    }
    return current->data;
  }
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
  /* Remove the first apperance of item in list and return true, otherwise return false */
  Node *prev = nullptr;
  Node *current = head;
  while (current)
  {
    if (current->data == item)
    {
      if (current == head) {
        head = head->next;
      } else if (current == tail) {
        tail = prev;
      } else {
        prev->next = current->next;
      }
      count -= 1;
      return true;
    }
    prev = current;
    current = current->next;
  }
  return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
      Node* current = head;
  while (current) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = tail = nullptr;
  count = 0;
}

