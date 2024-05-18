#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define PRINT(x) cout << x << endl;
using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::cin;

//=-=-=-=-=-=-=-=-=-=-=-=-= Номер 1 =-=-=-=-=-=-=-=-=-=-=-=-=
struct Lesson {
    string name;
    int grade;
};

struct Studentt { //две t чтобы не конфликтовало с последжним заданием
    int age;
    string name;
    Lesson lessons[2];
};

void nomer1() {
    Lesson math{ "math", 7 };
    Lesson eng{ "english", 9 };

    Studentt mark{ 21, "Mark", math, eng };
    PRINT("Student name: " << mark.name << " Student age: " << mark.age);
    PRINT(mark.lessons[0].name << " grade: " << mark.lessons[0].grade << '\t' << mark.lessons[1].name << " grade: " << mark.lessons[1].grade)
}
//=-=-=-=-=-=-=-=-=-=-=-=-= Номер 2 =-=-=-=-=-=-=-=-=-=-=-=-=
struct Point {
    int x_pos;
    int y_pos;
};

float calculating(Point a, Point b) {
    int X_pre_itog;
    int Y_pre_itog;
    float itog;

    if (a.x_pos > b.x_pos) {
        X_pre_itog = a.x_pos - b.x_pos;
    }
    else {
        X_pre_itog = b.x_pos - a.x_pos;
    }

    if (a.y_pos > b.y_pos) {
        Y_pre_itog = a.y_pos - b.y_pos;
    }
    else {
        Y_pre_itog = b.y_pos - a.y_pos;
    }

    itog = std::sqrt(static_cast<float>(X_pre_itog * X_pre_itog + Y_pre_itog * Y_pre_itog));//по теореме пифагора

    return itog;
}

void work_with_point() {
    Point a{ -4, 30 };
    Point b{ 76, 9 };
    PRINT("Примерное расстояние между двумя точками: " << calculating(a, b)) //как вам культура кода?
}
//=-=-=-=-=-=-=-=-=-=-=-=-= Номер 3 =-=-=-=-=-=-=-=-=-=-=-=-=
struct Ant {
    string color;
    string role;
    int age;//in days
};
struct Anthouse {
    vector<Ant> ants;
    int height; //in santimetrs
    int width;
};

void creating_ants() {
    Anthouse ah;//Аббревиатура 
    ah.ants.push_back(Ant{ "black", "worker", 12 });
    ah.ants.push_back(Ant{ "brown", "queen", 189 });
    ah.ants.push_back(Ant{ "red", "worker", 34 });
    ah.height = 80;
    ah.width = 115;
}


struct Car {
    struct Engine {
        int pover;
        float litters;
        bool electric; //электрический ли двигатель
    };
    Engine engine;
    int lenth;
    int weight;
    int weels_count;
};

void creating_car() {
    Car audi;
    audi.engine.electric = 0;
    audi.engine.litters = 3.5;
    audi.engine.pover = 280;
    audi.lenth = 3.2;
    audi.weight = 1200;
}

struct Cryon {
    string material;
    string color;
    int lenth;
};

void creating_cryon(){
    Cryon cr{ "plastic", "green", 14 };
}

struct Floor {
    int floor_number;
    vector<int> apportments_numbers;
};
struct Podezd {
    int podezd_number;
    vector<Floor> floors;
};
struct House {
    int house_number;
    bool lift; //оснащен ли дом лифтом
    vector<Podezd> podezds;
};
struct Apartment_complex {
    string name_of_complex;
    bool playground;
    vector<House> houses;
};

void creating_apartment_complex() {
    Floor floor_4;
    floor_4.floor_number = 4;
    floor_4.apportments_numbers.push_back(10);
    floor_4.apportments_numbers.push_back(11);
    floor_4.apportments_numbers.push_back(12);

    Podezd podezd_1;
    podezd_1.podezd_number = 1;
    podezd_1.floors.push_back(floor_4);

    House house_1;
    house_1.lift = true;
    house_1.house_number = 109;
    house_1.podezds.push_back(podezd_1);

    Apartment_complex apartment_complex_solnechy;
    apartment_complex_solnechy.name_of_complex = "Solnechny";
    apartment_complex_solnechy.playground = true;
    apartment_complex_solnechy.houses.push_back(house_1);
}
//=-=-=-=-=-=-=-=-=-=-=-=-= Номер 4 =-=-=-=-=-=-=-=-=-=-=-=-=

struct Subject {
    string subject_name;
    vector<int> grades;

    float avg_calculating() { //ф-ия для подсчёта среднего арифмитического
        int counter = 0;
        float itog = 0;
        for (int a : grades) {
            itog += a;
            counter++;
        }
        static_cast<float>(itog /= counter);
        return itog;
    }
    Subject(string _name) {
        this->subject_name = _name;
    }
    Subject() {}
};

struct Student {
    string student_name;
    string student_sname;
    int studak_number;
    vector<Subject> subject;
};

struct All_students{
    vector<Student> students_holder;

    void cout_all_students_information(All_students _all_students) { //ф-ия для вывода информации обо всех студентах
        for (Student some_student : _all_students.students_holder) { //первый форич нужен чтобы ввывести информацию обо всех студентах, а не только об одном
            PRINT("Вот информация о студенте обладающим студаком номер " << some_student.studak_number << ":")
            PRINT("Имя: " << some_student.student_name)
            PRINT("Фамилия: " << some_student.student_sname)
            PRINT("Номер студенческого: " << some_student.studak_number)
            PRINT("Оценки по предметам: ")
            for (Subject some_subject : some_student.subject) { //второй для того, чтобы ф-ия пробежалась по всем предметам, а не только по одному
                if (!some_subject.grades.empty()) {
                    cout << "Оценки по " << some_subject.subject_name << ":";
                    for (short grade : some_subject.grades) { //третий для того, чтобы ф-ия вывела все оценки в предмете, а не только одну
                        cout << ' ' << grade;
                    }
                    PRINT("    " << "Средняя оценка по этому предмету: " << some_subject.avg_calculating())
                }
                else {
                    PRINT("Оценки и средний балл по " << some_subject.subject_name << " отсутствуют, вы их не ввели")
                }
            }
            PRINT(' ')
        }
    }
};



void creating_first_student(All_students _all_students) {
    Subject math{ "math" };
    Subject enslish{ "enslish" };
    Subject phisic{ "phisic" };

    math.grades.push_back(9);
    math.grades.push_back(10);
    math.grades.push_back(11);
    
    enslish.grades.push_back(4);
    enslish.grades.push_back(8);
    enslish.grades.push_back(7);
    
    phisic.grades.push_back(11);
    phisic.grades.push_back(3);
    phisic.grades.push_back(9);

    Student ivan;
    ivan.student_name = "Ivan";
    ivan.student_sname = "Stolyarov";
    ivan.studak_number = 437;
    ivan.subject.push_back(math);
    ivan.subject.push_back(enslish);
    ivan.subject.push_back(phisic);

    _all_students.students_holder.push_back(ivan);
}

void creating_new_student(All_students all_students) {
    Subject math{ "math" };
    Subject enslish{ "enslish" };
    Subject phisic{ "phisic" };
    Student* tmp_st = new Student;
    tmp_st->subject.push_back(math);
    tmp_st->subject.push_back(enslish);
    tmp_st->subject.push_back(phisic);
    PRINT("Вы находитесь в разделе добавления нового студента.\nЧтобы досрочно покинуть этот раздел введите q")
    PRINT("Если вы не введёте первые 3 пункта, студент не будет добавлен.") //думаю это достаточно логично
    string user_string;
    bool special_check[3] = {0, 0, 0};
    do {
        PRINT("Введите имя добовляемого студента: ")
        cin >> user_string;
        if (user_string == "q" || user_string == "Q") { break; }//данная строка нужна чтобы можно было перестать добавлять студента в любой момент
        else { special_check[0] = 1; }//а данная шина для того, чтобы ф-ия не пыталась добавить недоделанного студента
        tmp_st->student_name = user_string;

        PRINT("Введите фамилию добовляемого студента: ")
        cin >> user_string;
        if (user_string == "q" || user_string == "Q") { break; }
        else { special_check[1] = 1; }
        tmp_st->student_sname = user_string;

        PRINT("Введите номер студенческого добовляемого студента(ТОЛЬКО ЦИФРЫ): ")
        cin >> user_string;
        if (user_string == "q" || user_string == "Q") { break; }
        else { special_check[2] = 1; }
        tmp_st->studak_number = stoi(user_string);

        do { //ещё один дувайл чтобы была возможность пропустить сегмет выставления оценок
            short user_choise; 
            short user_num;
            PRINT("Выставить оценки по всем предметам(1) или пропустить этот пункт(0)?")
            cin >> user_choise;
            if (user_choise == 1) {
                for (short counter = 0; counter < 3; counter++) {
                    PRINT("Сколько вы желаете выставить оценок по " << tmp_st->subject[counter].subject_name)
                    cin >> user_choise;
                    PRINT("Хорошо, вводите их через enter")
                    for (short i = 0; i < user_choise; i++) {
                        cin >> user_num;
                        tmp_st->subject[counter].grades.push_back(user_num);
                    }
                }
                
            }
            break;
        } while (user_string != "q" || user_string != "Q");
        break;
    } while (user_string != "q" || user_string != "Q");
    
    if (special_check[0] == 1 && special_check[1] == 1 && special_check[2] == 1) { //запись студента в вектор только в случае наличия имени, фамилии и номера студака
        all_students.students_holder.push_back(*tmp_st);
    }
    delete tmp_st;
}

void work_with_students() {
    All_students all_students; //создание структуры, хранящей в себе метод вывода информации всех студентов, а так же вектор студентов
    creating_first_student(all_students); //добавление в эту структуру первого студента согласно тз
    string user_choise; //от греха подальше именно строка, чтобы дувайл чётко знал когда ему заканчиваться
    do {
        PRINT("Что бы вы хотели сделать?")
        PRINT("0 - Вывести информацию обо всех студентах")
        PRINT("1 - Добавить информацию о новом студенте")
        PRINT("2 - завершить программу")
        cin >> user_choise;
        switch (stoi(user_choise))
        {
        case 0: all_students.cout_all_students_information(all_students); break;
        case 1: creating_new_student(all_students); break;
        case 2: break; break;
        default: user_choise = "2";
        }
    } while (user_choise != "2");
}


int main() {
    setlocale(0, "ru");
    srand(time(NULL));
    /*nomer1();
    work_with_point();
    creating_ants();
    creating_car();
    creating_cryon();
    creating_apartment_complex();*/
    work_with_students();
    return 0;
}
