#include "DoublyLinkedList.cpp"
#include <bits/stdc++.h>

LinkedList<int> appendleftTest() {
    cout << "appendleftTest called"
         << "\n";
    LinkedList<int> a;
    a.appendleft(1);
    a.appendleft(2);
    a.appendleft(3);
    a.appendleft(4);
    return a;
}

LinkedList<int> appendTest() {
    cout << "appendTest called"
         << "\n";
    LinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    return a;
}

LinkedList<int> removeTest() {
    cout << "removeTest called"
         << "\n";
    LinkedList<int> a;
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

LinkedList<int> popTest() {
    LinkedList<int> a;
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

LinkedList<int> popleftTest() {
    LinkedList<int> a = appendleftTest();
    a.popleft();
    a.popleft();
    a.popleft();
    a.popleft();
    return a;
}

int main() {
    // appendleftTest();
    // appendTest();
    // removeTest();

    popTest();
    // popleftTest();

    // insertTest();
}