int Train::allocate(int containerSize) {
  TrainCar* min = nullptr;
  int minIndex = 0;
  int index = 0;
  TrainCar* current = head;
  while (current) {
    if (current->remainingSpace >= containerSize) {
      if (min == nullptr || current->remainingSpace < min->remainingSpace) {
        min = current;
        minIndex = index;
      }
    }
    current = current->next;
    index += 1;
  }
  if (min == nullptr) return -1;
  min->remainingSpace -= containerSize;
  return minIndex;
}

int Train::totalRemainingSpace() {
  int sum = 0;
  TrainCar* current = head;
  while (current) {
    sum += current->remainingSpace;
    current=current->next;
  }
  return sum;
}
