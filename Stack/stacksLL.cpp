#include<iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* head;
node* tail;

//Function prototypes
int menu();
void push(node *&head, node *&tail, int data);
void pop(node *&head, node *&tail);
void top(node *&head);
void display(node *&head);
bool isEmpty(node *&head);

int main() {
    
    node* head;
    node* tail;
    
    head = NULL;
    tail = NULL;
    int choice;
    
    do {
        choice = menu();
        
        switch(choice) {
            case 1:
                int data;
                cout<<"Enter the value you want to add to the stack: ";
                cin>>data;
                push(head,tail,data);
                break;
            case 2:
                pop(head,tail);
                break;
            case 3:
                top(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                isEmpty(head);
                break;
            case 6:
                cout << "Ending the program... Press enter.\n";
				return 0;
                break;
                
            default: printf("\nEnter a choice from 1-6");
        }
    } while(choice != 6);
    
    return 0;
}

int menu() {
    int choice;
    cout << "\t\t================================\n";
	cout << "\t\t=====  STACKS LINKED LIST ======\n";
	cout << "\t\t================================\n";
	cout << endl;
	cout << "\tChoose one of the following:\n";
	cout << "\t1. Push.\n";
	cout << "\t2. Pop\n";
	cout << "\t3. Display top\n";
	cout << "\t4. Display Stack\n";
	cout << "\t5. Check if stack is empty\n";
	cout << "\t6. Quit\n";
    cout << "Enter your choice from 1-6" << endl;
    scanf("%d",&choice);
    return choice;
}

//Push element function
void push(node *&head, node *&tail, int data) {
    if (head == NULL) {
        node* i= new node;
        
        i->data = data;
        i->next = NULL;
        
        head = i;
        tail = i;
        
    } else {
        node* i = new node;
        i->data = data;
        i->next = head;
        head = i;
    }
}

//Pop element function
void pop(node *&head, node *&tail) {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
        
    } else if (head == tail) {
        // Case when there is only 1 element in the stack
        cout << "The value " << head->data << " was removed." << endl;
        delete head;
        head = NULL;
        tail = NULL;
        
    } else {
        node* i = new node;
        i = head;
        head = head->next;
        cout << "The value " << i->data << " was removed." << endl;
        delete i;
    }
}

//Display top element function
void top(node *&head) {
    if (head == NULL) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "The top value is " << head->data << endl;
    }
}

//Check if stack is empty function
bool isEmpty(node *&head) {
    if(head == NULL) {
        cout << "Stack is empty." << endl;
        return true;
        
    } else {
        cout << "Stack is not empty" << endl;
        return false;
    }
}

//Display the whole stack function
void display(node *&head)
{
    if (head == NULL) {
        cout << "Stack is empty." << endl;
    } else {
         node *temp;
         temp=head;
          while(temp != NULL)
                     {
                        cout <<temp->data<< " ";
                        temp=temp->next;
                     }
    }
    
}
