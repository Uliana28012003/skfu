////14. Синхронизированный вывод 4
////Решите задачу 11 с использованием двух семафоров - счетчиков
//
//#include <iostream>
//#include <thread>
//#include <semaphore.h>
//
//using namespace std;
//
//// Объявляем два семафора
//sem_t parentSem;
//sem_t childSem;
//
//void threadF() {
//    for (int i = 0; i < 10; ++i) {
//        // Ожидание сигнала от родительского потока
//        sem_wait(&childSem);
//        cout << "Дочерний Поток: " << i << endl;
//        // Сигнал родительскому потоку
//        sem_post(&parentSem);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    // Инициализируем семафоры
//    sem_init(&parentSem, 0, 1);  // Родительский поток начинает первым
//    sem_init(&childSem, 0, 0);   // Дочерний поток будет ждать
//
//    // Создаем дочерний поток
//    thread t(threadF);
//
//    for (int i = 0; i < 10; ++i) {
//        // Ожидание сигнала от дочернего потока
//        sem_wait(&parentSem);
//        cout << "Родительский Поток: " << i << endl;
//        // Сигнал дочернему потоку
//        sem_post(&childSem);
//    }
//
//    // Ждем завершения дочернего потока
//    t.join();
//
//    // Уничтожаем семафоры
//    sem_destroy(&parentSem);
//    sem_destroy(&childSem);
//
//    return 0;
//}
