#include <bits/stdc++.h>
// #define DEBUG_POP
// #define DEBUG_POPLEFT
// #define DEBUG_APPEND
// #define DEBUG_APPENDLEFT
// #define DEBUG_REMOVE

using namespace std;

template <typename T> class Node {
  public:
    T value;
    Node<T> *prev, *next;

    Node() {
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T> class LinkedList {
  public:
    Node<T> *headNode;
    Node<T> *lastNode;

    LinkedList() {
        this->headNode = nullptr;
        this->lastNode = nullptr;
    }

    void append(T value) {
        Node<T> *newNode = new Node<T>(value);

        if (this->headNode == nullptr && this->lastNode == nullptr) {
            this->lastNode = newNode;
            this->headNode = lastNode;
#ifdef DEBUG_APPEND
            this->debug();
#endif
            return;
        }

        newNode->prev = this->lastNode;
        this->lastNode->next = newNode;
        this->lastNode = newNode;

#ifdef DEBUG_APPEND
        this->debug();
#endif
    }

    void appendleft(T value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = this->headNode;
        this->headNode = newNode;

        if (this->lastNode == nullptr) {
            this->lastNode = headNode;
        }

#ifdef DEBUG_APPENDLEFT
        this->debug();
#endif
    }

    void remove(Node<T> *del) {
        if (del == nullptr) {
            cout << "Not found\n";
            return;
        }
        if (del == this->headNode) {
            this->headNode = del->next;
        } else if (del == this->lastNode) {
            this->lastNode = lastNode->prev;
        } else {
            del->prev->next = del->next;
            del->next->prev = del->prev;
        }
        delete del;
#ifdef DEBUG_REMOVE
        this->debug();
#endif
    }

    T popleft() {
        if (this->headNode == nullptr || this->lastNode == nullptr) {

#ifdef DEBUG_POPLEFT
            cout << "Tried to pop from empty list\n";
#endif
            return -1;
        }

        // 要素が最後の一つだけ
        if (this->headNode == this->lastNode) {
            T value = this->headNode->value;

            this->headNode = nullptr;
            this->lastNode = nullptr;

            delete this->headNode;

#ifdef DEBUG_POPLEFT
            cout << "You popped the last element!\n";
            this->debug();
#endif
            return value;
        }

        Node<T> *del = this->headNode; // 削除するアドレス
        T value = this->headNode->value;

        this->headNode = this->headNode->next;
        delete del;

#ifdef DEBUG_POPLEFT
        this->debug();
#endif
        return value;
    }

    T pop() {
        if (this->lastNode == nullptr || this->lastNode == nullptr) {

#ifdef DEBUG_POP
            cout << "Tried to pop from empty list\n";
            this->debug();
#endif
            return -1;
        }

        // 要素が最後の一つだけ
        if (this->lastNode == this->headNode) {
            T value = this->lastNode->value;

            //delete this->headNode;
            delete this->lastNode;

            this->headNode = nullptr;
            this->lastNode = nullptr;

#ifdef DEBUG_POP
            cout << "You popped the last element!\n";
            this->debug();
#endif
            return value;
        }
        
        Node<T> *del = this->lastNode;
        T value = del->value;
        
        this->lastNode->prev->next = nullptr;
        this->lastNode = this->lastNode->prev;
        
        delete del;

#ifdef DEBUG_POP
        this->debug();
#endif
        return value;
    }

    void insert(size_t index, T value) {
        if (index < 0) return;

        Node<T> *newNode = new Node<T>(value);

        if (index == 0) {
            newNode->next = this->headNode;
            this->headNode = newNode;
        } else {
            Node<T> *prevNode = getPointerAt(index - 1);
            if (prevNode == nullptr) return;
            // oldNode の繋げ先のノードをメモして繋ぎ変える
            prevNode->next = newNode;
            newNode->next = prevNode->next;
        }
    }

    size_t size() {
        if (this->empty()) return 0;
        size_t count = 1;
        Node<T> *current = this->headNode;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    Node<T> *getPointerof(T value) {
        if (this->headNode == nullptr || this->lastNode == nullptr)
            return nullptr;
        Node<T> *current = this->headNode;
        while (current != nullptr) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node<T> *getPointerAt(size_t index) {
        if (this->headNode == nullptr || this->lastNode == nullptr)
            return nullptr;
        Node<T> *current = this->headNode;
        for (size_t i = 0; i < index; i++) {
            if (current == nullptr) return nullptr;
            current = current->next;
        }
        return current;
    }

    T get(size_t index) {
        if (this->headNode == nullptr || this->lastNode == nullptr) return -1;
        if (this->empty()) return -1;
        Node<T> *p = this->getPointerAt(index);
        if (p == nullptr) return -1;
        return p->value;
    }

    void debug() {
        Node<T> *current = this->headNode;

        bool isEmpty = true;

        while (current != nullptr) {
            isEmpty = false;
            cout << current->value << " ";
            current = current->next;
        }

        if (!isEmpty) {
            cout << "\n";
            cout << "headNodeAddress=" << this->headNode << ", "
                 << "lastNodeAddress=" << this->lastNode << "\n";
            cout << "headNode=" << this->headNode->value << ", "
                 << "lastNode=" << this->lastNode->value << "\n";
            return;
        }

        cout << "Empty list\n";
    }
};
