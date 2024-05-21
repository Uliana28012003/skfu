//�������� ���������, ������� ������� ������ ������, ����������� ���� � �� �� �������.
//��� ������� ������ ����������� ������������������ ��������� �����, ���������� ��� ��������.
//������ �� ��������� ������� ������ ����������� ��������� ������������������ �����.

//#include <iostream>
//#include <pthread.h>
//#include <vector>
//#include <string>
//#include <unistd.h>
//
//using namespace std;
//
//// ��������� ��� �������� ���������� � �����
//struct ThreadParams {
//    int t;
//    vector<string> messages;
//};
//
//// �������, ������� ����� ��������� ������
//void* threadF(void* arg) {
//    ThreadParams* params = (ThreadParams*)arg;
//    int t = params->t;
//    vector<string> messages = params->messages;
//
//    cout << "����� " << t << ":\n";
//    for (const string& message : messages) {
//        cout << message << endl;
//    }
//
//    pthread_exit(NULL);
//}
//
//int main() {
//    // ������� ������ ������������������� ����� ��� ������� ������
//    vector<vector<string>> allMessages = {
//        {"��������� 1 �� ������ 1", "��������� 2 �� ������ 1", "��������� 3 �� ������ 1"},
//        {"��������� 1 �� ������ 2", "��������� 2 �� ������ 2", "��������� 3 �� ������ 2"},
//        {"��������� 1 �� ������ 3", "��������� 2 �� ������ 3", "��������� 3 �� ������ 3"},
//        {"��������� 1 �� ������ 4", "��������� 2 �� ������ 4", "��������� 3 �� ������ 4"}
//    };
//
//    // ������� ������ ��������������� �������
//    pthread_t threads[4];
//    // ������� ������ ���������� ��� ������� ������
//    ThreadParams params[4];
//
//    // ������� � ��������� ������ �����(���������)
//    for (int i = 0; i < 4; ++i) {
//        params[i].t = i + 1;
//        usleep(200000); // ��������
//        params[i].messages = allMessages[i];
//        if (pthread_create(&threads[i], NULL, threadF, (void*)&params[i]) != 0) {
//            cerr << "������: ���������� ������� ����� " << i + 1 << endl;
//            return 1;
//        }
//    }
//
//    // ���� ���������� ������� ������(���������)
//    for (int i = 0; i < 4; ++i) {
//        if (pthread_join(threads[i], NULL) != 0) {
//            cerr << "������ ��� ������������� ������ " << i + 1 << endl;
//            return 1;
//        }
//    }
//
//    return 0;
//}
