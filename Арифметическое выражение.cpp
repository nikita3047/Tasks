#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int znak = 1;
vector <long long> st;
vector <char> op;

bool isOperation(char ch) {
    return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^';
}

bool isUnaryMinus(int i) {
    if (s[i] == '-' && (i == 0 || isOperation(s[i - 1]) || s[i - 1] == '(')) {
        znak = -1;
        return true;
    }
    return false;
}

long long qPower(long long a, long long b) {
    long long res = 1;
    if (b < 0)res = 0;
    else {
        while (b) {
            if (b % 2 == 1)res *= a;
            a *= a;
            b /= 2;
        }
    }
    return res;
}

void process(char ch) {
    long long b = st.back();
    st.pop_back();
    long long a = st.back();
    st.pop_back();
    switch (ch) {
        case '+':st.push_back(a + b);
            break;
        case '-':st.push_back(a - b);
            break;
        case '*':st.push_back(a * b);
            break;
        case '/':st.push_back(a / b);
            break;
        case '^':long long t = qPower(a, b);
            st.push_back(t);
            break;
    }
    return;
}

int priority(char op) {
    return ((op == '(') ? 1 :
            ((op == '+' || op == '-') ? 2 :
            ((op == '*' || op == '/') ? 3 : 4)));
}

void calculate(int pr) {
    while (!op.empty() && priority(op.back()) >= pr) {
        process(op.back());
        op.pop_back();
    }
    return;
}

long long calculator(string s, long long x, long long y) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            if (!isUnaryMinus(i)) {
                calculate(2);
                op.push_back('-');
            }
        } else if (s[i] == '(') {
            op.push_back(s[i]);
        } else if (s[i] == ')') {
            calculate(2);
            op.pop_back();
        } else if (isOperation(s[i])) {
            calculate(priority(s[i]));
            op.push_back(s[i]);
        } else if (s[i] == 'x') {
            st.push_back(x * znak);
            znak = 1;
        } else if (s[i] == 'y') {
            st.push_back(y * znak);
            znak = 1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            long long tmp = s[i] - '0';
            while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                i++;
                tmp *= 10;
                tmp += s[i] - '0';
            }
            tmp *= znak;
            znak = 1;
            st.push_back(tmp);
        }
    }
    while (!op.empty()) {
        process(op.back());
        op.pop_back();
    }
    return st.back();
}

int main(int argc, char** argv) {
    cin>>s;
    int n;
    cin>>n;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x>>y;
        st.clear();
        op.clear();
        cout << calculator(s, x, y) << endl;
    }
    return 0;
}