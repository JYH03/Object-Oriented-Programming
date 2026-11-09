// 4차 과제 4번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int i=0,cnt=0;
	char data[300] = {}, alphabet[2], blank[2] = {" "};		
	ifstream fin;								
	fin.open("binary.txt");						
	ofstream fout;								
	fout.open("alphabet.txt");					
	if (!fin || !fout) { cerr << "File open error" << endl; return 1; }
	
	while (fin.getline(data, 300))
	{
		i = 0;

	while (data[i] != '\0')						
	{
		if (data[i] == '0'&&cnt<25)				
		{
			cnt++;								
		}
		else if (data[i] == ' ')				
		{
			fout.write(blank,1);				
		}
		if(data[i]=='1'||cnt==25)
		{
			alphabet[0] = char('a' + cnt);	
			fout.write(alphabet,1);			
			cnt = 0;
		}
		i++;								
	}
	}
	fin.close();						
	fout.close();						
}
