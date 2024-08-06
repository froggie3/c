#include "DoublyLinkedList.cpp"
#include <bits/stdc++.h>

DoublyLinkedList<int> appendleftTest() {
    cout << "appendleftTest called"
         << "\n";
    DoublyLinkedList<int> a;
    a.appendleft(1);
    a.appendleft(2);
    a.appendleft(3);
    a.appendleft(4);
    return a;
}

DoublyLinkedList<int> appendTest() {
    cout << "appendTest called"
         << "\n";
    DoublyLinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    return a;
}

DoublyLinkedList<int> removeTest() {
    cout << "removeTest called"
         << "\n";
    DoublyLinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.remove(a.getPointerof(1));
    a.remove(a.getPointerof(2));
    a.remove(a.getPointerof(3));
    a.remove(a.getPointerof(4));
    return a;
}

DoublyLinkedList<int> popTest() {
    DoublyLinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    return a;
}

DoublyLinkedList<int> popleftTest() {
    DoublyLinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.popleft();
    a.popleft();
    a.popleft();
    a.popleft();
    a.popleft();
    return a;
}

DoublyLinkedList<int> insertTest() {
    DoublyLinkedList<int> a;
    a.insert(0, 1);
    a.insert(0, 2); // [1, 2]
    DoublyLinkedList<int> b;
    b.insert(0, 3);
    b.insert(0, 4);
    return a;
}

int main() {
    // appendleftTest();
    // appendTest();
    // removeTest();
    // popTest();
    // popleftTest();
    // insertTest();

    DoublyLinkedList<int> a;
    a.append(5);
    a.append(2);
    a.append(3);
    a.append(1);
    a.remove(a.getPointerof(3));
    a.append(6);
    a.remove(a.getPointerof(5));
    a.popleft();
    a.pop();
    a.debug();
}
