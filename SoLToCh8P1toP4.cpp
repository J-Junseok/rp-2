/*
   HW NUMBER: 5
   FILE NAME : SoLToCh8P1toP4.cpp
   AUTHOR : ��ǻ�Ͱ��а� 2�г� C311159 ���ؼ�
   YYYYMMDD : 2024.05.13.
   PURPOSE : HW5 ; 8�� �ǽ����� 1*, 2, 3*, 4
*/

#include <iostream>
#include <string>
using namespace std;

// 8-1*, 8-2
class Circle {	// �⺻Ŭ���� Circle
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }	// ������ . radius���� . ����Ʈ�� 0
	int getRadius() { return radius; }					// radius ����
	void setRadius(int radius) { this->radius = radius; }	// radius ����
	double getArea() { return 3.14 * radius * radius; };	// area ����
};

class NamedCircle : public Circle {		// �Ļ�Ŭ���� NamedCircle : Circle�� ��� 
	string name;
public:
	NamedCircle(int radius, string name);	// ������
	void set(int radius, string name) {		// NamedCircle ����
		setRadius(radius);				// �⺻Ŭ������ setRadius �Լ��� radius ����
		this->name = name;				// name ����
	}
	string getName() { return name; }	// name ����
	void show();						// NamedCircle ��ü ���� ���
};

NamedCircle::NamedCircle(int radius = 0, string name = "NONAME") : Circle(radius) {
	// ������ . ����Ʈ�� radius=0 , name="NONAME" . radius�� Circle ������ �ڵ� ȣ�⿡ ���� �˾Ƽ� ����
	this->name = name;
}

void NamedCircle::show() {
	cout << "�������� " << getRadius() << "�� " << name << endl;
}

string biggest(NamedCircle p[], int n) {
	if (n <= 0)
		return ""; // ����
	// Find the biggest pizza
	int big = 0;	// ���� ū ���� index
	for (int i = 0; i < n; i++) {
		if (p[i].getRadius() > p[big].getRadius()) big = i;
	}
	return p[big].getName();
}

// P3,4 class definition
class Point {	// �⺻Ŭ���� Point
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }	// ������
	int getX() { return x; }	// x ����
	int getY() { return y; }	// y ����
protected:
	void move(int x, int y) { this->x = x; this->y = y; }	// (x,y) ����
};

class ColorPoint : public Point {	// �Ļ�Ŭ���� ColorPoint : Point�� ���
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }				// (x,y) ���� . ��ӹ��� move �Լ�
	void setColor(string color) { this->color = color; }	// color ����
	void show() {											// ColorPoint ��ü ���� ���
		cout << color << "������ " << '(' << getX() << ',' << getY() << ')' << "�� ��ġ�� ���Դϴ�." << endl;
	}
};


int main() {
	// P1,2 main() codes
	NamedCircle c[5];	// ��ü �迭 ����
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {		// 5���� NamedCircle ��ü�� ���ʷ� ����
		int r;
		string name;
		cout << i + 1 << ">> ";
		cin >> r;
		getline(cin, name);
		if (r <= 0) {	// ����
			cout << "�ٽ� �Է��ϼ���" << endl;
			i--;		// i�ε��� �ٽ� �Է�
			continue;
		}
		c[i].set(r, name);
	}
	cout << "���� ������ ū ���ڴ� " << biggest(c, 5) << "�Դϴ�" << endl;
	cout << endl;

	// P3 main() codes
	ColorPoint cp1(5, 5, "RED");
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();
	cout << endl;

	// P4 main() codes
	ColorPoint zeroPoint;	// ����Ʈ�� x=0, y=0, color="BLACk"
	zeroPoint.show();		// zeroPoint ��ü ���� ���

	ColorPoint cp(5, 5);	// ����Ʈ�� color="BLACk"
	cp.setPoint(10, 20);	// cp ��ü ��ǥ ����
	cp.setColor("BLUE");	// cp ��ü color ����
	cp.show();				// cp ��ü ���� ���

	// ���α׷� ����
	return 0;
}