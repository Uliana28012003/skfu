////���������� ���������� �������� ���������� sleepsort � ������������ O(N) (�� ������������� �������).
////
////�� ����������� ���� ��������� �������� �� ����� 100 ����� ��������� �����.
////��� ���������� ������� ��� ������, ��������������� �� �����.
////������ ���������� ����� ����� ���������� � ������������ �������.
////
////��� ������ ������� ������, �������� ����� � ��������� �� ��� ������ � �������� ���������.
////����� ������ ������� sleep(2) ��� usleep(2) � ����������, ���������������� ����� ���� ������.
////����� ����� ������� ������ � ����������� ����� ������ � �����������.
////�� ������� �������� ����������� ������������������ ������� ���������, �� �������� �������� ������������ ����������.
//
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <string>
//#include <unistd.h> // ��� ������� sleep
//
//using namespace std;
//
//void sleepsort(const string& str) {
//    // ������������ ����� ��� ��������������� ����� ������
//    unsigned int sleeptime = str.length() * 10000; // �������� �� 10000 ��� ���������� ��������
//
//    // ����� �������� �� �������� �����
//    usleep(sleeptime);
//
//    // ������� ��������������� ������
//    cout << str << endl;
//}
//
//int main() {
//    vector<string> strings;
//
//    // ��������� ������ �� ������������ �����
//    string line;
//    while (getline(cin, line)) {
//        strings.push_back(line);
//    }
//
//    // ������� ������ ��� ������ ������
//    vector<thread> threads;
//    for (const auto& str : strings) {
//        threads.emplace_back(sleepsort, str);
//    }
//
//    // ���������� ���������� ���� �������
//    for (auto& th : threads) {
//        th.join();
//    }
//
//    return 0;
//}
