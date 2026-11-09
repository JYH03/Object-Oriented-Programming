# 객체지향 프로그래밍 및 설계 과제

객체지향 프로그래밍 및 설계 수업에서 작성한 C++ 과제를 차수별로 정리하였다.

## 과제 목록

| 차수 | 수업 과제 | 주요 내용 | 상세 설명 |
|---|---|---|---|
| 1차 | 1-1 | 시어핀스키 삼각형, 이차방정식, 최대공약수·최소공배수, 역행렬 | [1차 과제](./assignment-01/README.md) |
| 2차 | 1-2 | 숫자 빈도, 오류 검출, 와일드카드 검색, 이미지 처리 | [2차 과제](./assignment-02/README.md) |
| 3차 | 1-3 | 좌표 변환, 회로 계산, 진법 변환, 정렬 | [3차 과제](./assignment-03/README.md) |
| 4차 | 2-1 | 스택, 미로 탐색, 문자열 함수 구현, 이진 코드 해독 | [4차 과제](./assignment-04/README.md) |
| 5차 | 2-2 | 중첩 배열 조회, 생성자와 소멸자, CSVLoader, 시계 클래스 | [5차 과제](./assignment-05/README.md) |
| 6차 | 2-3 | 직원 정보 관리, 학생 관리, 문자열 및 행렬 클래스 | [6차 과제](./assignment-06/README.md) |
| 7차 | 3-1 | 연결 리스트 병합, 토큰 분리, 큐와 스택 | [7차 과제](./assignment-07/README.md) |
| 8차 | 3-2 | 리스트 검색, 음악 정보, 다항식 | [8차 과제](./assignment-08/README.md) |
| 9차 | 3-3 | 상속과 다형성, 행렬 연산자, 양방향 리스트 | [9차 과제](./assignment-09/README.md) |

## 디렉터리 구조

```text
.
├── README.md
├── assignment-01/
│   ├── README.md
│   ├── 1번/main.cpp
│   ├── 2번/main.cpp
│   ├── 3번/main.cpp
│   └── 4번/main.cpp
├── assignment-02/
├── assignment-03/
├── assignment-04/
├── assignment-05/
├── assignment-06/
├── assignment-07/
├── assignment-08/
└── assignment-09/
```

각 차수에는 문제별 폴더가 있다. 일부 문제에는 `main.cpp` 외에 헤더, 구현 파일 또는 입력 데이터가 함께 있다.

## 빌드 및 실행

각 문제는 별도의 프로그램이므로 문제별로 빌드하고 실행한다. 하나의 문제에서 여러 `.cpp` 파일을 사용하는 경우 해당 파일을 함께 빌드해야 한다.

파일을 읽는 문제는 실행 시 작업 디렉터리에 필요한 입력 파일이 있어야 한다. 5차 3번의 `CSVLoader_Data.txt`가 그 예이다. 

## 수정본 사용

각 문제의 `main.cpp`와 같은 문제의 보조 `.cpp` 파일을 함께 빌드한다. 6차 1번은 최대 10명의 직원을 배열로 관리하며 `insert`, `find`, `change`, `print`, `exit` 명령을 처리한다. 해당 폴더에서 `main.cpp`와 `Empoloyee.cpp`를 함께 컴파일한다.

## 라이브러리 사용

컨테이너와 알고리즘 유틸리티 사용 제한하고 작성하였다. `swap`도 직접 값 교환으로 바꾸었다. `iostream`, `cmath`, `fstream` 등 원래 사용하던 입출력·수학 헤더는 유지한다.
