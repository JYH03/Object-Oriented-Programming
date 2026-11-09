// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class Person {
  protected:
    int age;
    char name[32];

  public:
    Person();
    virtual ~Person();
    virtual void Say() = 0;
};

Person::Person() : age(0) { strcpy(name, ""); }

Person::~Person() {}

class Student : public Person {
  protected:
    char studentNum[11];
    char major[32];
    int schoolYear;

  public:
    Student();
    ~Student();
    int getAge();
    char *getName();
    char *getStudentNum();
    char *getMajor();
    int getSchoolYear();
    void setAge(int age);
    void setName(const char *name);
    void setStudentNum(const char *studentNum);
    void setMajor(const char *major);
    void setSchoolYear(int year);
    void Say() override;
};

Student::Student() : Person(), schoolYear(0) {
    strcpy(studentNum, "");
    strcpy(major, "");
}

Student::~Student() {}

int Student::getAge() { return age; }

char *Student::getName() { return name; }

char *Student::getStudentNum() { return studentNum; }

char *Student::getMajor() { return major; }

int Student::getSchoolYear() { return schoolYear; }

void Student::setAge(int age) { this->age = age; }

void Student::setName(const char *name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}

void Student::setStudentNum(const char *studentNum) {
    strncpy(this->studentNum, studentNum, sizeof(this->studentNum));
    this->studentNum[sizeof(this->studentNum) - 1] = '\0';
}

void Student::setMajor(const char *major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}

void Student::setSchoolYear(int year) { this->schoolYear = year; }

void Student::Say() {
    int schoolYear = getSchoolYear();
    cout << "I'm a student of KW University." << endl;

    cout << "My name is " << getName() << endl;

    if (schoolYear == 1)

        cout << "I'm " << getAge() << " years old and I'm a freshman" << endl;
    else if (schoolYear == 2) {

        cout << "I'm " << getAge() << " years old and I'm a sophomore" << endl;
    } else if (schoolYear == 3) {

        cout << "I'm " << getAge() << " years old and I'm a junior" << endl;
    } else if (schoolYear == 4) {

        cout << "I'm " << getAge() << " years old and I'm a senior" << endl;
    } else {
        cout << "I'm " << getAge() << " years old and I'm a graduate student" << endl;
    }

    cout << "I'm majoring in " << getMajor() << endl;
}

class Professor : public Person {
  protected:
    char professorNum[11];
    char major[32];

  public:
    Professor();
    virtual ~Professor();

    int getAge();
    char *getName();
    char *getProfessorNum();
    char *getMajor();

    void setProfessorNum(const char *professorNum);
    void setMajor(const char *major);
    void setAge(int age);
    void setName(const char *name);

    virtual void Say();
};

Professor::Professor() : Person() {
    strcpy(professorNum, "");
    strcpy(major, "");
}

Professor::~Professor() {}

int Professor::getAge() { return age; }

char *Professor::getName() { return name; }

char *Professor::getProfessorNum() { return professorNum; }

char *Professor::getMajor() { return major; }

void Professor::setProfessorNum(const char *professorNum) {
    strncpy(this->professorNum, professorNum, sizeof(this->professorNum));
    this->professorNum[sizeof(this->professorNum) - 1] = '\0';
}

void Professor::setMajor(const char *major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}

void Professor::setAge(int age) { this->age = age; }

void Professor::setName(const char *name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}

void Professor::Say() {
    cout << "I'm a professor at KW University." << endl;
    cout << "My name is " << getName() << "." << endl;
    cout << "I'm " << getAge() << " years old." << endl;
    cout << "I'm a professor in " << getMajor() << "." << endl;
}

int main() {
    Student student;
    student.setName("Hong Gill Dong");
    student.setAge(21);
    student.setStudentNum("123456789");
    student.setMajor("Computer Engineering");
    student.setSchoolYear(2);

    Professor professor;
    professor.setName("Choi Choi Choi");
    professor.setAge(52);
    professor.setProfessorNum("8987123");
    professor.setMajor("Computer Engineering");

    Person *pPerson{};
    char job[32];
    cin.width(32);
    if (!(cin >> job))
        return 1;
    if (strcmp(job, "student") == 0) {
        pPerson = &student;
    } else if (strcmp(job, "professor") == 0) {
        pPerson = &professor;
    }

    if (!pPerson) {
        cerr << "Unknown role" << endl;
        return 1;
    }
    pPerson->Say();

    return 0;
}
