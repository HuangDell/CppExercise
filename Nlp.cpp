#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
template <typename T>
class Matrix
{
private:
	int rows;
	int columns;
	T *data;

	void _init(const int &rows, const int &columns, const vector<double> &values)
	{
		this->rows = rows;
		this->columns = columns;
		this->data = new T[rows * columns];
		for (int i = 0; i < rows * columns; ++i)
		{
			if (values.empty())
			{
				this->data[i] = 0;
				continue;
			}
			this->data[i] = values[i];
		}
	}
	void _init(const int &rows, const int &columns, const T *values)
	{
		this->rows = rows;
		this->columns = columns;
		this->data = new T[rows * columns];
		for (int i = 0; i < rows * columns; ++i)
		{
			if (values == NULL)
			{
				this->data[i] = 0;
				continue;
			}
			this->data[i] = values[i];
		}
	}

	int _index(int row, int column)
	{
		return (row - 1) * this->columns + (column - 1);
	}

public:
	Matrix(int rows, int columns)
	{
		this->_init(rows, columns, NULL);
	}

	Matrix(int rows, int columns, const vector<double> &values)
	{
		this->_init(rows, columns, values);
	}

	Matrix(const Matrix &matrix)
	{
		this->_init(matrix.rows, matrix.columns, matrix.data);
	}

	~Matrix()
	{
		delete[] this->data;
	}

	Matrix &operator=(const Matrix &matrix)
	{
		delete[] this->data;
		this->_init(matrix.rows, matrix.columns, matrix.data);
		return *this;
	}

	Matrix getRow(int row)
	{
		Matrix temp1(1, this->columns);
		for (int i = 0; i < this->columns; ++i)
			temp1.data[i] = this->data[(row - 1) * this->columns + i];
		return temp1;
	}

	Matrix getColumn(int col)
	{
		Matrix temp2(this->rows, 1);
		for (int i = 0; i < this->rows; ++i)
			temp2.data[i] = this->data[i * this->columns + col - 1];
		return temp2;
	}

	Matrix concatenateRows(Matrix m2)
	{
		Matrix m3(this->rows + m2.rows, this->columns);
		for (int i = 0; i < m3.rows * m3.columns; ++i)
		{
			if (i < this->rows * this->columns)
				m3.data[i] = this->data[i];
			else
				m3.data[i] = m2.data[i - this->rows * this->columns];
		}
		return m3;
	}

	Matrix concatenateColumns(Matrix m2)
	{
		Matrix m3(this->rows, this->columns + m2.columns);
		for (int i = 0; i < m3.rows; ++i)
		{
			for (int j = 0; j < m3.columns; ++j)
			{
				if (j < this->columns)
					m3.data[i * m3.columns + j] = this->data[i * columns + j];
				else
					m3.data[i * m3.columns + j] = m2.data[i * columns + j - this->columns];
			}
		}
		return m3;
	}

	Matrix reshape(int rows, int columns)
	{
		Matrix m2(rows, columns);
		int p = 0;
		int q = 0;
		for (int i = 0; i < columns; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				m2.data[i + j * columns] = this->data[p + q * this->columns];
				q++;
				if (q >= this->rows)
				{
					q = 0;
					p++;
				}
			}
		}
		return m2;
	}

	Matrix transpose()
	{
		Matrix m2(this->columns, this->rows);
		int p = 0;
		for (int i = 0; i < m2.columns; ++i)
		{
			for (int j = 0; j < m2.rows; ++j)
			{
				m2.data[i + j * m2.columns] = this->data[p];
				p++;
			}
		}
		return m2;
	}

	Matrix max()
	{
		if (this->rows > 1)
		{
			Matrix m2(1, this->columns);
			for (int i = 0; i < this->columns; ++i)
			{
				m2.data[i] = this->data[i];
				for (int j = 0; j < this->rows; ++j)
				{
					if (m2.data[i] < this->data[i + j * this->columns])
						m2.data[i] = this->data[i + j * this->columns];
				}
			}
			return m2;
		}
		else
		{
			Matrix m2(1, 1);
			m2.data[0] = this->data[0];
			for (int i = 0; i < this->columns; ++i)
			{
				if (m2.data[0] < this->data[i])
					m2.data[0] = this->data[i];
			}
			return m2;
		}
	}

	Matrix min()
	{
		if (this->rows > 1)
		{
			Matrix m2(1, this->columns);
			for (int i = 0; i < this->columns; ++i)
			{
				m2.data[i] = this->data[i];
				for (int j = 0; j < this->rows; ++j)
				{
					if (m2.data[i] > this->data[i + j * this->columns])
						m2.data[i] = this->data[i + j * this->columns];
				}
			}
			return m2;
		}
		else
		{
			Matrix m2(1, 1);
			m2.data[0] = this->data[0];
			for (int i = 0; i < this->columns; ++i)
			{
				if (m2.data[0] > this->data[i])
					m2.data[0] = this->data[i];
			}
			return m2;
		}
	}

	Matrix sum()
	{
		if (this->rows > 1)
		{
			Matrix m2(1, this->columns);
			for (int i = 0; i < this->columns; ++i)
			{
				for (int j = 0; j < this->rows; ++j)
					m2.data[i] += this->data[i + j * this->columns];
			}
			return m2;
		}
		else
		{
			Matrix m2(1, 1);
			for (int i = 0; i < this->columns; ++i)
				m2.data[0] += this->data[i];
			return m2;
		}
	}
	Matrix operator+(const Matrix &m2)
	{
		Matrix m3(this->rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i)
		{
			m3.data[i] = m2.data[i] + this->data[i];
		}
		return m3;
	}

	Matrix operator-(const Matrix &m2)
	{
		Matrix m3(this->rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i)
		{
			m3.data[i] = this->data[i] - m2.data[i];
		}
		return m3;
	}

	Matrix operator+(const double val)
	{
		Matrix m3(this->rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i)
		{
			m3.data[i] = this->data[i] + val;
		}
		return m3;
	}

	Matrix operator-(const double val)
	{
		Matrix m3(this->rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i)
		{
			m3.data[i] = this->data[i] - val;
		}
		return m3;
	}

	Matrix operator*(const Matrix &m2) const
	{
		Matrix m3(this->rows, m2.columns);
		for (int i = 0; i < m3.rows; ++i)
		{
			for (int j = 0; j < m3.columns; ++j)
			{
				for (int k = 0; k < this->columns; ++k)
					m3.data[i * m3.columns + j] += this->data[i * this->columns + k] * m2.data[j + k * m2.columns];
			}
		}
		return m3;
	}

	Matrix operator*(const double val) const
	{
		Matrix m3(this->rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i)
		{
			m3.data[i] = this->data[i] * val;
		}
		return m3;
	}

	void print()
	{
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->columns; ++j)
			{
				cout << "    " << this->get(i + 1, j + 1);
			}
			cout << endl;
		}
	}

	T &get(int row, int column)
	{
		return this->data[this->_index(row, column)];
	}
};

template <class T>
void print(vector<T> &vec, ostream &out = cout)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <class T>
ostream &operator<<(ostream &out, const vector<T> &vec)
{
	print(vec, out);
	return out;
}

int main()
{
	cout << "constructor 1" << endl;
	Matrix<double> matrix1(3, 3);
	matrix1.print();

	const double values1[] = {
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
	};
	vector<double> values2;
	for (int i = 0; i < 9; ++i)
	{
		values2.push_back(values1[i]);
	}

	cout << "constructor 2" << endl;
	Matrix<double> matrix2(3, 3, values2);
	matrix2.print();

	cout << "copy constructor" << endl;
	Matrix<double> matrix3 = matrix2;
	matrix3.print();

	cout << "operator =" << endl;
	matrix3.get(1, 1) = 10.0;
	matrix3 = matrix2;
	matrix3.print();

	cout << "getColumn" << endl;
	matrix2.getColumn(2).print();
	cout << "getRow" << endl;
	matrix2.getRow(2).print();

	cout << "concatenateRows" << endl;
	matrix1.concatenateRows(matrix2).print();
	cout << "concatenateColumns" << endl;
	matrix1.concatenateColumns(matrix2).print();

	cout << "reshape" << endl;
	matrix1.concatenateColumns(matrix2).reshape(6, 3).print();

	cout << "transpose" << endl;
	matrix2.transpose().print();
	cout << "operator +" << endl;
	(matrix2 + matrix2).print();
	cout << "operator +" << endl;
	(matrix2 + 10).print();
	cout << "operator -" << endl;
	(matrix2.transpose() - matrix2).print();
	cout << "operator -" << endl;
	(matrix2 - 10).print();

	cout << "operator *" << endl;
	(matrix2.transpose() * matrix2).print();
	cout << "operator *" << endl;
	(matrix2 * 2).print();

	cout << "max" << endl;
	cout << matrix2.max().max().get(1, 1) << endl;
	cout << "min" << endl;
	cout << matrix2.min().min().get(1, 1) << endl;
	cout << "sum" << endl;
	cout << matrix2.sum().sum().get(1, 1) << endl;
}