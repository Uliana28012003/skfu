//#include <iostream>
//#include <vector>
//#include <string>
//#include <thread>
//#include <fstream>
//#include <filesystem>
//#include <future>
//using namespace std;
//
//namespace fs = std::filesystem;
//
//// Функция для копирования файла
//void copyFile(const string& src, const string& dst) {
//    ifstream in(src, ios::binary);
//    ofstream out(dst, ios::binary);
//    out << in.rdbuf();
//}
//
//// Функция для рекурсивного копирования директории
//void copyDir(const string& src, const string& dst) {
//    // Создание новой директории в пункте назначения
//    std::filesystem::create_directory(dst);
//
//    std::vector<std::filesystem::path> files, directories;
//
//    // Получение списка файлов и директорий в исходной директории
//    for (const auto& entry : std::filesystem::directory_iterator(src)) {
//        if (std::filesystem::is_regular_file(entry)) {
//            files.push_back(entry.path());
//        }
//        else if (std::filesystem::is_directory(entry)) {
//            directories.push_back(entry.path());
//        }
//    }
//
//    std::vector<std::future<void>> fileFutures, dirFutures;
//
//    // Запуск копирования файлов асинхронно
//    for (const auto& file : files) {
//        string newSrc = file.string();
//        string newDst = dst + "/" + file.filename().string();
//        fileFutures.push_back(async(launch::async, copyFile, newSrc, newDst));
//    }
//
//    // Запуск копирования директорий асинхронно
//    for (const auto& directory : directories) {
//        string newSrc = directory.string();
//        string newDst = dst + "/" + directory.filename().string();
//        dirFutures.push_back(async(launch::async, copyDir, newSrc, newDst));
//    }
//
//    // Дожидаемся завершения всех операций копирования
//    for (auto& future : fileFutures) {
//        future.get();
//    }
//    for (auto& future : dirFutures) {
//        future.get();
//    }
//}
//
//int main() {
//    // Начало программы
//    cout << "\n\n_________start__________\n\n";
//
//    // Пути исходной и целевой директорий
//    string src = "D:/3 курс/2 семестр/Многопоточка/ConsoleApplication1";
//    string dst = "D:/3 курс/2 семестр/Многопоточка/ConsoleApplication1-copy";
//
//    // Создание потока для копирования директории
//    thread t(copyDir, src, dst);
//    t.join(); // Ожидание завершения потока
//
//    // Конец программы
//    cout << "\n\n_______________end_______________\n\n";
//
//    return 0;
//}
