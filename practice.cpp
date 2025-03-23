#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class single_list {
    node* head;


    node* create_node() {
        node* temp = new node;
        int value;
        cout << "Enter the value to be inserted: ";
        cin >> value;
        if (temp == NULL) {
            cout << "Memory not allocated!" << endl;
            return NULL;
        } else {
            temp->data = value;
            temp->next = NULL;
            return temp;
        }
    }


    void insert_begin() {
        node* temp = create_node();
        if (head == NULL) {
            head = temp;
            head->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    }


    void insert_last() {
        node* temp = create_node();
        if (head == NULL) {
            head = temp;
        } else {
            node* p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }


    void insert_pos() {
        int pos;
        cout << "Enter the position to insert: ";
        cin >> pos;

        node* temp = create_node();
        if (pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }

        node* p = head;
        for (int i = 1; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }

        if (p != NULL) {
            temp->next = p->next;
            p->next = temp;
        } else {
            cout << "Position out of range!" << endl;
        }
    }


    void delete_pos() {
        int pos;
        cout << "Enter the position to delete: ";
        cin >> pos;

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
            return;
        }

        node* prev = NULL;
        for (int i = 1; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL) {
            prev->next = temp->next;
            delete temp;
        } else {
            cout << "Position out of range!" << endl;
        }
    }


    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

public:

    single_list() {
        head = NULL;
    }


    void insert_begin_user() {
        insert_begin();
    }


    void insert_last_user() {
        insert_last();
    }


    void insert_pos_user() {
        insert_pos();
    }


    void delete_pos_user() {
        delete_pos();
    }


    void display_user() {
        display();
    }
};

int main() {
    single_list list;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete from specific position\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.insert_begin_user();
                break;
            case 2:
                list.insert_last_user();
                break;
            case 3:
                list.insert_pos_user();
                break;
            case 4:
                list.delete_pos_user();
                break;
            case 5:
                list.display_user();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}