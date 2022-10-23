/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from DLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
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
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    current = iterator.current;
  index = iterator.index;
  pList = iterator.pList;
  return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current == nullptr)
    throw std::out_of_range("Segmentation fault!");
  current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
     if (current == nullptr)
    throw std::out_of_range("Segmentation fault!");
  return current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
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

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
     return !(this->index == iterator.index && this->current == iterator.current);
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
     if (current == nullptr)
      {
        throw std::out_of_range("Segmentation fault!");
      }
    current = current->next;
    index += 1;
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
   DLinkedList<T>::Iterator iterator = *this;
  ++*this;
  return iterator;
}

