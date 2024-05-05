#include <iostream>
#include <vector>
#include <string>
using std::endl;
using std::string;
using std::vector;
using std::cout;
using std::cin;
/*
3) вывести сумму цифр числа 129956
4) доказать, что может существовать треугольник со сторонами 34, 17, 98 
*/
void osn0() { //п4
    int num = 129956;
    int itog = 0;
    string str_num = std::to_string(num);
    for (int i = 0; i < 6; i++) {
        itog += str_num[i] - 48;
        cout << "итоговая сумма после итерации номер " << i+1 << " = " << itog << endl;
    }
    cout << "Сумма цифр числа 129956 = " << itog << endl;
}

void YesOrNo(int a, int b, int c) {
    if ((a > (b + c)) || (b > (a + c)) || (c > (a + b))) {
        cout << "Треугольник со сторонами: " << a << ' ' << b << ' ' << c << endl;
        cout << "Не существует(" << endl;
    }
    else {
        cout << "Треугольник со сторонами: " << a << ' ' << b << ' ' << c << endl;
        cout << "Существует!" << endl;
    }
}

void osn1() {// п4 немножечко креатива)
    bool UserChoise;
    cout << "Select:\n0 - Fast test mode\n1 - Manual mode" << endl;
    cin >> UserChoise;
    if (!UserChoise) {
        int a = 34;
        int b = 17;
        int c = 98;
        YesOrNo(a, b, c);
    }
    else {
        int a, b, c;
        cout << "Enter first side: ";
        cin >> a; 
        cout << endl;
        cout << "Enter second side: ";
        cin >> b; 
        cout << endl;
        cout << "Enter third side: ";
        cin >> c; 
        cout << endl;
        YesOrNo(a, b, c);
    }
}

int main() {
    setlocale(0, "ru");
    osn0();
    osn1();
    return 0;
}
