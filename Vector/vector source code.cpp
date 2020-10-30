#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Vector
{
	double x;
	double y;
};

//function prototypes

void display_menu();
void get_values(Vector&, Vector&, int &);
void cal_add(Vector, Vector);
void cal_sub(Vector, Vector);
void scalar_mul(Vector, int);
void scalar_prod(Vector, Vector);
void norm(Vector);

int main()
{
	Vector vector_1;
	Vector vector_2;
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
				get_values(vector_1, vector_2, choice);
				cal_add(vector_1, vector_2);
				break;
			case 2:
				get_values(vector_1, vector_2, choice);
				cal_sub(vector_1, vector_2);
				break;
			case 3:
				get_values(vector_1, vector_2, choice);
				scalar_mul(vector_1, choice);
				break;
			case 4:
				get_values(vector_1, vector_2, choice);
				scalar_prod(vector_1, vector_2);
				break;
			case 5:
				get_values(vector_1, vector_2, choice);
				norm(vector_1);
				break;
			case 6:
				cout << "Ending the promgram... Press enter.\n";
				return 0;
				break;
		}
		cout << endl;
		cout << "Would you like to perform another calculation? (Y/N)" << endl;
		cin >> ans;
		while( ans != 'Y' & ans != 'y' & ans != 'n' & ans != 'N')
		{	
			cout << endl;
			cout << "Invalid Input. Press Y or N.";
			cin >> ans;
		}
		system("cls");
	}while (ans == 'Y' || ans == 'y');
	return 0;
}

//function definition

void display_menu()
{
	cout << "\t\t================================\n";
	cout << "\t\t=====  VECTOR CALCUALTOR  ======\n";
	cout << "\t\t================================\n";
	cout << endl;
	cout << "\tChoose one of the following calculation:\n";
	cout << "\t1. Vector Addition.\n";
	cout << "\t2. Vector Subtraction.\n";
	cout << "\t3. Scalar Multiplication.\n";
	cout << "\t4. Inner Product.\n";
	cout << "\t5. Magnitude (Norm).\n";
	cout << "\t6. Quit.\n";
	cout << endl;
};

void get_values(Vector &v1, Vector &v2, int &choice)
{
	if (choice == 1 || choice == 2 || choice == 4)
	{
		cout << "Enter the first element of vector A: ";
		cin >> v1.x;
		cout << "Enter the second element of vector A: ";
		cin >> v1.y;
		cout << "Enter the first element of vector B: ";
		cin >> v2.x;
		cout << "Enter the second element of vector B: ";
		cin >> v2.y;
	}
	else if (choice == 3)
	{
		cout << "Enter the first element of vector A: ";
		cin >> v1.x;
		cout << "Enter the second element of vector A: ";
		cin >> v1.y;
		cout << "Enter a scalar integer: ";
		cin >> choice;
	}
	else
	{
		cout << "Enter the first element of vector A: ";
		cin >> v1.x;
		cout << "Enter the second element of vector A: ";
		cin >> v1.y;
	}
};

/* The Vector Addition function adds the first element of each vector and the
second element of each vector */
void cal_add(Vector v1, Vector v2)
{
	cout << endl;
	cout << "Vector Addition: "; 
	cout << "(" << v1.x + v2.x << ", " << v1.y + v2.y << ")" << endl;
};

/* The Vector Subtraction function subtracts the first element of each vector
and the second element of each vector */
void cal_sub(Vector v1, Vector v2)
{
	cout << endl;
	cout << "Vector Subtraction: ";
	cout << "(" << v1.x - v2.x << ", " << v1.y - v2.y << ")" << endl;
};

/* The Scalar Multiple function multiplies both elements of Vector 1 by an 
integer */
void scalar_mul(Vector v1, int k)
{
	cout << endl;
	cout << "Scalar Multiplication: ";
	cout << "(" << v1.x * k << ", " << v1.y * k << ")" << endl;
};

/* The Scalar Product function adds the multiplication of the first element of
each vector and the multiplication of the second element of each vector */
void scalar_prod(Vector v1, Vector v2)
{
	cout << endl;
	cout << "Scalar Product: ";
	cout << "(" << (v1.x * v2.x) + (v1.y * v2.y) << ")" << endl;
};

/* The Magnitude of a Vector function square roots the addition of the square 
of each element in Vector 1 */
void norm(Vector v1)
{
	int x;
	x = v1.x * v1.x + v1.y * v1.y;
	cout << endl;
	cout << fixed << setprecision(2);
	cout << "Magnitude: " << sqrt(x) << endl;
};

