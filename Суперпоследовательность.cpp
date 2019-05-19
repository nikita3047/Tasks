/* Суперпоследовательность
Последовательность чисел a1, a2, … an называется суперпоследовательностью, если выполняется:

0 < a1 < a2 < … < an
ни одно из чисел не является суммой двух или более других чисел.
Input
В первой строке записано количество Т тестов. Каждый тест состоит из одной строки. Сначала в строке записано число N (1 ≤ N ≤ 50). Далее идут N чисел, разделенных пробелом, каждое из которых не меньше 1 и не больше 1000.

Output
Для каждого тестового случая вывести в отдельную строку Yes, если это суперпоследовательность, и No в противном случае.

Примеры
Входные данные
3
2 1 2
3 1 2 3
10 1 3 16 19 25 70 100 243 245 306
Результат работы
Yes
No
No*/
#include <iostream>
#include <cstring>

using namespace std;

int t, n, a[51], sum[50001];
bool tmp;

int main() {
    cin>>t;
    while (t--) {
        memset(sum, 0, sizeof (sum));
        memset(a, 0, sizeof (a));
        cin >> n;
        tmp = true;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i < n; i++)
            if (a[i] <= a[i - 1]) {
                tmp = false;
                break;
            }
        if (tmp) {
            for (int i = 0; i < n; i++) {
                if (sum[a[i]] == 1) {
                    tmp = false;
                    break;
                }
                for (int j = 49999; j >= 0; j--) {
                    if (sum[j] == 1) sum[j + a[i]] = 1;
                }
                sum[a[i]] = 1;
            }
        }
        if (tmp)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
