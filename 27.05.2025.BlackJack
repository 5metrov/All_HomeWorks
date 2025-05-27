#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <chrono>     // для std::chrono::milliseconds
#include <thread>     // для std::this_thread::sleep_for
#define ENDL cout << endl;
#define SLOW std::this_thread::sleep_for(std::chrono::milliseconds(1000));

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::map;
using std::cin;

//ф-ия для создания новых рандомных чисел в пределах индексов массивов
int newRandNum(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    int x = rand()%13;
    return x;
}

//Вывод всех карт игрока/диллера в консоль + подсчёт суммы значений карт
int showAllCardsAndSum(vector<int> indexes, string cardsNames[], int cardsVal[], string role){
    int sum = 0;
    int iter = 0;
    cout<<"Карты " << role << ": ";
    for(auto index : indexes){
        
        cout<<cardsNames[index]<<", ";
        
        if(cardsVal[index] == 11 && iter>=2 && sum > 10){ //Проверка чтобы туз превращался в единицу, но была возможность выбить золотое очко
            sum+=1;
        } else {sum+=cardsVal[index];}
        iter++;    
    }
	ENDL
	cout<<"Сумма карт " << role << ": " << sum; ENDL
	return sum;
}

//Основная логика игры именно в этой ф-ии
int game(){
    int cardsValArr[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}; //Может всё невероятно костыльно работает на двух массивах, однако я не осилил сделатьна map
    string cardsNameArr[13] = {"Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка", "Восьмёрка", "Девятка", "Дестка", "Валет", "Дама", "Король", "Туз"};
    map<string, int> cardsHolder;
    
	for (int i=0;i<13;i++) {
		cardsHolder.emplace(cardsNameArr[i], cardsValArr[i]);
	}
	
	
    int playerSum, dillerSum = 0;
    vector<int> dillerCardsIndexes; 
    vector<int> playerCardsIndexes;
    int randNum = newRandNum(); //Генерация случ. числа
    dillerCardsIndexes.push_back(randNum); //Занесение этого самого случ. числа в массив
    dillerSum = showAllCardsAndSum(dillerCardsIndexes, cardsNameArr, cardsValArr, "Диллера"); //Подсчёт ссуммы + вывод в консоль всех карт
    randNum = newRandNum();
    playerCardsIndexes.push_back(randNum);
    randNum = newRandNum();
    playerCardsIndexes.push_back(randNum);
    playerSum = showAllCardsAndSum(playerCardsIndexes, cardsNameArr, cardsValArr, "Игрока");
    
    //Золотое очко. Именно для его работы был добавлен костыльный итератор в функции showAllCardsAndSum
    if(playerSum == 22){cout<<"Вот это везение! Золотое очко! Везучее людей я ещё не встречал)"; return 0;} 
    
    //Цикл с добором карт игроком
    string playerSelect;
    while(playerSelect!="n" && playerSelect!="N" && playerSum <= 21){
        cout<<"Желаете взять ещё одну карту?(Y/N)";ENDL
        cin>>playerSelect;
        if (playerSelect == "y" || playerSelect == "Y"){
            randNum = newRandNum();
            playerCardsIndexes.push_back(randNum);
            playerSum = showAllCardsAndSum(playerCardsIndexes, cardsNameArr, cardsValArr, "Игрока");
        }
    }
    if (playerSum > 21) {cout << "Перебор! Выиграл диллер. Повезёт в другой раз."; return 0;}
    
    cout << "Итоговая сумма карт игрока: " << playerSum; ENDL SLOW
    cout << "Диллер берёт карту."; ENDL SLOW //Прокинуты таймеры бездействия, чтобы казалось что опонент думает
    
    randNum = newRandNum();
    dillerCardsIndexes.push_back(randNum);
    dillerSum = showAllCardsAndSum(dillerCardsIndexes, cardsNameArr, cardsValArr, "Диллера");
    
    //Цикл с добором карт диллеру. Диллер видит карты сумму карт игрока и старается её обогнать ценой поражения
    while (dillerSum < playerSum){
        cout << "Диллер берёт карту."; ENDL SLOW
        randNum = newRandNum();
        dillerCardsIndexes.push_back(randNum);
        dillerSum = showAllCardsAndSum(dillerCardsIndexes, cardsNameArr, cardsValArr, "Диллера");
        SLOW SLOW
    } 
    if (dillerSum > 21){cout << "У диллера перебор. Победа за игроком!"; return 0;}
    
    cout << "Диллер решил прекратить брать карты."; ENDL
    
    SLOW //"Определение" победителя
    cout << "Итоговые сумммы у Игрока/Диллера: " << playerSum << "/" << dillerSum; ENDL
    if (playerSum <= dillerSum){
        cout << "Победа за диллером! Повезёт в другой раз"; ENDL
        if(playerSum == dillerSum){cout<<"Да, было близко, но правила таковы.";} //Пояснение самым недовольным
        return 0;
    } else {
        cout<<"Поздравляем с победой! Вы обыграли бездушную машину!";
    }
    
    return 0;
}

int main()
{
    setlocale(0, "ru");
    srand(time(NULL));
    //У игр же есть стартовый экран? ну это типа он
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-="; ENDL
    cout<<"| Желаете начать игру?(Y/N) |"; ENDL
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-="; ENDL
    string playerSelect;
    cin>>playerSelect;
    if (playerSelect == "Y" || playerSelect == "y"){
        game(); //запуск игры        
    } else if (playerSelect == "N" || playerSelect == "n") {
        cout<<"Зачем тогда было запускать игру?"; ENDL
    } else if (playerSelect == "CC" || playerSelect == "cc") {
        cout<<"ОЛЛ ХЕЙЛ ЛЕЛУШ"; ENDL
    } else {
        cout<<"Нажата не верная клавиша, перезапустите программу и выберите из предложенных"; ENDL
    }
    return 0;
}
