#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void insert_at_index(int index, int value) {
        Node* new_node = new Node(value);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!current) throw out_of_range("Index out of bounds");
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    void delete_at_index(int index) {
        if (!head) throw out_of_range("Index out of bounds");
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!current || !current->next) throw out_of_range("Index out of bounds");
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    int return_size() {
        int count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    bool empty() {
        return head == NULL;
    }

    void rotate(int k) {
        if (!head || k <= 0) return;

        int length = return_size();
        k = k % length;
        if (k == 0) return;

        Node *fast = head, *slow = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* new_head = slow->next;
        slow->next = NULL;
        fast->next = head;
        head = new_head;
    }

    void reverse() {
        Node *prev = NULL, *current = head, *next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    void prepend(int value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    void merge(SinglyLinkedList& other_list) {
        if (!head) {
            head = other_list.head;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = other_list.head;
    }

    void interleave(SinglyLinkedList& other_list) {
        Node dummy(0);
        Node* tail = &dummy;
        Node *curr1 = head, *curr2 = other_list.head;

        while (curr1 || curr2) {
            if (curr1) {
                tail->next = curr1;
                tail = tail->next;
                curr1 = curr1->next;
            }
            if (curr2) {
                tail->next = curr2;
                tail = tail->next;
                curr2 = curr2->next;
            }
        }
        head = dummy.next;
    }

    int middle() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->data : -1; // Return -1 if the list is empty
    }

    int index_of(int value) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) return index;
            current = current->next;
            ++index;
        }
        return -1;
    }

    SinglyLinkedList split_at_index(int index) {
        if (index < 0) throw out_of_range("Index out of bounds");
        SinglyLinkedList new_list;
        if (index == 0) {
            new_list.head = head;
            head = NULL;
            return new_list;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!current) throw out_of_range("Index out of bounds");
            current = current->next;
        }

        new_list.head = current->next;
        current->next = NULL;
        return new_list;
    }

    void print_list() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.append(1);
    list.print_list();

    list.append(2);
    list.append(3);
    list.print_list();

    list.prepend(0);
    list.print_list();

    list.insert_at_index(2, 5);
    list.print_list();

    list.rotate(2);
    list.print_list();

    list.reverse();
    list.print_list();

    SinglyLinkedList other_list;
    other_list.append(6);
    other_list.append(7);
    list.merge(other_list);
    list.print_list();

    list.interleave(other_list);
    list.print_list();

    cout << "Middle element: " << list.middle() << endl;
    cout << "Index of 5: " << list.index_of(5) << endl;

    SinglyLinkedList new_list = list.split_at_index(3);
    cout << "Size of original list: " << list.return_size() << endl;
    cout << "Size of new list: " << new_list.return_size() << endl;

    list.print_list();
    new_list.print_list();

    return 0;
}
