#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
// 별표 위치로 되돌아가며 0개 이상의 문자를 차례로 비교한다.
bool matches(const char* pattern, const char* name) {
    int i=0, j=0, star=-1, retry=0;
    while (name[j] != '\0') {
        if (pattern[i] != '\0' && (pattern[i]=='?' || pattern[i]==name[j])) { ++i; ++j; }
        else if (pattern[i]=='*') { star=i++; retry=j; }
        else if (star>=0) { i=star+1; j=++retry; }
        else return false;
    }
    while (pattern[i]=='*') ++i;
    return pattern[i]=='\0';
}
int main() {
    char filename[100], data[1000][100], pattern[100];
    int count, size=0;
    cout << "input file name: ";
    cin.width(100); if (!(cin >> filename >> count) || count<0) return 1;
    ifstream fin(filename);
    if (!fin) { cout << "no" << endl; return 1; }
    while (size<1000 && fin.getline(data[size],100)) ++size;
    if (!fin.eof() && (fin.fail() || size==1000)) { cerr << "File too large" << endl; return 1; }
    for (int i=0; i<count; ++i) {
        cin.width(100); if (!(cin >> pattern)) return 1;
        for (int j=0; j<size; ++j) if (matches(pattern,data[j])) cout << data[j] << endl;
        cout << endl;
    }
}
