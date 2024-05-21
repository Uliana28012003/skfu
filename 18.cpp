//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// Структура узла связанного списка
//struct Node {
//    string data; // Данные узла
//    Node* next; // Указатель на следующий узел
//    mutex mtx; // Мьютекс для синхронизации доступа к узлу
//
//    // Конструктор узла
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//// Класс связанного списка
//class LinkedList {
//private:
//    Node* head; // Указатель на голову списка
//    mutex headMtx; // Мьютекс для синхронизации доступа к голове списка
//
//public:
//    // Конструктор списка
//    LinkedList() : head(nullptr) {}
//
//    // Метод для вставки нового элемента в начало списка
//    void insert(const string& data) {
//        Node* newNode = new Node(data); // Создание нового узла
//        lock_guard<mutex> lock(headMtx); // Захват мьютекса для головы списка
//        newNode->next = head; // Новый узел указывает на текущую голову списка
//        head = newNode; // Обновление головы списка
//    }
//
//    // Метод для печати содержимого списка
//    void print() {
//        lock_guard<mutex> lock(headMtx); // Захват мьютекса для головы списка
//        Node* current = head; // Начало печати с головы списка
//        while (current != nullptr) {
//            lock_guard<mutex> nodeLock(current->mtx); // Захват мьютекса для текущего узла
//            cout << current->data << endl; // Печать данных текущего узла
//            current = current->next; // Переход к следующему узлу
//        }
//    }
//
//    // Метод для сортировки списка методом пузырька
//    void bubbleSort() {
//        if (!head) return; // Если список пуст, выход
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            swapped = false;
//            lock_guard<mutex> lock(headMtx); // Захват мьютекса для головы списка
//            ptr1 = head; // Указатель для прохода по списку
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                lock_guard<mutex> lock1(ptr1->mtx); // Захват мьютекса для текущего узла
//                lock_guard<mutex> lock2(ptr1->next->mtx); // Захват мьютекса для следующего узла
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data); // Обмен данных между узлами
//                    swapped = true;
//                }
//                prev = ptr1; // Переход к следующему узлу
//                ptr1 = ptr1->next; // Переход к следующему узлу
//            }
//            lptr = ptr1; // Уменьшение области для сортировки
//        } while (swapped); // Повторять, пока есть обмены
//    }
//};
//
//// Функция потока сортировки
//void sortingThread(LinkedList& list, int interval) {
//    while (true) {
//        this_thread::sleep_for(chrono::seconds(interval)); // Пауза перед сортировкой
//        list.bubbleSort(); // Вызов метода сортировки списка
//    }
//}
//
//int main() {
//    SetConsoleCP(1251); // Установка кодировки ввода для консоли
//    SetConsoleOutputCP(1251); // Установка кодировки вывода для консоли
//
//    LinkedList list; // Создание объекта связанного списка
//    vector<thread> sortingThreads; // Вектор потоков сортировки
//    int numThreads = 2; // Количество потоков сортировки
//    int intervalSeconds = 5; // Интервал сортировки в секундах
//
//    // Создание потоков сортировки и добавление их в вектор
//    for (int i = 0; i < numThreads; ++i) {
//        sortingThreads.emplace_back(sortingThread, ref(list), intervalSeconds);
//    }
//
//    // Бесконечный цикл для взаимодействия с пользователем
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            cout << "Текущее состояние списка:" << endl;
//            list.print(); // Вывод текущего состояния списка
//        }
//        else {
//            if (input.length() > 80) {
//                // Если ввод превышает 80 символов, разбиваем на подстроки и вставляем их по очереди
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr); // Вставка подстроки в список
//                }
//            }
//            else {
//                list.insert(input); // Вставка введенной строки в список
//            }
//        }
//    }
//
//    // Ожидание завершения всех потоков сортировки
//    for (auto& thread : sortingThreads) {
//        thread.join();
//    }
//    return 0;
//}
