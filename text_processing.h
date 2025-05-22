#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H

#include <string>

// Підрахунок слів у рядку (лише кирилиця)
int count_words(const std::string& str);

// Перевірка рядка на допустимі символи (літери, цифри, пробіли, підкреслення)
bool is_valid(const std::string& str);

// Створення тестового файлу sample.txt з 10 рядками
void create_sample_file();

// Обробка файлу sample.txt і запис результатів у output.txt
void process_file();

#endif // TEXT_PROCESSING_H
