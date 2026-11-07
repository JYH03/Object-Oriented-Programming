// 01반_02반_2022202078_조영훈 2-1주차 4번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int i=0,cnt=0;
	char data[300] = {}, alphabet[2], blank[2] = {" "};		//data: binary 파일의 값을 입력받을 변수, alphabet: 변환된 알파벳을 저장할 변수, blank: 공백출력용 변수
	ifstream fin;								//읽기용 fin스트림
	fin.open("binary.txt");						//fin스트림에 binary 파일 연결
	ofstream fout;								//쓰기용 fout스트림
	fout.open("alphabet.txt");					//fout스트림에 alphabet파일 연결
	if (!fin)
	{
		cout << "no" << endl;					//파일이 열리지 않았다면 no 출력
	}
	while (!fin.eof())							//파일의 끝(end of file)이 아닌 동안
	{
		fin.getline(data, 300);					//파일 내 값을 입력 받아 data에 저장
	}
	while (data[i] != '\0')						//data가 \0이 아닌 동안
	{
		if (data[i] == '0'&&cnt<25)				//0의 개수로 알파벳 판별, z의 0개수가 25개라 25개보다 작을 때 까지 
		{
			cnt++;								//0의 개수 카운트
		}
		else if (data[i] == ' ')				//공백이면
		{
			fout.write(blank,1);				//공백입력
		}
		if(data[i]=='1'||cnt==25)
		{
			alphabet[0] = char('a' + cnt);	//a에서 0의 개수 만큼 더하면 표의 알파벳이 나옴 'a'+cnt 만큼의 정수가 상징하는 문자를 저장
			fout.write(alphabet,1);			//파일에 알파벳 입력
			cnt = 0;
		}
		i++;								//배열을 진행할 변수 i
	}
	fin.close();						//읽기용 fin스트림 닫기
	fout.close();						//쓰기용 fout스트림 닫기
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
