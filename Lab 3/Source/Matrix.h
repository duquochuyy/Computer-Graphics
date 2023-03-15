#pragma once

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Header.h"

/*
m00		m01		m02
m10		m11		m12
m20		m21		m22
*/

// doi tuong matrix de luu ma tran bien doi hinh
class Matrix {
private:
	vector<vector<double>> mMatrix;
public:
	Matrix() {
		mMatrix.assign(3, vector<double>(3, 0));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mMatrix[i][j] = (i == j) ? 1 : 0;
	}
	Matrix(double m00, double m01, double m10, double m11, double m02, double m12) {
		mMatrix[0][0] = m00;		mMatrix[0][1] = m01;		mMatrix[0][2] = m02;
		mMatrix[1][0] = m10;		mMatrix[1][1] = m11;		mMatrix[1][2] = m12;
		mMatrix[2][0] = 0;			mMatrix[2][1] = 0;			mMatrix[2][2] = 1;
	}
	~Matrix() {}
	vector<vector<double>> Elements() {
		return mMatrix;
	}
	void Reset() {
		mMatrix.assign(3, vector<double>(3, 0));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mMatrix[i][j] = (i == j) ? 1 : 0;
	}
	void Invert() {

	}
	void Rotate(double degree) {
		mMatrix[0][0] = cos(degree * PI / 180);		mMatrix[0][1] = -sin(degree * PI / 180);
		mMatrix[1][0] = sin(degree * PI / 180);		mMatrix[1][1] = cos(degree * PI / 180);
	}
	void Translate(double dx, double dy) {
		mMatrix[0][2] = dx;
		mMatrix[1][2] = dy;
	}
	void Scale(double sx, double sy) {
		mMatrix[0][0] = sx;
		mMatrix[1][1] = sy;
	}
	void Shear(double hx, double hy) {
		mMatrix[1][0] = hx;
		mMatrix[0][1] = hy;
	}
	// 3x3 * 3x1 = 3x1
	vector<int> Multiply(vector<int> other) {
		vector<int> result(3, 0);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result[i] += mMatrix[i][j] * other[j];
			}
		}
		return result;
	}
	/*
		pX
		pY
		1
	*/
	pair<int, int> TransformPoint(pair<int, int> point) {
		vector<int> old(3, 0);
		old[0] = point.first;
		old[1] = point.second;
		old[2] = 1;
		vector<int> result = Multiply(old);
		pair<int, int> pointResult = make_pair(result[0], result[1]);
		return pointResult;
	}
	vector<pair<int, int>> TransformPoints(vector<pair<int, int>> points) {
		vector<pair<int, int>> pointsResult(points.size());
		for (int i = 0; i < points.size(); i++) {
			pointsResult[i] = TransformPoint(points[i]);
		}
		return pointsResult;
	}
};

#endif
