#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;
//тз: создать функцию, которая на вход примит 2 лямбда функции. п первой л функции найти сумму идексов символос строки, второй функции на вход подаётся 4 числа, отсортировать их
void itog_funk(string str, int a, int b, int c, int d, int(*n1)(string), string(*n2)(int, int, int, int)) {

    cout << "Сумма индексов строки \"" << str << "\" = " << n1(str) << endl;
    
    cout << "Вот отсортированые 4 числа в порядке возрастания: " << n2(a, b, c, d) << endl;
 }

void osn1() {
    

    auto n1 = [](string str) {
        int itog = 0;
        for (int a : str) {
            itog += a;
        }
        return itog;
    };

    auto n2 = [](int a, int b, int c, int d) {
        int tmp_int;
        string itog;
        int tmp_arr[4] = { a, b, c, d };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (tmp_arr[i] >= tmp_arr[j]) {
                    continue;
                }
                else {
                    tmp_int = tmp_arr[j];
                    tmp_arr[j] = tmp_arr[i];
                    tmp_arr[i] = tmp_int;
                }
            }
        }
        for (int a : tmp_arr) {
            itog += std::to_string(a);
            itog += ' ';
        }
        return itog;
    };

    string some_str = "string";
    int a = 42;
    int b = 999;
    int c = 1;
    int d = 3;

    itog_funk(some_str, a, b, c, d, n1, n2);
}

int main(){
    setlocale(0, "ru");
    osn1();
    return 0;
}
