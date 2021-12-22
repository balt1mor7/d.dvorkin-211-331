#pragma once
class Matrix
{
	//������������ �������
private:
	int col, row;
	int* matrix;
protected:
	//
public:
	Matrix(); // ����������� �� ���������
	~Matrix(); // ����������

	void input(int tmp_row, int tmp_col); // ���� ������� � ����������
	void print(); // ����� �������
	int get_columns(); // ��������� �������
	int get_rows(); // ��������� ��������
	int get_elem(int i, int j); // ��������� ��������
	void mult_by_num(double num); // ��������� ������� �� �����
	int trace(); // ���� �������
	void sum(int matrix_2[], int row_2, int col_2); // ����� ������
	void mult(int matrix_2[], int row_2, int col_2); // ������������ ������
	int det(int rang, int matr[]); // ������������ �������

	int det_3(int matr[]);
	int* ret_matr();
};



