// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#pragma once
#include <cstddef>
namespace oopstd {
class string {
    char *data_;
    std::size_t length_;

  public:
    static const std::size_t npos = static_cast<std::size_t>(-1);
    string();
    string(const char *text);
    string(const string &other);
    ~string();
    string &operator=(const string &other);
    string &assign(const char *text);
    char &at(std::size_t index);
    const char &at(std::size_t index) const;
    const char *c_str() const;
    void clear();
    void push_back(char ch);
    int compare(const char *text) const;
    string &replace(std::size_t pos, std::size_t count, const char *text);
    string substr(std::size_t pos, std::size_t count = npos) const;
    std::size_t find(const char *text) const;
};
int stoi(const string &text, std::size_t *pos = nullptr, int base = 10);
float stof(const string &text, std::size_t *pos = nullptr);
string to_string(int value);
string to_string(float value);
} // namespace oopstd
