template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{

  /*
      Constructor of iterator
      * Set pList to pList
      * begin = true:
      * * Set current (index = 0) to pList's head if pList is not NULL
      * * Otherwise set to NULL (index = -1)
      * begin = false:
      * * Always set current to NULL
      * * Set index to pList's size if pList is not NULL, otherwise 0
  */
  this->pList = pList;
  if (begin)
  {
    if (pList != nullptr)
    {
      index = 0;
      current = pList->head;
    }
    else
    {
      current = nullptr;
      index = -1;
    }
  }
  else
  {
    current = nullptr;
    if (pList != nullptr)
    {
      index = pList->size();
    }
    else
    {
      index = 0;
    }
  }
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
  /*
      Assignment operator
      * Set this current, index, pList to iterator corresponding elements.
  */
  current = iterator.current;
  index = iterator.index;
  pList = iterator.pList;
  return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
  /*
      Remove a node which is pointed by current
      * After remove current points to the previous node of this position (or node with index - 1)
      * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
      * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
  */
    if (current == nullptr)
  {
    throw std::out_of_range("Segmentation fault!");
  }
  this->pList->removeAt(index);
  if (index == 0) {
      current = nullptr;
      index = -1;
  } else {
      index -= 1;
      current = this->pList->head;
     for (int i = 0; i < index; i += 1) {
         current = current->next;
     }  
  }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
  /*
      Set the new value for current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == nullptr)
    throw std::out_of_range("Segmentation fault!");
  current->data = e;
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
  /*
      Get data stored in current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == nullptr)
    throw std::out_of_range("Segmentation fault!");
  return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
  /*
      Operator not equals
      * Returns false if two iterators points the same node and index
  */
  return !(this->index == iterator.index && this->current == iterator.current);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
  /*
      Prefix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  current = current->next;
  index += 1;
  return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
  /*
      Postfix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  SLinkedList<T>::Iterator iterator = *this;
  ++*this;
  return iterator;
}
