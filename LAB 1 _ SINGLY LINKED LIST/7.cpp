template <class T>
void SLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list. */
  if (!tail)
    head = tail = new SLinkedList::Node(e, nullptr);
  else
  {
    tail->next = new SLinkedList::Node(e, nullptr);
    tail = tail->next;
  }
  count += 1;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index. */
  if (index == 0)
  {
    head = new SLinkedList::Node(e, head);
    if (!tail)
      tail = head;
  }
  else
  {
    SLinkedList::Node *current = head;
    while (index > 1)
    {
      current = current->next;
      index -= 1;
    }
    current->next = new SLinkedList::Node(e, current->next);
    if (current == tail)
      tail = current->next;
  }

  count += 1;
}

template <class T>
int SLinkedList<T>::size()
{
  return count;
}
