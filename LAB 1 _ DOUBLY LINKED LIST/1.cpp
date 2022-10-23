Deque::Deque() {
    head = tail = nullptr;
    curSize = 0;
}

Deque::~Deque() {
    clear();
}

void Deque::clear() {
    while (head != nullptr) {
        Node* next = head->right;
        delete head;
        head = next;
    }
    head = tail = nullptr;
    curSize = 0;
}

int Deque::getSize() {
    return curSize;
}

void Deque::pushFront(int i) {
   curSize += 1;
   Node* node = new Node(i, nullptr, head);
   if (head != nullptr) {
       head->left = node;
   }
   head = node;
   if (tail == nullptr) tail = head;
}

void Deque::pushBack(int i) {
    curSize += 1;
    Node* node = new Node(i, tail, nullptr);
    if (tail != nullptr) {
        tail->right = node;
    }
    tail = node;
    if (head == nullptr) head = tail;
}

int Deque::popFront() {
    if (head == nullptr) return -1;
    curSize -= 1;
    int value = head->value;
    head = head->right;
    if (curSize == 0) {
        tail = nullptr;
    } else {
         head->left = nullptr;
    }
    return value;
}

int Deque::popBack() {
    if (tail == nullptr) return -1;
    curSize -= 1;
    int value = tail->value;
    tail = tail->left;
    if (curSize == 0) {
        head = nullptr;
    } else {
        tail->right = nullptr;
    }
    return value;
}

void Deque::printDequeReverse() {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->left;
   }
    cout << endl;
}

void Deque::printDeque() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->right;
    }
    cout << endl;
}
