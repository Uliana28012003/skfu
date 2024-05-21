//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <thread>
//#include <future>
//#include <chrono>
//#include <math.h>
//using namespace std;
//
//// Глобальная переменная, обозначающая количество итераций для вычисления π
//int iterations = 200000000;
//
//// Функция для вычисления части суммы ряда Лейбница для вычисления π
//long double calculate_pi_portion(int start, int end) {
//    long double sum = 0;
//    // Вычисление суммы части ряда от start до end
//    for (int i = start; i <= end; i++) {
//        sum += ((pow(-1, i)) / (2 * i + 1));
//    }
//    return sum;
//}
//
//// Функция для однопоточного вычисления π
//void task8Single() {
//    long double pi = 0;
//    // Вычисление π по формуле Лейбница
//    for (int i = 0; i < iterations; i++) {
//        pi += ((pow(-1, i)) / (2 * i + 1));
//    }
//    pi *= 4;
//    // Вывод результата
//    cout << setprecision(10) << pi << endl;
//}
//
//// Функция для многопоточного вычисления π
//void task8Multi() {
//    const int NUM_THREADS = 10; // Количество потоков
//    int iterations_per_thread = iterations / NUM_THREADS; // Количество итераций на один поток
//    long double pi = 0;
//
//    // Создание вектора для хранения будущих результатов
//    std::vector<std::future<long double>> futures(NUM_THREADS);
//    // Запуск каждого потока для вычисления своей части суммы
//    for (int i = 0; i < NUM_THREADS; i++) {
//        int start = i * iterations_per_thread;
//        int end = (i == NUM_THREADS - 1) ? iterations - 1 : start + iterations_per_thread - 1;
//        // Асинхронный вызов функции вычисления части суммы
//        futures[i] = std::async(std::launch::async, calculate_pi_portion, start, end);
//    }
//    // Получение результатов от каждого потока и их суммирование
//    for (auto& future : futures) {
//        long double result = future.get();
//        pi = pi + result;
//    }
//    // Умножение суммы на 4 для получения значения π
//    pi = pi * 4;
//    // Вывод результата
//    std::cout << setprecision(10) << pi << endl;
//}
//
//int main() {
//    auto start = chrono::high_resolution_clock::now();
//    task8Single(); // Однопоточное вычисление π
//    auto end = chrono::high_resolution_clock::now();
//    auto ms_int = chrono::duration_cast<chrono::milliseconds>(end - start);
//    std::cout << "Single thread: " << ms_int.count() << " ms\n"; // Вывод времени выполнения однопоточного метода
//
//    start = chrono::high_resolution_clock::now();
//    task8Multi(); // Многопоточное вычисление π
//    end = chrono::high_resolution_clock::now();
//    ms_int = chrono::duration_cast<chrono::milliseconds>(end - start);
//    std::cout << "Multi thread: " << ms_int.count() << " ms\n"; // Вывод времени выполнения многопоточного метода
//
//    return 0;
//}
