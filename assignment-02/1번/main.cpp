#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char first[101] = {}, second[101] = {}, combined[201] = {};
    bool counted[256] = {};
    cout << "Input first number: ";
    cin.width(101); if (!(cin >> first)) return 1;
    cout << "Input second number: ";
    cin.width(101); if (!(cin >> second)) return 1;
    strcpy(combined, first); strcat(combined, second);
    // 처음 나타난 순서대로 각 문자의 출현 횟수를 센다.
    for (int i = 0; combined[i] != '\0'; ++i) {
        unsigned char digit = static_cast<unsigned char>(combined[i]);
        if (counted[digit]) continue;
        counted[digit] = true;
        int count = 0;
        for (int j = 0; combined[j] != '\0'; ++j)
            if (combined[j] == combined[i]) ++count;
        cout << combined[i] << count;
    }
}
