#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Matrix
{
       double a[2][2];
       double b[2][2];
};

           	   
//function prototypes 
void display_menu();
void get_matrix(Matrix&, Matrix&, int&);
void calc_sum(Matrix, Matrix);
void calc_diff(Matrix, Matrix);
void scalar_mult(Matrix, double);
void calc_prod(Matrix, Matrix);
void calc_inv(Matrix);

int main()
{
    int i;
    int j;
    Matrix m1;
    Matrix m2;
   	int choice = 0;
	char ans;
	
	do
	{
		display_menu();
		cout << "Enter one option from 1-6\n";
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
				get_matrix(m1, m2, choice);
				calc_sum(m1, m2);
				break;
			case 2:
				get_matrix(m1, m2, choice);
				calc_diff(m1, m2);
				break;
			case 3:
                get_matrix(m1, m2, choice);
				scalar_mult(m1, choice);
				break;
			case 4:
		  	    get_matrix(m1, m2, choice);
				calc_prod(m1, m2);
				break;
			case 5:
		 	    get_matrix(m1, m2, choice);
				calc_inv(m1);
				break;
			case 6:
				cout << "Ending the program... Press enter.\n";
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
	}while (ans == 'Y' || ans == 'y');
	return 0;
}

//function definition

void display_menu()
{
	cout << "\t\t================================\n";
	cout << "\t\t=====  MATRIX CALCULATOR  ======\n";
	cout << "\t\t================================\n";
	cout << endl;
	cout << "\tChoose one of the following calculations:\n";
	cout << "\t1. Matrix Addition.\n";
	cout << "\t2. Matrix Subtraction.\n";
	cout << "\t3. Scalar Multiplication.\n";
	cout << "\t4. Matrix Multiplication.\n";
	cout << "\t5. Inverse of a Matrix.\n";
	cout << "\t6. Quit.\n";
	cout << endl;
};

void get_matrix(Matrix &m1, Matrix &m2, int &choice)
{
	if (choice == 1 || choice == 2 || choice == 4)
	{
		cout << "Enter the elements of Matrix 1: ";
		for (int i = 0; i<2; i++ ) {
            for (int j = 0; j < 2; j++ ) {
               cin >> m1.a[i][j];
               }
        }
		cout << "Enter the elements of Matrix 2: ";
		for (int i = 0; i<2; i++ ) {
            for (int j = 0; j < 2; j++ ) {
               cin >> m2.b[i][j];
           	   } 
         }
    }
	else if (choice == 3)
	{
		cout << "Enter the elements of Matrix 1: ";
		for (int i = 0; i<2; i++ ) {
            for (int j = 0; j < 2; j++ ) {
               cin >> m1.a[i][j];
               }
        }
	}
	else
	{
        cout << "Enter the elements of Matrix 1: ";
		for (int i = 0; i<2; i++ ) {
            for (int j = 0; j < 2; j++ ) {
               cin >> m1.a[i][j];
               }
        }
	}
};

void calc_sum(Matrix m1, Matrix m2)
{
    double sum[2][2];
	cout << endl;
	cout << "Matrix Addition: " << endl;
	for (int i = 0;i < 2;i++ ) {
      for (int j = 0;j < 2;j++ ) {
        sum[i][j]= m1.a[i][j] + m2.b[i][j];
        cout<< sum[i][j] << "\t" ;
        }
        cout << "\n";
     }
};

void calc_diff(Matrix m1, Matrix m2)
{
     double diff[2][2];
     cout << endl;
     cout << "Matrix Subtraction: " << endl;
     for (int i = 0;i < 2;i++ ) {
         for (int j = 0;j < 2;j++ ) {
             diff[i][j]= m1.a[i][j] - m2.b[i][j];
             cout<< diff[i][j] << "\t" ;
         }
         cout << "\n";
     }
};

void scalar_mult(Matrix m1, double k)
{	
    cout << "Enter a scalar integer: ";
		cin >> k;
    double k_m[2][2];
    cout << endl;
	cout << "Scalar Multiplication: " << endl;
	for (int i = 0;i < 2;i++ ) {
         for (int j = 0;j < 2;j++ ) {
             k_m[i][j]= m1.a[i][j] * k;
            cout<< k_m[i][j] << "\t" ;
         }
         cout<< "\n";
     }
};

void calc_prod(Matrix m1, Matrix m2)
{
    cout << endl;
	cout << "Matrix Multiplication: " << endl;
    cout << m1.a[0][0] * m2.b[0][0] + m1.a[0][1] * m2.b[1][0] << setw(10) << 
            m1.a[0][0] * m2.b[0][1] + m1.a[0][1] * m2.b[1][1] << endl;
    cout << m1.a[1][0] * m2.b[0][0] + m1.a[1][1] * m2.b[1][0] << setw(10) <<
            m1.a[1][0] * m2.b[0][1] + m1.a[1][1] * m2.b[1][1] << endl;              

};

void calc_inv(Matrix m1)
{
     double determinant;
     cout << endl;
        determinant = m1.a[0][0] * m1.a[1][1] - m1.a[1][0] * m1.a[0][1];
       
    cout<<"determinant: " << determinant;
    
    cout<<"\n\nInverse of matrix is: \n";    
    cout << setprecision(2) << (m1.a[1][1]/determinant) << setw(10) << setprecision(2) << (-m1.a[0][1]/determinant) << endl;
    cout << setprecision(2) << (-m1.a[1][0]/determinant) << setw(10) << setprecision(2) << (m1.a[0][0]/determinant) << endl;
     
};
