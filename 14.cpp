////14. ������������������ ����� 4
////������ ������ 11 � �������������� ���� ��������� - ���������
//
//#include <iostream>
//#include <thread>
//#include <semaphore.h>
//
//using namespace std;
//
//// ��������� ��� ��������
//sem_t parentSem;
//sem_t childSem;
//
//void threadF() {
//    for (int i = 0; i < 10; ++i) {
//        // �������� ������� �� ������������� ������
//        sem_wait(&childSem);
//        cout << "�������� �����: " << i << endl;
//        // ������ ������������� ������
//        sem_post(&parentSem);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    // �������������� ��������
//    sem_init(&parentSem, 0, 1);  // ������������ ����� �������� ������
//    sem_init(&childSem, 0, 0);   // �������� ����� ����� �����
//
//    // ������� �������� �����
//    thread t(threadF);
//
//    for (int i = 0; i < 10; ++i) {
//        // �������� ������� �� ��������� ������
//        sem_wait(&parentSem);
//        cout << "������������ �����: " << i << endl;
//        // ������ ��������� ������
//        sem_post(&childSem);
//    }
//
//    // ���� ���������� ��������� ������
//    t.join();
//
//    // ���������� ��������
//    sem_destroy(&parentSem);
//    sem_destroy(&childSem);
//
//    return 0;
//}
