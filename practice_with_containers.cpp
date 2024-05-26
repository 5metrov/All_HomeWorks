/*
тз:
- контейнеры: array, vector, deque, list, map, set
- старайтесь не использовать циклы, используйте уже готовые методы
- набор элементов: 
Необходимо
рассматривать
свою
победу,
как
череду
более
мелких
побед,
которые,
к тому же,
растянуты
во времени.
Другими
словами,
это игра
"в долгую".

-1) необходимо сохранить этот набор элементов в указанные контейнеры
-2) выведите в консоль содержимое каждого контейнера
-3) затем из каждого контейнера удалите значения "свою" и "более"
-4) выведите в консоль содержимое каждого контейнера
-5) выведите в консоль кол-во элементов в каждом контейнере
-6) создайте структуру Student со свойством name
-7) в каждый контейнер запишите 5 объектов указанной структуры с произвольным значением для св-ва name
-8) выведите в консоль содержимое каждого контейнера: значения св-ва name
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <algorithm> 
#define ENDL cout << endl;
using std::string;
using std::endl;
using std::vector;
using std::cout;
using std::cin;

void show_all_kontainers(string array[], int size, vector<string> vec, std::list<string> list, std::deque<string> deq, std::map<int, string> map, std::set<string> set) {
	cout << "This is array:"; ENDL
		for (int i = 0; i < size; ++i) {
			std::cout << array[i] << " ";
		}
	ENDL ENDL;

	cout << "This is vector:"; ENDL
		std::for_each(vec.begin(), vec.end(), [](string& str) {
		cout << str << ' ';
			});
	ENDL ENDL;

	cout << "This is deque:"; ENDL
		std::for_each(deq.begin(), deq.end(), [](string& str) {
		cout << str << ' ';
			});
	ENDL ENDL;

	cout << "This is list:"; ENDL
		std::for_each(deq.begin(), deq.end(), [](string& str) {
		cout << str << ' ';
			});
	ENDL ENDL;

	cout << "This is map:"; ENDL
		for (auto& pair : map) {
			cout << pair.first << " - " << pair.second << '\n';
		}
	ENDL;

	cout << "This is set:"; ENDL
		for (auto& text : set) {
			cout << text << ' ';
		}
	ENDL ENDL;
}

struct Student {
	string name;

	bool operator<(const Student& other) const { //врать не буду - перегрузку оператора сравнения мне подсказал чат жпт
		return name < other.name;
	}
};

void osn0() {
	string s0 = "Необходимо"; //3, 7
	string s1 = "рассматривать";
	string s2 = "свою";
	string s3 = "победу,";
	string s4 = "как";
	string s5 = "череду";
	string s6 = "более";
	string s7 = "мелких";
	string s8 = "побед,";
	string s9 = "которые,";
	string s10 = "к тому же,";
	string s11 = "растянуты";
	string s12 = "во времени.";
	string s13 = "Другими";
	string s14 = "словами,";
	string s15 = "это игра";
	string s16 = "\"в долгую\".";

	string array[17] = { s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16 };
	int array_size;
	vector<string> vec;
	std::deque<string> deq;
	std::list<string> list;
	std::map<int, string> map;
	std::set<string> set;

	int counter = 0;
	for (string text : array) {
		vec.push_back(text);
		deq.push_back(text);
		list.push_back(text);
		map.emplace(counter, text);
		set.insert(text);
		counter++;
	}

	array_size = sizeof(array) / sizeof(array[0]);
	show_all_kontainers(array, array_size, vec, list, deq, map, set);

	array[2].clear();
	array[6].clear();

	vec.erase(vec.begin() + 2);
	vec.erase(vec.begin() + 5);
	
	auto it = std::next(list.begin(), 2);
	list.erase(it);
	it = std::next(list.begin(), 5);
	list.erase(it);

	deq.erase(deq.begin() + 2);
	deq.erase(deq.begin() + 5);

	map.erase(2);
	map.erase(6);

	set.erase("свою");
	set.erase("более");

	show_all_kontainers(array, array_size, vec, list, deq, map, set);

	int array_counter = 0;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		if (!array[i].empty()) {
			array_counter++;
		}
		else { continue; }
	}
	cout << "В массиве " << array_counter << " элементов"; ENDL;
	cout << "В векторе " << vec.size() << " элементов"; ENDL;
	cout << "В листе " << list.size() << " элементов"; ENDL;
	cout << "В двусторонней очереди " << deq.size() << " элементов"; ENDL;
	cout << "В map " << map.size() << " элементов"; ENDL;
	cout << "В set " << set.size() << " элементов"; ENDL;

	Student ivan{ "Ivan" };
	Student oleg{ "Oleg" };
	Student egor{ "Egor" };
	Student stepan{ "Stepan" };
	Student grogorot{ "Grogorot" };

	Student st_array[5] = { ivan , oleg , egor , stepan , grogorot };
	vector<Student> st_vec;
	std::deque<Student> st_deq;
	std::list<Student> st_list;
	std::map<int, Student> st_map;
	std::set<Student> st_set;
	counter = 0;
	for (Student student : st_array) {
		st_vec.push_back(student);
		st_deq.push_back(student);
		st_list.push_back(student);
		st_map.emplace(counter, student);
		st_set.insert(student);
		counter++;
	}
	

	ENDL;
	cout << "This is students array:"; ENDL;
	for (int i = 0; i < sizeof(st_array) / sizeof(st_array[0]); i++) {
		cout << st_array[i].name << ' ';
	}
	ENDL ENDL;

	cout << "This is students vector:"; ENDL;
	for (Student student : st_vec) {
		cout << student.name << ' ';
	}
	ENDL ENDL;

	cout << "This is students list:"; ENDL;
	for (Student student : st_list) {
		cout << student.name << ' ';
	}
	ENDL ENDL;

	cout << "This is students deque:"; ENDL;
	for (Student student : st_deq) {
		cout << student.name << ' ';
	}
	ENDL ENDL;

	cout << "This is students map:"; ENDL;
	for (auto student : st_map) {
		cout << student.first << " - " << student.second.name << '\n';
	}
	ENDL ENDL;

	cout << "This is students set:"; ENDL;
	for (Student student : st_set) {
		cout << student.name << ' ';
	}
	ENDL ENDL;

}

int main() {
	setlocale(0, "ru");
	osn0();
	return 0;
}
