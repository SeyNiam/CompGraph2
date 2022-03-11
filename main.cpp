// �����������
// + �������
// + ����
// + ���������
// + ������� � ������
// + �����������
// + ���������
// + ��������������

#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#define P 3.14

using namespace std;


// ��������� ����� ��������
void drawLine(float x1, float y1, float x2, float y2, COLORREF cColor) {
    setcolor(cColor); // ���� 3 ��� 11
    line(x1, y1, x2, y2);
}


// ����� ��� �����
class Point {
public:
    float x;
    float y;
    char *name;

    void namePoint(char *name) {
        outtextxy(x, y, name);
    }
};


// ����� ������������
class Triangle {
public:
    Point A;
    Point B;
    Point C;
    char name_A[2] = "A";
    char name_B[2] = "B";
    char name_C[2] = "C";
    int col = 11; // ���� 11

    // �����������
    Triangle(){
        A.x = 20; A.y = 250;
        A.name = name_A;
        B.x = 400; B.y = 50;
        B.name = name_B;
        C.x = 100; C.y = 50;
        C.name = name_C;
        drawTriangle();
    }

    // ���������
    void drawTriangle() {
        A.namePoint(A.name);
        B.namePoint(B.name);
        C.namePoint(C.name);

        drawLine(A.x, A.y, B.x, B.y, col); // ����� 1
        drawLine(B.x, B.y, C.x, C.y, col); // ����� 2
        drawLine(A.x, A.y, C.x, C.y, col); // ����� 3
    }

    // ����������
    void moveX(float amt) {
        A.x += amt;
        B.x += amt;
        C.x += amt;
    }
    void moveY(float amt) {
        A.y += amt;
        B.y += amt;
        C.y += amt;
    }

    // �������
    void rotate(int u) { // u = -1 �� �������, u = 1 ������
        Point tmpA = A, tmpB = B, tmpC = C;
        float ang = u * 0.05; // ���� ��������

        Point Cen; // ����� ������ ������������
        Cen.x = (A.x+B.x+C.x) / 3;
        Cen.y = (A.y+B.y+C.y) / 3;

        A.x = A.x - Cen.x; // ���������� �� � �� ������ �� �
        A.y = A.y - Cen.y; // �� �
        B.x = B.x - Cen.x; // ���������� �� b �� ������ �� �
        B.y = B.y - Cen.y; // �� �
        C.x = C.x - Cen.x; // ���������� �� c �� ������ �� �
        C.y = C.y - Cen.y; // �� �

        // ������� ������ ��
        // A
        float tmpX = A.x * cos(ang) + A.y * sin(ang);
        float tmpY = -A.x * sin(ang) + A.y * cos(ang);
        A.x = tmpX + Cen.x;
        A.y = tmpY + Cen.y;
        // B
        tmpX = B.x * cos(ang) + B.y * sin(ang);
        tmpY = -B.x * sin(ang) + B.y * cos(ang);
        B.x = tmpX + Cen.x;
        B.y = tmpY + Cen.y;
        // C
        tmpX = C.x * cos(ang) + C.y * sin(ang);
        tmpY = -C.x * sin(ang) + C.y * cos(ang);
        C.x = tmpX + Cen.x;
        C.y = tmpY + Cen.y;
    }

    // ���������������
    void scale(float e) {
        Point Cen; // ����� ������ ������������
        Cen.x = (A.x + B.x + C.x) / 3;
        Cen.y = (A.y + B.y + C.y) / 3;

        if ((abs(A.x - Cen.x) >= 1 && abs(A.y - Cen.y) >= 1) && (abs(B.x - Cen.x) >= 1 && abs(B.y - Cen.y) >= 1) && 
            (abs(C.x - Cen.x) >= 1 && abs(C.y - Cen.y) >= 1) || e > 1) { // �������������� ������ � �����
            // A.x
            float xe = (Cen.x + A.x) / 2;
            float lx = Cen.x - A.x;
            lx = lx * e;
            A.x = xe - lx / 2;
            // A.y
            float ye = (Cen.y + A.y) / 2;
            float ly = Cen.y - A.y;
            ly = ly * e;
            A.y = ye - ly / 2;

            // B.x
            xe = (Cen.x + B.x) / 2;
            lx = Cen.x - B.x;
            lx = lx * e;
            B.x = xe - lx / 2;
            // B.y
            ye = (Cen.y + B.y) / 2;
            ly = Cen.y - B.y;
            ly = ly * e;
            B.y = ye - ly / 2;

            // C.x
            xe = (Cen.x + C.x) / 2;
            lx = Cen.x - C.x;
            lx = lx * e;
            C.x = xe - lx / 2;
            // C.y
            ye = (Cen.y + C.y) / 2;
            ly = Cen.y - C.y;
            ly = ly * e;
            C.y = ye - ly / 2;
        }

    }
};




int main()
{
    initwindow(1400, 700); // ������ ���������� ���� 1400 �� 700
    
    Triangle Tri; // �������� ������������

    // ����������
    int i = 1; // ������� ������
    while (i) {
        switch (getch()) {
        case 'w':
            cout << 'w' << endl;
            Tri.moveY(-10); // �����
            break;
        case 'a':
            cout << 'a' << endl;
            Tri.moveX(-10); // �����
            break;
        case 's':
            cout << 's' << endl;
            Tri.moveY(10); // ����
            break;
        case 'd':
            cout << 'd' << endl;
            Tri.moveX(10); // ������
            break;
        case 'q':
            cout << 'q' << endl;
            Tri.rotate(1); // ������ �������
            break;
        case 'e':
            cout << 'e' << endl;
            Tri.rotate(-1); // �� �������
            break;
        case '=':
            cout << '+' << endl;
            Tri.scale(1.5); // ����������
            break;
        case '-':
            cout << '-' << endl;
            Tri.scale(0.5); // ����������
            break;
        default:
            cout << "default -> exit" << endl;
            i = 0;
            break;
        }
        cleardevice(); // �������� ������
        Tri.drawTriangle(); // ����������� ������������
    }
    

    getch(); // ������ ������ ������� � ����������
    closegraph(); // ����������� ��� ������, ���������� ��� ����������� �������, ����� ��������������� ����� � �����, ������� ��� �� ������ initwindow

    return 0;
}