//Модифицируйте программу упр. 4 так,
//чтобы дочерний поток перед завершением распечатывал сообщение об этом.
//Используйте pthread_cleanup_push.

//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//using namespace std;
//
//void cleanup(void* arg) {
//    // Просто выводим сообщение о завершении работы
//    cout << "Дочерний поток: Завершение работы..." << endl;
//}
//
//void* ThreadF(void*) {
//    cout << "Дочерний поток: Запущен..." << endl;
//
//    // Регистрируем функцию очистки для вызова перед завершением потока
//    pthread_cleanup_push(cleanup, NULL);
//
//    // Разрешить отмену потока в любое время
//    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
//
//    // Имитация работы
//    for (int i = 0; i < 10; ++i) {
//        cout << "Дочерний поток работает... " << i << endl;
//        sleep(1);  // Синхронный сон на 1 секунду
//    }
//
//    // Выполняем очистку стека
//    pthread_cleanup_pop(1);
//
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
//    cout << "Дочерний поток завершен родительским." << endl;
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
