//Напишите программу, которая создает поток.Используйте атрибуты по умолчанию.
//Родительский и вновь созданный поток должны распечатать десять строк текста.

#include <iostream>
#include <thread>
#include <locale>

using namespace std;

void threadF() {
    for (int i = 0; i < 10; ++i) {
        cout << "Дочерний Поток: " << i << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание и запуск дочернего потока
    thread t(threadF);

    // Вывод в родительском потоке
    for (int i = 0; i < 10; ++i) {
        cout << "Родительский Поток: " << i << endl;
    }

    // Присоединение дочернего потока
    t.join();

    return 0;
}
