#include <iostream>
using namespace std;
class Matrix5x5
{

public:
    double number[5][5] = {0};
    void set(int row, int col, double value)
    {
        number[row][col] = value;
    }
    double get(int row, int col)
    {
        return number[row][col];
    }
    Matrix5x5 operator+(Matrix5x5 &m2)
    {
        Matrix5x5 temp;
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++)
            temp.number[i][j]=this->number[i][j]+m2.number[i][j];
        }
        return temp;
    }
};

void print(Matrix5x5 & matrix) {
	for (int row = 0; row < 5; ++ row) {
		for (int col = 0; col < 5; ++ col) {
			cout << matrix.get(row, col) << ' ';
		}
		cout << endl;
	}
}

int main() {
	Matrix5x5 m1, m2, m3;
	double value;
	cin >> value;
	m1.set(0, 0, value);
	cin >> value;
	m1.set(4, 4, value);
	cin >> value;
	m2.set(0, 0, value);
	cin >> value;
	m2.set(3, 3, value);
	m3 = m1 + m2;
	print(m3);
}