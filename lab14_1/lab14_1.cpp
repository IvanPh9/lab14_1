#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <math.h>
//Підключення бібліотек

void copi(int* arr, int* arr_m, int size) { //Функція для копіювання масиву, що б надалі його сортувати
    for (int i = 0; i < size; ++i) {
        arr_m[i] = arr[i];
    }
}

void swap(int* a, int* b) { //Функція для перемішування елементів 
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int* arr, int size) { //Функція сортування масиву
    for (int i = 0; i < size - 1; ++i) { //Подвійний цикл, після кожної строчки ми проробляємо так ще ту саму кількість разів, скільки елементів в масиві для правильного сортування
        for (int j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);//Викликаємо функцію обміну елементами
            }
        }
    }
}

void findMinMax(int* arr_m, int* arr, int size, int* minIndex, int* maxIndex) { //Функція для порівняння двох масивів (сортованого і ні), де значення першого елемента сортованого мінімальне шукає такий самий елемент з індексом в несортованому масиві 
    *minIndex = 0;                                                              //і змінює значення змінної для індексу на відповідне в несортованому. Аналогічно для максимального значення
    *maxIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (arr_m[0] == arr[i]) {
            *minIndex = i;
        }
        if (arr_m[size - 1] == arr[i]) {
            *maxIndex = i;
        }

    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); //Українізація

    int size;
    do { //Введення розміру масиву з циклом післяумовою, яка перевіряє чи не є розмір масиву меньше за 0
        printf("Введiть розмiр масиву: ");
        scanf_s("%d", &size);
    } while (size <= 0);

    int* arr = (int*)malloc(size * sizeof(int)); //Створення динамічної комірки пам'яті для масиву елементів
    int* arr_m = (int*)malloc(size * sizeof(int)); //Створення динамічної комірки пам'яті для сортування масиву елементів
    int minIndex, maxIndex;

    printf("Введiть елементи масиву:\n"); //Введення елементів до пустого масиву за допомогою циклу
    for (int i = 0; i < size; ++i) {
        printf("Елемент %d: ", i + 1);
        scanf_s("%d", &arr[i]);
    }

    copi(arr, arr_m, size); // Копіювання масиву 
    sortArray(arr_m, size); // Сортування масиву
    findMinMax(arr_m, arr, size, &minIndex, &maxIndex); // Знаходження у несортованому масиві елементи першого і останнього сортованого масиву, як найменше та найбільше відповідно
    int distance = abs(minIndex - maxIndex) - 1; //Обрахування відстані

    printf("\nМiнiмальне значення: %d\n", arr[minIndex]); // Виводимо результати
    printf("Максимальне значення: %d\n", arr[maxIndex]);
    printf("Вiдстань мiж позицiями: %d\n", distance);

    free(arr); //Звільнення динамічної комірки пам'яті 
    free(arr_m);//Звільнення динамічної комірки пам'яті 

    return 0;
}
