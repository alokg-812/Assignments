// https://leetcode.com/submissions/detail/1342556360/

class MyLinkedList {
private:
    class Node {
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (size == 1) {
                tail = nullptr;
            }
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            if (index == size - 1) {
                tail = current;
            }
            delete temp;
        }
        size--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 