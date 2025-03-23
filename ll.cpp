#include<iostream>
using namespace std;

class node{
public : 
    int data;
    node *next;
};

class single_list{

    public:
        node *head;
        node *create_Node(){
            node *temp = new node;
            int value;
            cout << "Enter the value to be inserted : ";
            cin >> value;
            if(temp == NULL){
                cout << "Memory not allocated " << endl;
                return NULL;
            }else{
                temp->data = value;
                temp->next = NULL;
                return temp;
            }

        }
        void insert_begin(){
            node *temp = create_Node();
            if(head == NULL){
                head = temp;
                temp->next = NULL;
            }
            else{
                temp->next = head;
                head = temp;
            }
        }
        void insert_last(){
            node *s;
            node *temp = create_Node();
            s = head;
            while(s->next != NULL){
                s = s -> next;
            }
            temp -> next = NULL;
            s -> next = temp;
            cout << "Element inserted at last" << endl;

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
        void insert_pos(){

            node *temp = create_Node();
            int pos;
            cout << "Enter the position to insert : ";
            cin >> pos;
            if(pos == 1){
                temp -> next = head;
                head = temp;
                return ;
            }

            node *p = head;
            for(int i = 1; i < pos - 1  && pos != NULL; i++){
                p = p -> next ;
            }
            if(p != NULL){
                temp -> next = p -> next;
                p -> next = temp;
            }
            else {
                cout << "Position out of range" << endl;
            }
        };
        void display(){
            node *temp;
            if(head == NULL){
                cout << "List is empty" << endl;
            }
            temp = head; 
            cout << "Elements in the list are : ";
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        };

        single_list(){
            head = NULL;
        }


};

int main(){

    single_list list;
    int choice; 
    while(true){
        cout << "1. Insert at begining " << endl;
        cout << "2. Insert at last " << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete from position " << endl;
        cout << "5. Display " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1: list.insert_begin();
                    break;

            case 2: list.insert_last();
                    break;

            case 3 : list.insert_pos();
                    break;

            case 4 : list.delete_pos();
                    break;

            case 5 : list.display();
                    break;
            
            case 6 : exit(0);
        }
    }

}