/*
1)создать класс почтальона
- св-ва: имя, номер, кол-во доставленных писем, письма в наличии
- у всех объектов данного класса одно название почтового отделения
- функции:
-- доставка по указанному адресу (объект получает адрес и проверяет, есть ли письмо с данным адресом)
-- получение письма для доставки
- у каждого письма: адрес, ФИО

2) создать почтовое отделение
- название, адрес, почтальоны
- приходят клиенты и передают для отправки письма
- в письме реквизит от КОГО берётся из ФИО клиента
- эти письма передаются почтальонам для разноски
*/
#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Client {
public:
    string FIO;

    Client(string _FIO) {
        FIO = _FIO;
    }

    Client() {}
};

class Letter {
public:
    string adress;
    string from_who;

    Letter(string _adress, Client cl) {
        adress = _adress;
        from_who = cl.FIO;
    }

    Letter() {}
};

class Postman {
public:
    string working_post_office_name = "Oficerski"; //согласно тз, цитирую - "у всех объектов данного класса одно название почтового отделения"
    string name;
    unsigned int number;
    int delivered_letters_count = 0; //при создании - нуль; инкрумируется при успешной доставке письма
    vector<Letter> letters;

    Postman(int _number, string _name) {
        number = _number;
        name = _name;
    }

    Postman() {}

    void show_all_postman_stats() { //вывод всех характеристик почтальона
        cout << "Имя: " << name << ", номер: " << number << ", работает в " << working_post_office_name << endl;
        cout << "Колличество уже доставленных писем: " << delivered_letters_count << endl;
        if (size(letters)) {
            cout << "Письма в наличии:" << endl;
            for (Letter a : letters) {
                int iterator = 0;
                cout << "Письмо №" << iterator << ". Адрес письма: " << a.adress << ". От кого: " << a.from_who << endl;
                iterator++;
            }
        }
        else {
            cout << "Не имеет писем в наличии" << endl;
        }
    }

    void letter_send(string _adress) { //честно вам говорю: конкретно этот метод был взят у chatGPT, однако я его детально изучил и пости полностью понял
        int tmp_counter = 0;
        for (auto it = letters.begin(); it != letters.end(); ) {
            if (it->adress == _adress) {
                cout << endl << "Письмо от " << it->from_who << " доставлено по адресу " << it->adress << endl << endl; 
                it = letters.erase(it); //только эту строчку не особо понял
                delivered_letters_count++;
                tmp_counter++;
            }
            else {
                ++it;
            }
        }
        if (!tmp_counter) {
            cout << "Нет писем по указанному адресу" << endl;
        }
    }
};

class Post_office {
public:
    string post_office_name;
    string post_office_adress;
    Postman postmans[10];
    vector<Letter> letters_storage;

    Post_office(string _post_office_name, string _post_office_adress) {
        post_office_name = _post_office_name;
        post_office_adress = _post_office_adress;
    }

    void get_letter(Letter l) { //получение письма от клиента
        letters_storage.push_back(l);
    }
    void give_letter() { //раздача всех писем за раз рандомно всем почтальонам, вывод информации о почтальонах, а так же доставка писем
        for (Letter l : letters_storage) {
            int a = rand() % 10;
            postmans[a].letters.push_back(l);
            cout << "Письмо было полученно данным почтальоном:" << endl;
            postmans[a].show_all_postman_stats();// вывод статов почтальона
            postmans[a].letter_send("Some adress");// отправыка всех писем по адресу "Some adress" 
            postmans[a].show_all_postman_stats(); // повторный вывод статов почтальона
        }
    }

};

void osn0() {
    Client Drujko_Oleg_Petrovic("Drujko Oleg Petrovic");

    Letter l1("Some adress", Drujko_Oleg_Petrovic);

    Postman dave(1, "Dave");
    Postman james(2, "James");
    Postman oscar(3, "Oscar");
    Postman ellis(4, "Ellis");
    Postman archer(5, "Archer");
    Postman jack(6, "Jack");
    Postman julian(7, "Julian");
    Postman sawyer(8, "Sawyer");
    Postman wesley(9, "Wesley");
    Postman bennett(10, "Bennett");

    Post_office Oficerski("Oficerski", "Some adress");
    Oficerski.postmans[0] = dave;
    Oficerski.postmans[1] = james;
    Oficerski.postmans[2] = oscar;
    Oficerski.postmans[3] = ellis;
    Oficerski.postmans[4] = archer;
    Oficerski.postmans[5] = jack;
    Oficerski.postmans[6] = julian;
    Oficerski.postmans[7] = sawyer;
    Oficerski.postmans[8] = wesley;
    Oficerski.postmans[9] = bennett;
    Oficerski.get_letter(l1);
    Oficerski.give_letter();

}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    osn0();
    return 0;
}
