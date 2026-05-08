// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& val) {
        Node* newNode = new Node(val);

        if (head == nullptr || val.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* cur = head;
        while (cur->next != nullptr && cur->next->data.prior > val.prior) {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Queue is empty");
        }

        Node* temp = head;
        T res = head->data;
        head = head->next;
        delete temp;
        return res;
    }

    bool empty() const {
        return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
