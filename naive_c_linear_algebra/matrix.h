#pragma once

#include <math.h>

#define MAX_ROW 5
#define MAX_COL 5
#define EPS 0.000000001

typedef struct {

	double matrix[MAX_ROW][MAX_COL];
	int row;
	int col;

}Matrix;


typedef struct {

	double vector[MAX_ROW];
	int row;

}Vector;

typedef struct {

	Matrix Matrix;
	Vector Vector;

}MatrixVector;

typedef struct {
	Matrix U;
	Matrix Sigma;
	Matrix V;
}SVD;

// �Է� ���� ��Į�� ���� ������ ���Ѵ�. (divided by zero ó����)
double Reciprocal(double a);

// matrix�� �����Ѵ�.
Matrix CloneMatrix(Matrix mat);

// vector�� �����Ѵ�.
Vector CloneVector(Vector vec);

// �� matrix�� ���Ѵ�.
Matrix MatrixByMatrix(Matrix mat1, Matrix mat2);

// matrix�� vector�� ���Ѵ�.
Vector MatrixByVector(Matrix mat, Vector vec);

// �Է� ���� ������ �׵������ ��ȯ�Ѵ�.
Matrix Identity(int len);

// matrix�� �� ���� scalar ���� ���մϴ�.
Matrix ScalarByMatrix(double scalar, Matrix mat);

// vector�� �� ���� scalar ���� ���մϴ�.
Vector ScalarByVector(double scalar, Vector vec);

// matrix�� matrix�� ���մϴ�.
Matrix MatrixPlusMatrix(Matrix mat1, Matrix mat2);

// matrix�� transpose �մϴ�.
Matrix Transpose(Matrix mat);

// matrix�� ��� ���� ������ ���մϴ�. (divide by zero ��ġ��)
Matrix MatrixReciprocal(Matrix mat);

// vector�� ��� ���� ������ ���մϴ�. (divide by zero ��ġ��)
Vector VectorReciprocal(Vector vec);

// ��� ���� 0�� (row, col) ũ���� matrix�� ����ϴ�.
Matrix Zeros(int row, int col);

// ��� ���� 1�� (row, col) ũ���� matrix�� ����ϴ�.
Matrix Ones(int row, int col);

// matrix�� eigenvector�� eigenvalue�� ���մϴ�. Matrix�� eigenvector��, Vector�� eigenvalue�� ����˴ϴ�.
MatrixVector Eigen(Matrix mat);

// matrix�� U, Sigma, V ������ Ư�̰� ���� �մϴ�.
SVD SingularValueDecomposition(Matrix mat);

// matrix�� ������� ���մϴ�. ����� ���� ���� ������ pseudo inverse�� ���մϴ�.
Matrix Inverse(Matrix mat);

// matrix�� ����մϴ�.
void PrintMatrix(Matrix mat);

// vector�� ����մϴ�.
void PrintVector(Vector vec);