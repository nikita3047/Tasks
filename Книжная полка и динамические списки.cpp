/*
Книжная полка и динамические списки
Денис раскладывает свои книги на полку. Если на полке нет ни одной книги, то он просто ставит её, если есть, то ставит либо справа, либо слева от уже расставленных книг. Забирает книги он так же, то есть снимает только с правого или левого края. По заданной информации требуется смоделировать действия Дениса и вывести номера книг, которые он будет снимать.

Внимание! При решении задачи нельзя
использовать:
классы библиотеки STL
массивы
Формат входных данных
Входные данные содержат информацию об операциях, которые выполнил денис, и заканчиваются символом EOF. Информация о каждой операции содержится в отдельной строке.

Каждая операция постановки книги на полку описывается парой чисел. Первое из них (1 или 2) показывает, книга ставится с левого края или с правого, соответственно. Второе целое число (от 0 до 109) обозначает номер книги. Номера книг могут повторяться.

Операции снятия книги с полки описывается одним числом. Число 3 означает, что книга снимается с левого края, 4 - с правого. Гарантируется, что для каждой операции снятия книги на полке будет хотя бы одна книга.

Формат результата
Для каждой операции снятия книги с полки вывести номер снимаемой книги.

Примеры
Входные данные
1 1
2 2
1 3
2 7
2 9
3
4
3
3
4
Результат работы
3
9
1
2
7
*/

#include <cstdio>

struct TList {
    int num;
    TList *prev;
    TList *next;
} *start = NULL, *last = NULL;

void deleteLast() {
    printf("%d\n",last->num);
    if (start == last) {
        start = last = NULL;
        return;
    }
    last = last->prev;
    last->next = NULL;
    return;
}

void deleteFirst() {
    printf("%d\n",start->num);
    if (start == last) {
        start = last = NULL;
        return;
    }
    start = start->next;
    start->prev = NULL;
    return;
}

void addLeft(int v) {
    TList *left = new TList;
    left->num = v;
    left->next = NULL;
    if (start == NULL) {
        left->prev = NULL;
        start = last = left;
        return;
    }
    left->next = start;
    start->prev = left;
    left->prev = NULL;
    start = left;
    return;
}

void addRight(int v) {
    TList *right = new TList;
    right->num = v;
    right->prev = NULL;
    if (last == NULL) {
        right->prev = NULL;
        start = last = right;
        return;
    }
    last->next = right;
    right->prev = last;
    right->next = NULL;
    last = right;
    return;
}

int tmp, dir;

int main() {
    while (scanf("%d",&dir)!=EOF) {
        switch (dir) {
            case (1):
                scanf("%d",&tmp);
                addLeft(tmp);
                break;
            case (2):
                scanf("%d",&tmp);
                addRight(tmp);
                break;
            case (3):deleteFirst();
                break;
            case(4):deleteLast();
                break;
        }
    }
    return 0;
}