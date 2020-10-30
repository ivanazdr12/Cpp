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
void enqueue(node *& head, node *&tail, int data);
void dequeue(node *&head, node *& tail);
void top(node *& head);
void display(node *& head);
bool isEmpty(node *& head);

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
                cout << "Enter the value you want to add to the queue: ";
                cin >> data;
                enqueue(head,tail,data);
                break;
            case 2:
                dequeue(head,tail);
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
                
            cout << "Enter a choice from 1-6" << endl;
        }
    } while(choice != 6);
    
    return 0;
}

//Function definitions
//Menu function
int menu() {
    int choice;
    cout << "\t\t================================\n";
	cout << "\t\t=====  QUEUES LINKED LIST ======\n";
	cout << "\t\t================================\n";
	cout << endl;
	cout << "\tChoose one of the following:\n";
	cout << "\t1. Enqueue.\n";
	cout << "\t2. Dequeue\n";
	cout << "\t3. Display top\n";
	cout << "\t4. Display Queue\n";
	cout << "\t5. Check if queue is empty\n";
	cout << "\t6. Quit\n";
   cout << "Enter your choice from 1-6" << endl;
    scanf("%d",&choice);
    return choice;
}

//Enqueue element function
void enqueue(node *& head, node *&tail, int data) {
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

//Dequeue element function
void dequeue(node *&head, node *& tail) {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        
    } else if (head == tail) {
        // Case when there is only 1 element in the queue
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
void top(node *& head) {
    if (head == NULL) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "The top value is " << head->data << endl;
    }
}

//Check if queue is empty function
bool isEmpty(node *& head) {
    if(head == NULL) {
        cout << "Queue is empty." << endl;
        return true;
        
    } else {
        cout << "Queue is not empty" << endl;
        return false;
    }
}

//Display the whole queue function
void display(node *& head)
{
    if (head == NULL) {
        cout << "Queue is empty." << endl;
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
