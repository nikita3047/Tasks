/*Простая сумма
Дан массив из N элементов, необходимо находить сумму элементов массива на отрезке.

Формат входных данных
Первая строка входных данных содержит два целых числа N и K - число чисел в массиве и количество запросов. (1 ≤ N ≤ 106); (1 ≤ K ≤ 105). Следующие K строк содержат запросы:

1 i x – присвоить i-му элементу массива значение x (1 ≤ i ≤ n; 0 ≤ x ≤ 109)
2 l r – найти сумму чисел в массиве на позициях от l до r. (1 ≤ l ≤ r ≤ n)
Изначально массив заполнен нулями.

Формат результата
На каждый запрос вида 2 l r нужно вывести единственное число – сумму на отрезке.

Примеры
Входные данные
5 9
1 2 2
1 3 1
1 4 2
2 1 1
2 2 2
2 3 3
2 4 4
2 5 5
2 1 5
Результат работы
0
2
1
2
0
5*/
#include <iostream>
#include <cmath>

using namespace std;

long long  tree[4000004];
int start;

void Update(int x, int value) {
    x += start;
    tree[x] = value;
    while (x / 2 > 0) {
        x /= 2;
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }
    return;
}

void GetSum(int l, int r) {
    l += start;
    r += start;
    long long sum = 0;
    while (l <= r) {
        if (l % 2 != 0) {
            sum += tree[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += tree[r];
            r--;
        }
        r /= 2;
        l /= 2;
    }
    cout << sum << endl;
    return;
}

int main() {
    int n, k, t, a, b;
    cin >> n>>k;
    start = 1;
    while (start < n)start *= 2;
    for (int i = 0; i < k; i++) {
        cin >> t >> a>>b;
        if (t == 1) {
            Update(a - 1, b);
        } else {
            GetSum(a - 1, b - 1);
        }
    }
    return 0;
}