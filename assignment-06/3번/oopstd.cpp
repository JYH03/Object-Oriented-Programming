// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "oopstd.h"
#include <cerrno>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
namespace oopstd {
string::string() : data_(new char[1]{'\0'}), length_(0) {}
string::string(const char *text) : data_(nullptr), length_(0) { assign(text); }
string::string(const string &other) : data_(nullptr), length_(0) { assign(other.data_); }
string::~string() { delete[] data_; }
string &string::operator=(const string &other) {
    if (this != &other)
        assign(other.data_);
    return *this;
}
string &string::assign(const char *text) {
    if (!text)
        throw std::invalid_argument("null string");
    const std::size_t n = std::strlen(text);
    char *copy = new char[n + 1];
    std::memcpy(copy, text, n + 1);
    delete[] data_;
    data_ = copy;
    length_ = n;
    return *this;
}
char &string::at(std::size_t index) {
    if (index >= length_)
        throw std::out_of_range("string index");
    return data_[index];
}
const char &string::at(std::size_t index) const {
    if (index >= length_)
        throw std::out_of_range("string index");
    return data_[index];
}
const char *string::c_str() const { return data_; }
void string::clear() {
    data_[0] = '\0';
    length_ = 0;
}
void string::push_back(char ch) {
    char *copy = new char[length_ + 2];
    std::memcpy(copy, data_, length_);
    copy[length_] = ch;
    copy[length_ + 1] = '\0';
    delete[] data_;
    data_ = copy;
    ++length_;
}
int string::compare(const char *text) const { return std::strcmp(data_, text); }
string &string::replace(std::size_t pos, std::size_t count, const char *text) {
    if (pos > length_)
        throw std::out_of_range("replace position");
    if (!text)
        throw std::invalid_argument("null string");
    if (count > length_ - pos)
        count = length_ - pos;
    std::size_t extra = std::strlen(text), size = length_ - count + extra;
    char *copy = new char[size + 1];
    std::memcpy(copy, data_, pos);
    std::memcpy(copy + pos, text, extra);
    std::memcpy(copy + pos + extra, data_ + pos + count, length_ - pos - count + 1);
    delete[] data_;
    data_ = copy;
    length_ = size;
    return *this;
}
string string::substr(std::size_t pos, std::size_t count) const {
    if (pos > length_)
        throw std::out_of_range("substring position");
    if (count > length_ - pos)
        count = length_ - pos;
    string result;
    char *copy = new char[count + 1];
    std::memcpy(copy, data_ + pos, count);
    copy[count] = '\0';
    delete[] result.data_;
    result.data_ = copy;
    result.length_ = count;
    return result;
}
std::size_t string::find(const char *text) const {
    const char *found = std::strstr(data_, text);
    return found ? static_cast<std::size_t>(found - data_) : npos;
}
int stoi(const string &text, std::size_t *pos, int base) {
    if (base != 0 && (base < 2 || base > 36))
        throw std::invalid_argument("base");
    errno = 0;
    char *end = nullptr;
    const char *start = text.c_str();
    long value = std::strtol(start, &end, base);
    if (end == start)
        throw std::invalid_argument("integer");
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
        throw std::out_of_range("integer");
    if (pos)
        *pos = static_cast<std::size_t>(end - start);
    return static_cast<int>(value);
}
float stof(const string &text, std::size_t *pos) {
    errno = 0;
    char *end = nullptr;
    const char *start = text.c_str();
    float value = std::strtof(start, &end);
    if (end == start)
        throw std::invalid_argument("float");
    if (errno == ERANGE)
        throw std::out_of_range("float");
    if (pos)
        *pos = static_cast<std::size_t>(end - start);
    return value;
}
string to_string(int value) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%d", value);
    return string(buf);
}
string to_string(float value) {
    char buf[64];
    int n = std::snprintf(buf, sizeof(buf), "%f", static_cast<double>(value));
    if (n < 0 || n >= 64)
        throw std::out_of_range("float output");
    return string(buf);
}
} // namespace oopstd
