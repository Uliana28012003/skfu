//������������� ��������� ���. 1 ���,
//����� ����� ������������ � �������� ������� ��� ������������� :
//������� ������������ ����� �������� ������ ������, ����� ��������,
//����� ������������ ������ ������ � �.�.����������� ��������.
//������������� ������������ �������� ���� PTHREAD_MUTEX_ERRORCHECK.
//����� � ������� �������� ���������� ����� ������
//(sleep(3C) / usleep(3C), sched_yield(3RT))
//� �������� ����� ����������� ������������
//������ �� ����� �������������.
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
//            cout << "�������� �����: " << counter++ << endl;
//        }
//        this_thread::sleep_for(chrono::milliseconds(100)); // ����� �������� ����������
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
//            cout << "������������ �����: " << counter++ << endl;
//        }
//        this_thread::sleep_for(chrono::milliseconds(100)); // ����� �������� ����������
//    }
//
//    t.join();
//
//    return 0;
//}
