//16. Синхронизированный вывод двух процессов
//Решите задачу 11 с использованием двух процессов(а не потоков) и именованных семафоров - счетчиков

//#include <iostream>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <sys/sem.h>
//#include <sys/ipc.h>
//
//using namespace std;
//
//union semun {
//    int val;
//    struct semid_ds* buf;
//    unsigned short* array;
//};
//
//void sem_wait(int sem_id) {
//    struct sembuf sops = { 0, -1, 0 };
//    semop(sem_id, &sops, 1);
//}
//
//void sem_signal(int sem_id) {
//    struct sembuf sops = { 0, 1, 0 };
//    semop(sem_id, &sops, 1);
//}
//
//void childProcess(int sem_id) {
//    for (int i = 0; i < 10; ++i) {
//        sem_wait(sem_id);
//        cout << "Дочерний Процесс: " << i << endl;
//        sem_signal(sem_id);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    // Создание именованного семафора-счетчика
//    key_t key = ftok("/tmp", 'S');
//    int sem_id = semget(key, 1, IPC_CREAT | 0666);
//    semun arg;
//    arg.val = 1; // Устанавливаем начальное значение семафора
//    semctl(sem_id, 0, SETVAL, arg);
//
//    pid_t pid = fork();
//
//    if (pid < 0) {
//        cerr << "Ошибка при вызове fork()" << endl;
//        return 1;
//    }
//    else if (pid == 0) {
//        // Дочерний процесс
//        childProcess(sem_id);
//    }
//    else {
//        // Родительский процесс
//        for (int i = 0; i < 10; ++i) {
//            sem_wait(sem_id);
//            cout << "Родительский Процесс: " << i << endl;
//            sem_signal(sem_id);
//        }
//        wait(NULL);
//    }
//
//    // Удаление семафора
//    semctl(sem_id, 0, IPC_RMID);
//
//    return 0;
//}
