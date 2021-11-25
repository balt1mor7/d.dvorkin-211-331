#include <iostream>
using namespace std;

// Очистка экрана
void clear_screen() {
    cout << "\nСейчас будет очищен экран и выполнен переход в меню.\n";
    system("pause");
    system("cls");
}

// Заполение целочисленного массива
int fill_int_array(int* c_fill_int_array, int len_fill_int_array) {
    int count_len_int = 0;  // счетчик длины массива
    for (int i_fill_int_array = 0; i_fill_int_array < len_fill_int_array; i_fill_int_array++) {
        cin >> *(c_fill_int_array + i_fill_int_array);
        if (*(c_fill_int_array + i_fill_int_array) == 0) { break; }
        else { count_len_int += 1; }
    }
    cout << "\n";
    return count_len_int;
}

// Заполнение символьного массива 
int fill_char_array(char* c_fill_char_array, int len_fill_char_array) {
    int count_len_char = 0;
    for (int i_fill_char_array = 0; i_fill_char_array < len_fill_char_array; i_fill_char_array++) {
        cin >> *(c_fill_char_array + i_fill_char_array);
        if (int(*(c_fill_char_array + i_fill_char_array)) == 48) { break; }
        else { count_len_char += 1; }
    }
    cout << "\n";
    return count_len_char;
}

// Вывод целочисленного массива на печать
void print_int_array(int* c_print_int_array, int len_print_int_array) {
    for (int i_print_int_array = 0; i_print_int_array < len_print_int_array; i_print_int_array++) {
        cout << *(c_print_int_array + i_print_int_array) << " ";
    }
}

// Вывод символьного массива на печать
void print_char_array(char* c_print_char_array, int len_print_char_array) {
    for (int i_print_char_array = 0; i_print_char_array < len_print_char_array; i_print_char_array++) {
        cout << *(c_print_char_array + i_print_char_array) << " ";
    }
}

// Пузырьковая сортировка
void bubble_sorting() {
    // отделение начала функции
    cout << "\n";

    cout << "Пузырьковая сортировка:\n\n";

    // подготовка массива
    int aon_1[1000];  // aon_1 - array_of_number_1
    int len_aon_1;  // длина массива
    len_aon_1 = fill_int_array(aon_1, 1000);
    cout << "Изначальный массив :\n";
    print_int_array(aon_1, len_aon_1);
    cout << "\n\n";

    // сортировка массива
    int replacement;
    for (int i = 0; i < len_aon_1; i++) {
        for (int j = 0; j < len_aon_1 - i - 1; j++) {
            if (aon_1[j] > aon_1[j + 1]) {
                replacement = aon_1[j];
                aon_1[j] = aon_1[j + 1];
                aon_1[j + 1] = replacement;
            }
        }
    }

    cout << "Конечный массив :\n";
    print_int_array(aon_1, len_aon_1);

    // отделение конца функции
    cout << "\n";
}

// Сортировка подсчетом
void sorting_by_counting() {
    // отделение начала функции
    cout << "\n";

    cout << "Сортировка подсчетом:\n\n";

    // подготовка массива
    char aoc_1[1000];  //aoc_1 - array_of_char_1
    int len_aoc_1;
    len_aoc_1 = fill_char_array(aoc_1, 1000);
    cout << "Изначальный массив :\n";
    print_char_array(aoc_1, len_aoc_1);
    cout << "\n\n";

    // подготовка массива для посчёта
    int afc_1[26] = { 0 };  //afc_1 - array_for_counting_1

    // 1й этап сортировки
    for (int i = 0; i < len_aoc_1; i++) {
        for (int j = 0; j < 26; j++) {
            if (int(aoc_1[i] - 'a') == j) {
                afc_1[j] += 1;
            }
        }
    }

    // 2й этап сортировки
    int index_array = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < afc_1[i]; j++) {
            aoc_1[index_array] = 'a' + char(i);
            index_array += 1;
        }
    }

    cout << "Конченый массив :\n";
    print_char_array(aoc_1, len_aoc_1);

    // отделение конца функции
    cout << "\n";
}

// Сортировка слиянием

// Функция сортировки 
void merge_sorting_f(int* arr, int size) {
    int left_size = size / 2; // конец левой части
    int right_size = size - left_size;  // начало правой части
    if (size > 1)
    {
        merge_sorting_f(&arr[0], left_size);  // передача значения в рекурсию
        merge_sorting_f(&arr[left_size], right_size);  // передача значения в рекурсию
    }
    int new_array[1000];  // объявление нового массива, куда будут записываться отсортированный массив 
    int i_count_new_array, ii, jj;  // i_count_new_array - считает во временном масиве позицию, i - позиция в левом массиве, j - правый счетчик, который будет считать от половины до конца
    jj = left_size;
    i_count_new_array = 0;
    ii = 0;
    while ((ii < left_size) or (jj < size))
    {
        if (arr[ii] < arr[jj]) {
            new_array[i_count_new_array++] = arr[ii++];
        }
        else
        {
            new_array[i_count_new_array++] = arr[jj++];
        }
        if (ii == left_size) {
            for (int i = jj; i < size; i++)
            {
                new_array[i_count_new_array++] = arr[i];
            }
            break;
        }
        if (jj == size) {
            for (int i = ii; i < left_size; i++)
            {
                new_array[i_count_new_array++] = arr[i];
            }
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = new_array[i];
    }
}
// Выполнение задания сортировка слиянием
void merge_sorting() {
    cout << "\n";
    int size;
    int mas[1000] = { 0 };
    cout << "Введите количество элементов массива: ";
    cin >> size;
    cout << "\n";
    fill_int_array(mas, size);
    cout << "\nИсходный массив: \n";
    print_int_array(mas, size);
    merge_sorting_f(mas, size);
    cout << "\n\n Отсортированный массив: \n";
    print_int_array(mas, size);
    cout << "\n";
}

// Меню.
int start_menu() {
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    while (true) {
        //Вывод на экран меню
        cout << "Меню:\n"
            << "1. Пузырьковая сортировка\n"
            << "2. Сортировка подсчетом\n"
            << "3. Сортировка слиянием\n"
            << "4. Выход\n";
        cout << "\nЧто вы хотите выполнить? >>> ";
        cin >> choice;
        //Проверка выбора от 1-4, где 1-3 задания, а 4 выход из тела основной функции
        switch (choice) {
        case 1: {
            bubble_sorting();
            break;
        }
        case 2: {
            sorting_by_counting();
            break;
        }
        case 3: {
            merge_sorting();
            break;
        }
        case 4: {
            return 0;
        }
        default: {
            cout << "\nВведено неверное значение\n";
        }
        }
        clear_screen();
    }
}

// Тело основной функции
int main()
{
    // Контроль закрытия меню.
    int result_start_menu;
    result_start_menu = start_menu();
    if (result_start_menu == 0) { return 0; }
}