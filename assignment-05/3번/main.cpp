// 5차 과제 3번: 기존 프로그램의 오류를 점검한 수정본
#include "CSVLoader.h"
using namespace std;

int main()
{
	CSVLoader CSVLoader("CSVLoader_Data.txt");
	cout << "Rows: ";
	cout << CSVLoader.getRows() << endl;
	cout << "Cols: ";
	cout << CSVLoader.getCols()<<endl;
	cout << "Second Data: ";
	if (CSVLoader.getRows() > 0 && CSVLoader.getCols() > 1)
		cout << CSVLoader.getData()[0][1] << endl;
	else
		cout << "unavailable" << endl;
	cout << "print all data: " << endl;
	CSVLoader.print();

}
