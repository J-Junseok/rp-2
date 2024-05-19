/*
   HW NUMBER: 5
   FILE NAME : SoLToCh8P1toP4.cpp
   AUTHOR : 컴퓨터공학과 2학년 C311159 정준석
   YYYYMMDD : 2024.05.13.
   PURPOSE : HW5 ; 8장 실습문제 1*, 2, 3*, 4
*/

#include <iostream>
#include <string>
using namespace std;

// 8-1*, 8-2
class Circle {	// 기본클래스 Circle
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }	// 생성자 . radius설정 . 디폴트값 0
	int getRadius() { return radius; }					// radius 리턴
	void setRadius(int radius) { this->radius = radius; }	// radius 설정
	double getArea() { return 3.14 * radius * radius; };	// area 리턴
};

class NamedCircle : public Circle {		// 파생클래스 NamedCircle : Circle을 상속 
	string name;
public:
	NamedCircle(int radius, string name);	// 생성자
	void set(int radius, string name) {		// NamedCircle 설정
		setRadius(radius);				// 기본클래스의 setRadius 함수로 radius 설정
		this->name = name;				// name 설정
	}
	string getName() { return name; }	// name 리턴
	void show();						// NamedCircle 객체 정보 출력
};

NamedCircle::NamedCircle(int radius = 0, string name = "NONAME") : Circle(radius) {
	// 생성자 . 디폴트값 radius=0 , name="NONAME" . radius는 Circle 생성자 자동 호출에 의해 알아서 설정
	this->name = name;
}

void NamedCircle::show() {
	cout << "반지름이 " << getRadius() << "인 " << name << endl;
}

string biggest(NamedCircle p[], int n) {
	if (n <= 0)
		return ""; // 오류
	// Find the biggest pizza
	int big = 0;	// 가장 큰 피자 index
	for (int i = 0; i < n; i++) {
		if (p[i].getRadius() > p[big].getRadius()) big = i;
	}
	return p[big].getName();
}

// P3,4 class definition
class Point {	// 기본클래스 Point
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }	// 생성자
	int getX() { return x; }	// x 리턴
	int getY() { return y; }	// y 리턴
protected:
	void move(int x, int y) { this->x = x; this->y = y; }	// (x,y) 설정
};

class ColorPoint : public Point {	// 파생클래스 ColorPoint : Point를 상속
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }				// (x,y) 설정 . 상속받은 move 함수
	void setColor(string color) { this->color = color; }	// color 설정
	void show() {											// ColorPoint 객체 정보 출력
		cout << color << "색으로 " << '(' << getX() << ',' << getY() << ')' << "에 위치한 점입니다." << endl;
	}
};


int main() {
	// P1,2 main() codes
	NamedCircle c[5];	// 객체 배열 선언
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {		// 5개의 NamedCircle 객체를 차례로 설정
		int r;
		string name;
		cout << i + 1 << ">> ";
		cin >> r;
		getline(cin, name);
		if (r <= 0) {	// 오류
			cout << "다시 입력하세요" << endl;
			i--;		// i인덱스 다시 입력
			continue;
		}
		c[i].set(r, name);
	}
	cout << "가장 면적이 큰 피자는 " << biggest(c, 5) << "입니다" << endl;
	cout << endl;

	// P3 main() codes
	ColorPoint cp1(5, 5, "RED");
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();
	cout << endl;

	// P4 main() codes
	ColorPoint zeroPoint;	// 디폴트값 x=0, y=0, color="BLACk"
	zeroPoint.show();		// zeroPoint 객체 정보 출력

	ColorPoint cp(5, 5);	// 디폴트값 color="BLACk"
	cp.setPoint(10, 20);	// cp 객체 좌표 설정
	cp.setColor("BLUE");	// cp 객체 color 설정
	cp.show();				// cp 객체 정보 출력

	// 프로그램 종료
	return 0;
}