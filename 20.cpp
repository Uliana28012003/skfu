//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <thread>
//#include <shared_mutex> // Для использования shared_mutex
//#include <chrono>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// Структура узла связанного списка
//struct Node {
//    string data;
//    Node* next;
//    mutable shared_mutex mtx; // shared_mutex вместо mutex, чтобы разрешить несколько потоков для чтения и один для записи
//
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//// Класс связанного списка
//class LinkedList {
//private:
//    Node* head;
//    mutable shared_mutex headMtx; // shared_mutex для синхронизации доступа к голове списка
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    // Вставка нового элемента в список
//    void insert(const string& data) {
//        Node* newNode = new Node(data);
//        unique_lock<shared_mutex> lock(headMtx, defer_lock); // Захватываем мьютекс, откладывая блокировку
//        lock.lock(); // Теперь блокируем мьютекс
//        newNode->next = head;
//        head = newNode;
//    }
//
//    // Вывод содержимого списка
//    void print() {
//        shared_lock<shared_mutex> lock(headMtx); // Разрешаем параллельное чтение
//        Node* current = head;
//        while (current != nullptr) {
//            shared_lock<shared_mutex> nodeLock(current->mtx); // Захватываем мьютекс узла для безопасного доступа к данным
//            cout << current->data << endl;
//            current = current->next;
//        }
//    }
//
//    // Сортировка списка методом пузырька
//    void bubbleSort() {
//        if (!head) return;
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            swapped = false;
//            shared_lock<shared_mutex> lock(headMtx); // Разрешаем параллельное чтение
//            ptr1 = head;
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                unique_lock<shared_mutex> lock1(ptr1->mtx, defer_lock); // Откладываем блокировку
//                unique_lock<shared_mutex> lock2(ptr1->next->mtx, defer_lock); // Откладываем блокировку
//                std::lock(lock1, lock2); // Блокируем оба мьютекса сразу
//
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data);
//                    swapped = true;
//                }
//                prev = ptr1;
//                ptr1 = ptr1->next;
//            }
//            lptr = ptr1;
//        } while (swapped);
//    }
//};
//
//// Функция потока для сортировки списка
//void sortingThread(LinkedList& list, int interval) {
//    while (true) {
//        this_thread::sleep_for(chrono::seconds(interval));
//        list.bubbleSort();
//    }
//}
//
//int main() {
//    SetConsoleCP(1251); // Устанавливаем кодировку для консоли ввода
//    SetConsoleOutputCP(1251); // Устанавливаем кодировку для консоли вывода
//
//    LinkedList list;
//    vector<thread> sortingThreads;
//    int numThreads = 2; // Количество потоков сортировки
//    int intervalSeconds = 5; // Интервал времени между шагами сортировки
//
//    // Создание и запуск потоков сортировки
//    for (int i = 0; i < numThreads; ++i) {
//        sortingThreads.emplace_back(sortingThread, ref(list), intervalSeconds);
//    }
//
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            cout << "Текущее состояние списка:" << endl;
//            list.print();
//        }
//        else {
//            if (input.length() > 80) {
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr);
//                }
//            }
//            else {
//                list.insert(input);
//            }
//        }
//    }
//
//    // Ожидание завершения потоков сортировки
//    for (auto& thread : sortingThreads) {
//        thread.join();
//    }
//    return 0;
//}
