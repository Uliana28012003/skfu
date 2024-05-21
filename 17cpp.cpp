//17. Синхронизированный доступ к списку
//
//Родительская поток программы должна считывать вводимые пользователем строки и помещать их
//в начало связанного слиска.Строки длиннее 80 символов можно разрезать на несколько строк.
//При вводе пустой строки программа должна выдавать текущее состояние слиска.Дочерняя поток
//пробуждается каждые пять секунд и сортирует список в лексикографическом порядке(используйте
//пузырьковую сортировку).Все операции над списком должны синхронизоваться при помощи мьютекса.
//
//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <algorithm>
//
//using namespace std;
//
//// Структура для узла списка
//struct Node {
//    string data; // Данные узла
//    Node* next; // Указатель на следующий узел
//    Node(const string& data) : data(data), next(nullptr) {} // Конструктор узла
//};
//
//// Класс для связанного списка
//class LinkedList {
//private:
//    Node* head; // Указатель на голову списка
//    mutex mtx; // Мьютекс для синхронизации
//
//public:
//    LinkedList() : head(nullptr) {} // Конструктор списка
//
//    // Метод для вставки нового узла в начало списка
//    void insert(const string& data) {
//        lock_guard<mutex> lock(mtx); // Захват мьютекса
//        Node* newNode = new Node(data); // Создание нового узла
//        newNode->next = head; // Указание на следующий узел
//        head = newNode; // Обновление головы списка
//    }
//
//    // Метод для печати элементов списка
//    void print() {
//        lock_guard<mutex> lock(mtx); // Захват мьютекса
//        Node* current = head; // Начало с головы списка
//        while (current != nullptr) { // Пока не достигнут конец списка
//            cout << current->data << endl; // Печать данных узла
//            current = current->next; // Переход к следующему узлу
//        }
//    }
//
//    // Метод для сортировки списка методом пузырька
//    void bubbleSort() {
//        lock_guard<mutex> lock(mtx); // Захват мьютекса
//        if (!head) return; // Если список пуст, выходим
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            swapped = false;
//            ptr1 = head;
//            while (ptr1->next != lptr) { // Проход по списку
//                if (ptr1->data > ptr1->next->data) { // Сравнение узлов
//                    swap(ptr1->data, ptr1->next->data); // Обмен данных
//                    swapped = true; // Устанавливаем флаг обмена
//                }
//                ptr1 = ptr1->next; // Переход к следующему узлу
//            }
//            lptr = ptr1; // Обновление последнего упорядоченного узла
//        } while (swapped); // Повтор, если был обмен
//    }
//};
//
//// Функция для потока сортировки
//void sortingThread(LinkedList& list) {
//    while (true) {
//        this_thread::sleep_for(chrono::seconds(5)); // Ожидание 5 секунд
//        list.bubbleSort(); // Вызов сортировки
//    }
//}
//
//int main() {
//    // Установка кодировки консоли на 1251 (кириллица)
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    LinkedList list; // Создание объекта списка
//    thread sorting(sortingThread, ref(list)); // Создание потока для сортировки
//
//    // Главный цикл для ввода данных
//    while (true) {
//        string input;
//        getline(cin, input); // Чтение строки ввода
//        if (input.empty()) { // Если строка пустая
//            cout << "Текущее состояние списка:" << endl;
//            list.print(); // Печать списка
//        }
//        else {
//            if (input.length() > 80) { // Если длина строки больше 80
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80); // Разделение строки на подстроки
//                    list.insert(substr); // Вставка подстроки в список
//                }
//            }
//            else {
//                list.insert(input); // Вставка строки в список
//            }
//        }
//    }
//
//    sorting.join(); // Ожидание завершения потока сортировки
//    return 0;
//}
//ф