/*#include <iostream>
#include <cstdio>
#include <cctype>
#include "Windows.h"
using namespace std;

bool isVowel(char c) 
{
    char lower_c = tolower(c);
    const char* vowels = "аеєиіїоуюяaeiou";

    for (int i = 0; vowels[i] != '\0'; i++) 
    {
        if (vowels[i] == lower_c) return true;
    }
    return false;
}

bool isConsonant(char c) 
{
    char lower_c = tolower(c);
    const char* consonants = "бвгджзйклмнпрстфхцчшщbcdfghjklmnpqrstvwxyz";

    for (int i = 0; consonants[i] != '\0'; i++) 
    {
        if (consonants[i] == lower_c) return true;
    }
    return false;
}

int main() {
    char input_filename[100];
    char output_filename[100];

    cout << "Введіть імя файлу для читання: ";
    cin >> input_filename;
    cout << "Введіть імя файлу для запису результату: ";
    cin >> output_filename;

    cout << "Відкриваємо файл " << input_filename << "..." << endl;

    int total_chars = 0;
    int total_lines = 0;
    int vowel_count = 0;
    int consonant_count = 0;
    int digit_count = 0;

 
    FILE* input_file;
    if (fopen_s(&input_file, input_filename, "r") != 0 || input_file == NULL) 
    {
        cout << "Помилка. не вдалося відкрити файл " << input_filename << endl;
        cout << "Перевірте, чи файл існує!" << endl;
        system("pause");
        return 1;
    }

    cout << "Файл відкрито успішно! Аналізуємо..." << endl;

    char c;
    while (!feof(input_file)) 
    {
        c = fgetc(input_file);
        if (feof(input_file)) break;

        total_chars++;

        if (isVowel(c)) vowel_count++;
        else if (isConsonant(c)) consonant_count++;
        else if (c >= '0' && c <= '9') digit_count++;

        if (c == '\n') total_lines++;
    }

    if (total_chars > 0 && total_lines == 0) 
    {
        total_lines = 1;
    }

    fclose(input_file);

    cout << "Записуємо результат..." << endl;

    FILE* output_file;
    if (fopen_s(&output_file, output_filename, "w") != 0 || output_file == NULL) 
    {
        cout << "Помилка. не вдалося створити файл " << output_filename << endl;
        system("pause");
        return 1;
    }

    fprintf(output_file, "Статистика для файлу: %s\n", input_filename);
    fprintf(output_file, "Кількість символів: %d\n", total_chars);
    fprintf(output_file, "Кількість рядків: %d\n", total_lines);
    fprintf(output_file, "Кількість голосних букв: %d\n", vowel_count);
    fprintf(output_file, "Кількість приголосних букв: %d\n", consonant_count);
    fprintf(output_file, "Кількість цифр: %d\n", digit_count);

    fclose(output_file);

    cout << "Статистика записна у файл" << endl;
    cout << "Вхідний файл: " << input_filename << endl;
    cout << "Вихідний файл: " << output_filename << endl;
    return 0;
}*/