#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Matrix
{
	public:
		int size;
    int** data;
        Matrix(int n) : size(n) 
		{
        data = new int*[size];
        for (int i = 0; i < size; ++i) 
		{
            data[i] = new int[size];
        }
    }
    void fillRandom() 
	{
        for (int i = 0; i < size; ++i) 
		{
            for (int j = 0; j < size; ++j) 
			{
                data[i][j] = rand()%10;
            }
        }
    }
     void print() 
	 {
        for (int i = 0; i < size; ++i) 
		{
            for (int j = 0; j < size; ++j) 
			{
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
     friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
};

Matrix operator+(const Matrix& m1, const Matrix& m2) 
{
    Matrix result(m1.size);
    for (int i=0;i<m1.size;i++) 
	{
        for (int j=0;j<m1.size;j++) 
		{
            result.data[i][j]=m1.data[i][j]+m2.data[i][j];
        }
    }
    return result;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) 
{
    Matrix result(m1.size);
    for (int i=0;i<m1.size;i++) 
	{
        for (int j=0;j<m1.size;j++) 
		{
            result.data[i][j]=m1.data[i][j]-m2.data[i][j];
        }
    }
    return result;
}
Matrix operator*(const Matrix& m1, const Matrix& m2) 
{
    Matrix result(m1.size);
    for (int i=0;i<m1.size;i++) 
	{
        for (int j=0;j<m1.size;j++) 
		{
            result.data[i][j]=m1.data[i][j]*m2.data[i][j];
        }
    }
    return result;
}
bool operator==(const Matrix& m1, const Matrix& m2) 
{
    for (int i=0;i<m1.size; i++) 
	{
        for (int j=0;j<m1.size; j++) 
		{
            if (m1.data[i][j]!=m2.data[i][j]) 
			{
                return false;
            }
        }
    }
    return true;
}
int main()
{
	srand(time(NULL));
	int n;
	cout<<"Input n: ";
	cin>>n;
	Matrix A(n),B(n),C(n);
	A.fillRandom();
	A.print();
	cout<<endl;
	B.fillRandom();
	B.print();
	cout<<endl<<"Suma: "<<endl;
	C=A+B;
	C.print();
	cout<<endl<<"Riznica: "<<endl;
	C=A-B;
	C.print();
	cout<<endl<<"Mnozenya: "<<endl;
	C=A*B;
	C.print();
	cout<<endl<<"Porivnynya: "<<endl;
	if (A==B) 
	{
        cout<<"Matrices are equal"<<endl;
    }
	else 
	{
        cout<<"Matrices are not equal"<<endl;
    }
	return 0;
}
