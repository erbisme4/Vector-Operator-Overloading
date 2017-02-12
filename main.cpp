//Evan Burkert
#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
	double x;
	double y;
	double z;
};

double magnitude (Vector v1) {

	return sqrt(v1.x*v1.x+v1.y*v1.y+v1.z*v1.z);
}

double vectorSum (Vector v1, Vector v2) {
	Vector v3;
	v3.x = v1.x+v2.x;
	v3.y = v1.y+v2.y;
	v3.z = v1.z+v2.z;

	return sqrt(v3.x*v3.x+v3.y*v3.y+v3.z*v3.z);
}

class CVector {
public:
	CVector() {
		x = y = z = 0;
	}
	CVector(double cx, double cy, double cz) {

		x = cx;
		y = cy;
		z = cz;

	}
	double magnitude(CVector vectorClass1) {
		return sqrt(vectorClass1.x*vectorClass1.x+vectorClass1.y*vectorClass1.y+vectorClass1.z*vectorClass1.z);
	}
	//accessor methods
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z;  }
	//setter methods
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setZ(double z) { this->z = z; }

	friend double dotProduct(CVector& vectorClass1, CVector& vectorClass2) {
		return (vectorClass1.getX()*vectorClass2.getX() + vectorClass1.getY()*vectorClass2.getY() + vectorClass1.getZ()*vectorClass2.getZ());

	}

protected:
	double x, y, z;
	friend ostream& operator<<(ostream& o, CVector& vectorClass1) {
		o << "(" << vectorClass1.x << ", " << vectorClass1.y << ", " << vectorClass1.z << ")" << endl;
		return o;
	}
	friend CVector operator+(const CVector& vectorClass1, const CVector& vectorClass2) {
		CVector vectorSum;
		vectorSum.x = vectorClass1.x+vectorClass2.x;
		vectorSum.y = vectorClass1.y+vectorClass2.y;
		vectorSum.z = vectorClass1.z+vectorClass2.z;
		return vectorSum;
	}
	friend CVector operator-(const CVector& vectorClass1, const CVector& vectorClass2) {
		CVector vectorSum;
		vectorSum.x = vectorClass1.x-vectorClass2.x;
		vectorSum.y = vectorClass1.y-vectorClass2.y;
		vectorSum.z = vectorClass1.z-vectorClass2.z;
		return vectorSum;
	}
	friend CVector operator+=(CVector& vectorClass1, const CVector& vectorClass2) {
		vectorClass1.x += vectorClass2.x;
		vectorClass1.y += vectorClass2.y;
		vectorClass1.z += vectorClass2.z;

		return vectorClass1;
	}
	friend CVector operator-=(CVector& vectorClass1, CVector& vectorClass2) {
		CVector vectorSum;
		vectorSum.x = vectorClass1.x-vectorClass2.x;
		vectorSum.y = vectorClass1.y-vectorClass2.y;
		vectorSum.z = vectorClass1.z-vectorClass2.z;
		vectorClass1.x = vectorSum.x;
		vectorClass1.y = vectorSum.y;
		vectorClass1.z = vectorSum.z;
		return vectorClass1;
	}
	friend CVector operator*(const CVector& vectorClass, const int k) {
		CVector scalarMultiple;

		scalarMultiple.x = vectorClass.x*k;
		scalarMultiple.y = vectorClass.y*k;
		scalarMultiple.z = vectorClass.z*k;
		return scalarMultiple;
	}
	friend CVector operator*(const int k, const CVector& vectorClass) {
		CVector scalarMultiple;

		scalarMultiple.x = vectorClass.x*k;
		scalarMultiple.y = vectorClass.y*k;
		scalarMultiple.z = vectorClass.z*k;
		return scalarMultiple;
	}
	friend CVector operator/(const CVector& vectorClass, const int k) {
		CVector scalarMultiple;

		scalarMultiple.x = vectorClass.x/k;
		scalarMultiple.y = vectorClass.y/k;
		scalarMultiple.z = vectorClass.z/k;
		return scalarMultiple;
	}
	friend CVector operator/(const int k, const CVector& vectorClass) {
		CVector scalarMultiple;

		scalarMultiple.x = vectorClass.x/k;
		scalarMultiple.y = vectorClass.y/k;
		scalarMultiple.z = vectorClass.z/k;
		return scalarMultiple;
	}
	
};

int main () {

	Vector v1;
	Vector v2;
	cout << "This will test the program's Structures" << endl;
	cout << "Enter components of the vector 1 separated by a single space (E.G. 4 5 6) :";
	cin >> v1.x >> v1.y >> v1.z;
	cout << "Enter components of the vector 2 separated by a single space (E.G. 4 5 6) :";
	cin >> v2.x >> v2.y >> v2.z;
	cout << "Vector 1 magnitude: " << magnitude(v1) << endl;
	cout << "Vector sum of 1 and 2 is: " << vectorSum(v1, v2) << endl;
	cout << "This will test the program's Classes" << endl;
	CVector vectorClass1(1, 7, 4);
	CVector vectorClass2(6, 9, 3);
	cout << "Vector 1: " << vectorClass1 << endl;
	cout << "Vector 2: " << vectorClass2 << endl;
	cout << "Vector 1 + Vector 2 = " << vectorClass1 + vectorClass2 << endl;
	cout << "Vector 1 - Vector 2 = " << vectorClass1 - vectorClass2 << endl;
	vectorClass1+=vectorClass2;
	cout << "Vector 1 += Vector 2: " << vectorClass1 << endl;
	cout << "Updated! Vector 1 = " << vectorClass1 << endl;
	vectorClass1-=vectorClass2;
	cout << "Vector 1 -= Vector 2: " << vectorClass1 << endl;
	cout << "Updated! Vector 1 = " << vectorClass1 << endl;
	cout << "Vector 1 * 5 = " << vectorClass1 * 5 << endl;
	cout << "Vector 2 / 2 = " << vectorClass2 / 2 << endl;
	cout << "Dot product of Vector1 and Vector2 = " << dotProduct(vectorClass1, vectorClass2) << endl;

	return 0;
}