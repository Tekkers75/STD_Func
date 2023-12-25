#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void printSquare(int num) {
    cout << num * num << " ";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    vector<int> numbers = { 1, 2, 3, 4, 5 };


    cout << "Функция For_each" << endl;
    cout << "Исходные числа: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    
    cout << "Квадраты чисел: ";
    // Применяет функцию printSquare к каждому элементу вектора numbers и выводит квадрат каждого числа.
    for_each(numbers.begin(), numbers.end(), printSquare);
    cout << endl;
    cout << endl;


    cout << "Функция Any_of" << endl;
    /// Проверяет, есть ли в векторе хотя бы одно четное число.
    bool anyEven = any_of(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
        });
    cout << "Есть ли хотя бы одно четное число? " << (anyEven ? "Да" : "Нет") << endl;
    cout << endl;


    cout << "Функция All_of" << endl;
    /// Проверяет, состоят ли все числа в векторе из четных чисел.
    bool allEven = all_of(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
        });
    cout << "Состоят ли все числа из четных чисел? " << (allEven ? "Да" : "Нет") << endl;
    cout << endl;


    cout << "Функция None_of" << endl;
    // Проверяет, что ни одно число в векторе не является четным.
    bool noneEven = none_of(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
        });
    cout << "Ни одно число не является четным? " << (noneEven ? "Да" : "Нет") << endl;
    cout << endl;


    vector<int> squaredNumbers(numbers.size());
    cout << "Функция Transform" << endl;
    /// Применяет функцию, которая возвращает квадрат каждого числа из вектора numbers и сохраняет результаты в вектор squaredNumbers.
    transform(numbers.begin(), numbers.end(), squaredNumbers.begin(), [](int num) {
        return num * num;
        });

    cout << "Исходные числа: ";
    for (int num : numbers) {
       cout << num << " ";
    }
    cout << endl;

    cout << "Квадраты чисел: ";
    for (int num : squaredNumbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;


    vector<int> evenNumbers;
    cout << "Функция Copy_if" << endl;
    /// Копирует только четные числа из вектора numbers в новый вектор evenNumbers.
    copy_if(numbers.begin(), numbers.end(), back_inserter(evenNumbers), [](int num) {
        return num % 2 == 0;
        });

    cout << "Исходные числа: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Четные числа: ";
    for (int num : evenNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}