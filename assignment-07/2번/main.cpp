// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <iostream>

char *my_strtok(char *str);

int main() {

    char input[100];
    if (!std::cin.getline(input, sizeof(input)))
        return 1;
    char *ptr = my_strtok(input);
    while (ptr != NULL) {

        std::cout << ptr << std::endl;
        ptr = my_strtok(NULL);
    }

    return 0;
}

char *my_strtok(char *str) {
    int i = 0;
    char *cur;
    static char *pre = nullptr;

    if (str == NULL) {
        cur = pre;
    } else {
        cur = str;
    }

    if (cur == nullptr || cur[i] == '\0')
        return NULL;

    while (1) {
        if (cur[i] == '@' || cur[i] == '.' || cur[i] == '\0') {
            if (cur[i] == '\0') {
                pre = &cur[i];
            } else {
                pre = &cur[i + 1];
                cur[i] = '\0';
            }
            break;
        }
        i++;
    }

    return cur;
}
