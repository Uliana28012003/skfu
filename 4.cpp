//�������� ����� ������ ������������� ����� �� �����.
//����� ��� ������� ����� �������� ��������� ������,
//������������ ����� ������ �������� �� ������� ������� pthread_cancel.
//
//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//using namespace std;
//
//void* ThreadF(void*) {
//    // ��������� ������ ������ � ����� �����
//    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
//
//    cout << "�������� ����� �������..." << endl;
//
//    // �������� ���������� ������
//    for (int i = 0; i < 10; ++i) {
//        cout << "�������� ����� ��������... " << i << endl;
//        sleep(1);  // ���������� ��� �� 1 �������
//    }
//
//    cout << "�������� ����� �������� ��������������." << endl;
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
//    cout << "�������� ����� ��� �������� ������������." << endl;
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
