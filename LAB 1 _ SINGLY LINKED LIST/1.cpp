LLNode *addLinkedList(LLNode *l0, LLNode *l1)
{
  if (l0 == nullptr && l1 == nullptr)
    return nullptr;
  LLNode *result = nullptr;
  LLNode *current = nullptr;
  int rem = 0;
  do
  {
    if (!current)
    {
      current = new LLNode();
      result = current;
    }
    else
    {
      current->next = new LLNode();
      current = current->next;
    }
    int a = (l0 != nullptr) ? l0->val : 0;
    int b = (l1 != nullptr) ? l1->val : 0;
    int c = rem + a + b;
    if (c >= 10)
    {
      rem = c / 10;
      c = c % 10;
    }
    else
    {
      rem = 0;
    };
    current->val = c;
    if (l0)
      l0 = l0->next;
    if (l1)
      l1 = l1->next;
  } while (l0 != NULL || l1 != NULL);

  if (rem > 0)
  {
    current->next = new LLNode(rem, NULL);
  }

  return result;
};
