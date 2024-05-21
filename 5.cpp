//������������� ��������� ���. 4 ���,
//����� �������� ����� ����� ����������� ������������ ��������� �� ����.
//����������� pthread_cleanup_push.

//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//using namespace std;
//
//void cleanup(void* arg) {
//    // ������ ������� ��������� � ���������� ������
//    cout << "�������� �����: ���������� ������..." << endl;
//}
//
//void* ThreadF(void*) {
//    cout << "�������� �����: �������..." << endl;
//
//    // ������������ ������� ������� ��� ������ ����� ����������� ������
//    pthread_cleanup_push(cleanup, NULL);
//
//    // ��������� ������ ������ � ����� �����
//    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
//
//    // �������� ������
//    for (int i = 0; i < 10; ++i) {
//        cout << "�������� ����� ��������... " << i << endl;
//        sleep(1);  // ���������� ��� �� 1 �������
//    }
//
//    // ��������� ������� �����
//    pthread_cleanup_pop(1);
//
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t t;
//
//    if (pthread_create(&t, NULL, ThreadF, NULL)) {
//        cerr << "������ ��� �������� ������." << endl;
//        return 1;
//    }
//
//    // �������� 2 ������
//    sleep(2);
//
//    if (pthread_cancel(t)) {
//        cerr << "������ ��� ���������� ������." << endl;
//        return 1;
//    }
//
//    cout << "�������� ����� �������� ������������." << endl;
//
//    if (pthread_join(t, NULL)) {
//        cerr << "������ ��� ������������� ������." << endl;
//        return 1;
//    }
//
//    cout << "������������ ����� ��������." << endl;
//
//    return 0;
//}
