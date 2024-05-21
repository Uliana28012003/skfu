//Модифицируйте программу упр. 1 так,
//чтобы вывод родительской и дочерней потоках был синхронизован :
//сначала родительская поток выводила первую строку, затем дочерняя,
//затем родительская вторую строку и т.д.Используйте мьютексы.
//Рекомендуется использовать мьютексы типа PTHREAD_MUTEX_ERRORCHECK.
//Явные и неявные передачи управления между нитями
//(sleep(3C) / usleep(3C), sched_yield(3RT))
//и холостые циклы разрешается использовать
//только на этапе инициализации.
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//
//
//using namespace std;
//
//mutex mtx;
//int counter = 0;
//
//void threadF() {
//    for (int i = 0; i < 10; ++i) {
//        {
//            lock_guard<mutex> lock(mtx);
//            cout << "Дочерний Поток: " << counter++ << endl;
//        }
//        this_thread::sleep_for(chrono::milliseconds(100)); // Явная передача управления
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    thread t(threadF);
//
//    for (int i = 0; i < 10; ++i) {
//        {
//            lock_guard<mutex> lock(mtx);
//            cout << "Родительский Поток: " << counter++ << endl;
//        }
//        this_thread::sleep_for(chrono::milliseconds(100)); // Явная передача управления
//    }
//
//    t.join();
//
//    return 0;
//}
