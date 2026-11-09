// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "oopstd.h"
#include <iostream>
using namespace std;
int main() {
    oopstd::string a;
    a.assign("Hi");
    cout << a.c_str() << endl << endl;
    oopstd::string example("Hello World");
    cout << example.at(2) << endl << endl;
    const char *b = example.c_str();
    cout << b << endl << endl;
    oopstd::string example2("Hello World");
    example2.clear();
    cout << example2.c_str() << endl << endl;
    oopstd::string example3("Hello World");
    example3.push_back('b');
    cout << example3.c_str() << endl << endl;
    oopstd::string ex1("HELLO");
    cout << ex1.compare("Hello") << endl
         << ex1.compare("HELLO") << endl
         << ex1.compare("HA") << endl
         << endl;
    oopstd::string example4("Hello World");
    cout << example4.replace(0, 5, "Hi").c_str() << endl << endl;
    oopstd::string example5 = "Hello World";
    oopstd::string e = example5.substr(5, 10);
    cout << e.c_str() << endl << endl;
    oopstd::string example6 = "Hello World";
    cout << example6.find("World") << endl << endl;
    oopstd::string number = "10bus";
    size_t sz;
    int num = oopstd::stoi(number, &sz, 10);
    cout << num << endl << sz << endl << endl;
    oopstd::string float_number = "1.5abc";
    size_t sz1;
    float value = oopstd::stof(float_number, &sz1);
    cout << value << endl << sz1 << endl << endl;
    oopstd::string y = oopstd::to_string(123);
    cout << y.c_str() << endl << endl;
    oopstd::string z = oopstd::to_string(static_cast<float>(-24.3));
    cout << z.c_str() << endl << endl;
}
