/*
 * a,b�ֱ�Ϊ����ĸ��������cΪС����������3
 * a+b+3c=100
 * 5a+2b+c=100
 * num=100-c*3
 * mon=100-c
 * ��ȥb�ó� a=(mon-2*num)/3
 * b=num-a;
 * ����AB�ķ�Χ��������ָ���
 */
#include <iostream>

using namespace std;

void fun1() {
    int a, b, c, num, mon, i;
    for (c = 0; c <= 33; c++) {
        num = 100 - 3 * c;
        mon = 100 - c;
        if ((mon - 2 * num) % 3 == 0)                        //AB���㷽����ʱ�������ȷ��
        {
            a = (mon - 2 * num) / 3;
            if (a < 0 || a > 16) continue;
            b = num - a;
            if (b < 0 || b > 40) continue;
            cout << "����:����" << a << "ֻ,ĸ��" << b << "ֻ,С��" << 3 * c << "ֻ" << endl;
        }
    }
}

//����a ĸ��b С��c
void fun2() {
    int a, b, c;
    for (a = 0; a <= 16; a++) {
        for (b = 0; b <= 40; b++) {
            c = 100 - a - b;
            if (!(c % 3) && c / 3 + b * 2 + a * 5 == 100) {
                cout << "����:����" << a << "ֻ,ĸ��" << b << "ֻ,С��" << c << "ֻ" << endl;
            }
        }
    }
}

int main() {
    cout << "����5Ԫ1ֻ��ĸ��2Ԫ1ֻ��С��1Ԫ3ֻ��Ҫ�����100Ԫ��100ֻ�������п������" << endl;
    cout << "��ѭ��" << endl;
    fun1();
    cout << "˫ѭ��" << endl;
    fun2();
    return 0;
}