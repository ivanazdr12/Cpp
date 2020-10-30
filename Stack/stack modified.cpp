#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 20;

//define structure
struct Stack
{
    int i[SIZE];
    int top;
};

//function prototypes
void display_menu();
void push_item(Stack&);
void pop_item(Stack&);
void display_top(Stack&);
void check_empty(Stack&);
void purge_stack(Stack&);

int main()
{
    Stack s;
    s.top = -1;
    int choice = 0;
    char ans;
    
    do
    {
        display_menu();
        cout << "Enter one option from 1-6.\n";
        cin >> choice;
        while(cin.fail() || choice < 1 || choice > 6 )
        {
            cin.clear();
            cin.ignore(99, '\n');
            cout << "Invalid Input.\n";
            cout << "Choose one of the above options: ";
            cin >> choice;
        }
        switch(choice)
        {
            case 1:
                push_item(s);
                break;
            case 2:
                pop_item(s);
                break;
            case 3:
                display_top(s);
                break;
            case 4:
               check_empty(s);
                break;
            case 5:
                purge_stack(s);
                break;
            case 6:
                cout << "Ending the program... Press enter.\n";
                return 0;
                break;
        }
        cout << endl;
        cout << "Would you like to choose another option? (Y/N)" << endl;
        cin >> ans;
        while( ans != 'Y' & ans != 'y' & ans != 'n' & ans != 'N')
        {
            cout << endl;
            cout << "Invalid Input. Press Y or N.";
            cin >> ans;
        }
//        system("cls");
    } while (ans == 'Y' || ans == 'y');
    return 0;
}

//function definitions

void display_menu()
{
    cout << "\t\t================================\n";
    cout << "\t\t=====  STACK  ======\n";
    cout << "\t\t================================\n";
    cout << endl;
    cout << "\tChoose one of the following options:\n";
    cout << "\t1. Push Onto Stack.\n";
    cout << "\t2. Pop Off Stack.\n";
    cout << "\t3. Display Top of Stack.\n";
    cout << "\t4. Check if stack is empty.\n";
    cout << "\t5. Purge Stack.\n";
    cout << "\t6. Quit.\n";
    cout << endl;
};

void push_item(Stack& s)
{
     int n;
     
     if(s.top==19)
               cout << "Stack is full.";              
     else {
             cout << "Enter the value you want to push on stack: ";
             cin >> n;
             ++s.top;
             s.i[s.top] = n;
             cout << n << " was inserted on stack." << endl;
      }
};

void pop_item(Stack& s)
{
    if(s.top==-1)
        cout<< "Stack is empty. No elements to pop."<<endl;
    else
        cout << s.i[s.top] << " was deleted.";
    --s.top;
    cout << endl;
};

void display_top(Stack& s)
{
    cout << endl;
    if(s.top==-1)
        cout << "Stack is empty. No top to display." << endl;
    else
        cout << s.i[s.top] << " is the top.";
    cout << endl;
};

void check_empty(Stack& s)
{
    if(s.top==-1)
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl; 
     
};

void purge_stack(Stack& s)
{
     if(s.top==-1)
          cout << "Stack is empty. There are no elements to purge." << endl;
          else
             s.top=-1; 
             cout<< "Stack is destroyed." << endl;
     }
