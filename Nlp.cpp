#include <iostream>
using namespace std;

class Matrix
{
private:
 int rows;
 int columns;
 double * data;
 
public:
 ~Matrix()
 {
	 delete []data;
 }
 Matrix(int rows, int columns, double values[]) {
	 this->rows = rows;
	 this->columns = columns;
	 this->data = new double[rows * columns];
	 for (int i = 0; i < rows * columns; ++i)
		 this->data[i] = values[i];
 }
  Matrix& concatenateRows(const Matrix & matrix2) {
	 int index1=this->rows*this->columns;
	 int index2=matrix2.rows*matrix2.columns;
	 double *temp=new double[index2+index1];
	 for (int i=0;i<index1;i++)
		 temp[i]=this->data[i];
	 this->rows+=matrix2.rows;
	 for (int i = index1,j=0; j<index2; ++ i,j++)
		 temp[i]=matrix2.data[j];
	 delete []this->data;
	 this->data=temp;
	 return *this;
 }
 Matrix& concatenateColumns(const Matrix & matrix2) {
	 int new_col=this->columns+matrix2.columns;
	 int new_size=new_col*matrix2.rows;
	 double *temp=new double[new_size];
	 int index=0,i=0,j=0;
	 int counts=1;
	 while(index<new_size)
	 {
		 while (i < columns * counts)
			 temp[index++] = this->data[i++];
		 while (j < matrix2.columns * counts)
			 temp[index++] = matrix2.data[j++];
		 counts++;
	 }
	 this->columns=new_col;
	 this->rows=matrix2.rows;
	 delete[] this->data;
	 this->data=temp;
	 return *this;
 }
 Matrix & transport()
 {
	int size=rows*columns;
	int index=0,p_pre=0;
	double *new_array=new double[size]; 
	for (int pre=p_pre;index<size;index++)
	{
		new_array[index]=data[pre];
		pre=(pre+columns)%size;
		if(pre==p_pre)
			pre=++p_pre;
	}
	delete[] data;
	int temp=rows;
	rows = columns;
	columns = temp;
	data = new_array;
	return *this;
 }

 Matrix & reshape(int row,int col)
 {
	 int size=row*col;
	 int index=0;
	 int p_cur=0;
	 int p_pre=0;
	 double *new_array=new double[size];
	 for(int cur=p_cur,pre=p_pre;index<size;index++)
	 {
		 new_array[cur]=data[pre];
		 cur=(cur+col)%size;
		 if(cur==p_cur)
			 cur=++p_cur;
		 pre=(pre+columns)%size;
		 if(pre==p_pre)
			 pre=++p_pre;
	 }
	 rows=row;
	 columns=col;
	 delete[] data;
	 data=new_array;
	 return *this;
 }
 Matrix operator*(const Matrix &matrix2)
 {
	 int size=rows*matrix2.columns,index=0;
	 double* new_array=new double[size];
	 while(index<size )
	 {
		 int m2=index%matrix2.columns,m1=index/matrix2.columns*columns,val=0;
		 for (int i=0;i<columns;i++)
			 val+=data[m1++]*matrix2.data[m2],m2+=matrix2.columns;
		 new_array[index++]=val;
	 }
	 auto an= Matrix(rows,matrix2.columns,new_array);
	 delete[] new_array;
	 return an;
 }
 Matrix operator*(double val)
 {
	 int size=rows*columns;
	 for (int i=0;i<size;i++)
		data[i]*=val;
	 return Matrix(rows,columns,data);
 }
 void print() 
 {
	 int index = 0;
	 for (int i = 0; i < this->rows; ++i)
	 {
		 for (int j = 0; j < this->columns; ++j)
		 {
			 cout << "    " << this->data[index++];
		 }
		 cout << endl;
	 }
 }
};
Matrix read() 
{
	int rows;
	int columns;
	double values[1000];
	cin >> rows >> columns;
	for (int i = 0; i < rows * columns; ++ i) {
		cin >> values[i];
	}
	Matrix matrix(rows, columns, values);
	return matrix;
}

int main() {
	Matrix matrix1 = read(); // calls copy constructor
	Matrix matrix2 = read();
	
	double value;
	cin >> value;
	
	matrix1.print();
	cout << endl;
	matrix2.print();
	cout << endl;
	
	Matrix matrix3 = matrix1 * matrix2;
	matrix3.print();
	cout << endl;
	
	Matrix matrix4 = matrix1 * value;
	matrix4.print();
	cout << endl;
}