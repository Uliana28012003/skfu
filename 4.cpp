//Дочерний поток должен распечатывать текст на экран.
//Через две секунды после создания дочернего потока,
//родительский поток должен прервать ее вызовом функции pthread_cancel.
//
//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//using namespace std;
//
//void* ThreadF(void*) {
//    // Разрешить отмену потока в любое время
//    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
//
//    cout << "Дочерний поток запущен..." << endl;
//
//    // Имитация длительной задачи
//    for (int i = 0; i < 10; ++i) {
//        cout << "Дочерний поток работает... " << i << endl;
//        sleep(1);  // Синхронный сон на 1 секунду
//    }
//
//    cout << "Дочерний поток завершен самостоятельно." << endl;
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t t;
//
//    if (pthread_create(&t, NULL, ThreadF, NULL)) {
//        cerr << "Ошибка при создании потока." << endl;
//        return 1;
//    }
//
//    // Ожидание 2 секунд
//    sleep(2);
//
//    if (pthread_cancel(t)) {
//        cerr << "Ошибка при завершении потока." << endl;
//        return 1;
//    }
//
//    cout << "Дочерний поток был завершен родительским." << endl;
//
//    if (pthread_join(t, NULL)) {
//        cerr << "Ошибка при присоединении потока." << endl;
//        return 1;
//    }
//
//    cout << "Родительский поток завершен." << endl;
//
//    return 0;
//}
