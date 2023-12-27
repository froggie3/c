#include <bits/stdc++.h>

using namespace std;

template <typename T> class Node {
  public:
    T value;
    Node<T> *next;

    Node<T>(T value) {
        this->value = value;
        this->next = nullptr;
    }

    Node<T> &operator++() {
        if (this->next != nullptr) {
            this = this->next;
        }
        return *this;
    }
};

template <typename T> class LinkedList {
  public:
    LinkedList() {
        this->head = nullptr;
        endDummy.next = nullptr;
    }

    Node<T> endDummy;
    Node<T> begin() const { return *this->head; }
    Node<T> end() const { return endDummy; }

    void append(T value) {
        Node<T> *newNode = new Node<T>(value);

        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        Node<T> *lastNode = this->getLastNode();
        lastNode->next = newNode;
    }

    T pop() {
        if (this->head == nullptr) return -1;

        Node<T> *lastNode = this->getLastNode();
        T value = lastNode->value;

        if (this->head == lastNode) {
            this->head = nullptr;
        } else {
            Node<T> *previousNode = this->getNodeBefore(lastNode);
            previousNode->next = nullptr;
        }

        delete lastNode;
        return value;
    }

    void appendleft(T value) {
        Node<T> *newNode = new Node<T>(value);

        newNode->next = this->head;
        this->head = newNode;
    }

    T popleft() {
        if (this->head == nullptr) return -1;

        T value = this->head->value;
        this->head = this->head->next;
        return value;
    }

    void insert(size_t index, T value) {
        if (index < 0) return;

        Node<T> *newNode = new Node<T>(value);

        if (index == 0) {
            newNode->next = this->head;
            this->head = newNode;
        } else {
            Node<T> *prevNode = getPointerAt(index - 1);
            if (prevNode == nullptr) return;
            // oldNode の繋げ先のノードをメモして繋ぎ変える
            prevNode->next = newNode;
            newNode->next = prevNode->next;
        }
    }

    void remove(T value) {
        if (this->head == nullptr) return;

        Node<T> *current = this->head;
        Node<T> *previous = nullptr;

        while (current != nullptr) {
            if (current->value == value) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    // if previous is null, it means current is the head
                    this->head = current->next;
                }
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    T get(size_t index) {
        if (this->head == nullptr) return -1;

        Node<T> *current = this->head;
        for (size_t i = 0; i < index; i++) {
            if (current->next == nullptr) return -1;
            current = current->next;
        }
        return current->value;
    }
    size_t size() {
        if (this->head == nullptr) return 0;
        size_t count = 1;
        Node<T> *current = this->head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

  private:
    Node<T> *head;

    Node<T> *getLastNode() const {
        if (this->head == nullptr) return nullptr;

        Node<T> *current = this->head;

        while (current->next != nullptr) {
            current = current->next;
        }

        return current;
    }

    Node<T> *getPointerAt(size_t index) {
        if (this->head == nullptr) return nullptr;

        Node<T> *current = this->head;

        for (size_t i = 0; i < index; i++) {
            if (current == nullptr) return nullptr;
            current = current->next;
        }

        return current;
    }

    Node<T> *getNodeBefore(Node<T> *targetNode) {
        if (this->head == nullptr) return nullptr;

        Node<T> *current = this->head;

        while (current->next != targetNode) {
            current = current->next;
        }

        return current;
    }
};

int main() {
    // Instantiate a linked list of integers
    LinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);

    // Use a range-based for loop to iterate over the list
    for (auto const &node : intList) {
        cout << node.value << " ";
    }

    // Instantiate a linked list of strings
    LinkedList<string> strList;
    strList.append("apple");
    strList.append("orange");
    strList.append("banana");

    // Use a range-based for loop to iterate over the list
    for (auto const &node : strList) {
        cout << node.value << " ";
    }
}
