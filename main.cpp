#include <iostream>        // Підключення для вводу/виводу
#include <fstream>         // Для роботи з файлами
#include <string>          // Для використання std::string
#include <cstring>         // Для функцій роботи з C-рядками (strncpy)
#include "my_replace.h"    // Підключення власного заголовочного файлу з функцією my_replace
#include "text_processing.h" // Підключення заголовочного файлу з функціями для обробки тексту

using namespace std;       // Використання простору імен std

int main() {
    // Коментар: створення sample.txt можна виконати вручну або розкоментувати виклик create_sample_file()
    // create_sample_file();

    int choice;             // Змінна для збереження вибору користувача у меню

    do {
        // Виведення меню для користувача
        cout << "\n1. Замінити частину рядка (my_replace і string::replace)\n";
        cout << "2. Порахувати кількість слів у введеному рядку\n";
        cout << "3. Обробити файл (sample.txt) і зберегти у output.txt\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";

        cin >> choice;       // Зчитування вибору користувача
        cin.ignore();        // Очищення буфера вводу (щоб getline працював коректно після cin)

        switch (choice) {
            case 1: {   // Завдання 1: заміна частини рядка
                string str;
                cout << "Введіть рядок: ";
                getline(cin, str);  // Зчитування рядка з консолі

                // Копіюємо рядок у масив char для функції my_replace
                char c_str[256];
                strncpy(c_str, str.c_str(), sizeof(c_str)); // Копіюємо не більше 256 символів
                c_str[sizeof(c_str) - 1] = '\0';             // Гарантуємо нуль-термінацію

                size_t pos, len;    // Змінні для позиції і довжини заміни
                string repl;        // Рядок, який вставимо замість видаленого фрагмента

                cout << "Введіть позицію для заміни: ";
                cin >> pos;         // Зчитування позиції початку заміни
                cout << "Введіть довжину для заміни: ";
                cin >> len;         // Зчитування довжини сегмента для заміни
                cin.ignore();       // Очищення буфера після числового вводу
                cout << "Введіть рядок для вставки: ";
                getline(cin, repl); // Зчитування рядка для вставки

                string str_copy = str;  // Копія рядка для стандартної заміни
                if (pos <= str_copy.length()) // Перевірка, чи позиція у межах рядка
                    str_copy.replace(pos, len, repl);  // Виконання заміни за допомогою std::string::replace

                cout << "Результат string::replace: " << str_copy << endl;

                my_replace(c_str, pos, len, repl.c_str()); // Виклик власної функції заміни
                cout << "Результат my_replace: " << c_str << endl;

                // Запис результату у файл (додаємо в кінець файлу)
                ofstream result_file("result_task_1.txt", ios::app);
                if (result_file) {
                    result_file << "Рядок: " << str << "\nРезультат заміни: " << c_str << endl;
                    result_file.close();
                } else {
                    cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
                }

                break;
            }
            case 2: {  // Завдання 2: підрахунок кількості слів
                string line;
                cout << "Введіть рядок для підрахунку слів: ";
                getline(cin, line);  // Зчитування рядка

                int count = count_words(line);  // Виклик функції для підрахунку слів
                cout << "Кількість слів: " << count << endl;

                // Запис результату у файл (додаємо в кінець)
                ofstream result_file("result_task_2.txt", ios::app);
                if (result_file) {
                    result_file << "Рядок: " << line << "\nКількість слів: " << count << endl;
                    result_file.close();
                } else {
                    cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
                }
                break;
            }
            case 3: {  // Завдання 3: обробка файлу sample.txt
                process_file();  // Виклик функції обробки файлу
                cout << "Файл оброблено. Перевірте output.txt." << endl;
                break;
            }
            case 0:  // Вихід з програми
                cout << "Вихід..." << endl;
                break;
            default: // Обробка невірного вводу
                cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);  // Цикл працює, доки користувач не обере 0 (вихід)

    return 0;  // Повернення 0 з main означає успішне завершення програми
}
