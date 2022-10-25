#include "./Stack.h"
#include <iostream>
using namespace std;

int main() {
  Stack<int> s = Stack<int>();
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  s.print();

  cout << "pop: " << s.pop() << endl;
  cout << "pop: " << s.pop() << endl;
  s.print();

  cout << "peek: " << s.peek() << endl;

  cout << "size: " << s.size() << endl;

  s.push(5);
  s.push(6);

  cout << "contain 10: " << s.contains(10) << endl;
  cout << "contain 5: " << s.contains(5) << endl;

  cout << "remove 10: " << s.remove(10) << endl;
  cout << "remove 5: " << s.remove(5) << endl;
  s.print();

  cout << "empty: " << s.empty() << endl;

  cout << "clear: " << endl;
  s.clear();
  s.print();

  cout << "empty: " << s.empty() << endl;
}