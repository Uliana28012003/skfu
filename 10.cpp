//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <limits>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <fstream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <sys/stat.h>
//#include <pthread.h>
//#include <filesystem>
//#include <chrono>
//#include <future>
//#include <math.h>
//#include <conio.h>
//#include <signal.h>
//
//using namespace std;
//
//// Мьютекс для синхронизации вывода
//mutex printM;
//
//// Функция для вывода состояния философа
//void print(int philosopher_number, int n) {
//    // Захват мьютекса для синхронизации вывода
//    printM.lock();
//    if (n == 1) {
//        cout << "Философ " << philosopher_number << " думает.." << endl;
//    }
//    else if (n == 2) {
//        cout << "Философ " << philosopher_number << " закончил есть и думает.." << endl;
//    }
//    else {
//        cout << "Философ " << philosopher_number << " начал есть.." << endl;
//    }
//    // Освобождение мьютекса
//    printM.unlock();
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian"); // Установка локали для поддержки русского языка
//
//    const int number_of_philosophers = 5; // Количество философов
//
//    // Структура для представления вилок
//    struct Forks {
//    public:
//        Forks() { ; }
//        mutex mu; // Мьютекс для синхронизации доступа к вилке
//    };
//
//    // Лямбда-функция, представляющая процесс еды философа
//    auto eat = [](Forks& left_fork, Forks& right_fork, int philosopher_number) {
//        // Захват мьютексов для вилок
//        unique_lock<mutex> llock(left_fork.mu);
//        unique_lock<mutex> rlock(right_fork.mu);
//
//        print(philosopher_number, 3); // Философ начинает есть
//
//        chrono::milliseconds timeout(300); // Тайм-аут для имитации процесса еды
//        this_thread::sleep_for(timeout); // Сон на время тайм-аута
//
//        print(philosopher_number, 2); // Философ закончил есть и начинает думать
//    };
//
//    Forks forks[number_of_philosophers]; // Массив вилок
//    thread philosopher[number_of_philosophers]; // Массив потоков для философов
//
//    // Создание потоков для философов
//    for (int i = 0; i < number_of_philosophers; ++i) {
//        auto philosopher_number = i + 1; // Номер философа
//        print(philosopher_number, 1); // Философ думает
//        auto previous_fork_index = (number_of_philosophers + (i - 1)) % number_of_philosophers; // Индекс предыдущей вилки
//        philosopher[i] = thread(eat, ref(forks[i]), ref(forks[previous_fork_index]), philosopher_number); // Создание потока
//    }
//
//    cout << endl;
//    // Ожидание завершения всех потоков
//    for (auto& ph : philosopher) {
//        ph.join();
//    }
//
//    return 0;
//}
