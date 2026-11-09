#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
// 생성 다항식과 비트별 XOR 연산으로 4비트 나머지를 계산한다.
void remainder(const char* input, int length, const char* polynomial, char* result) {
    char work[17];
    for (int i=0; i<length; ++i) work[i]=input[i];
    work[length]='\0';
    for (int i=0; i+5<=length; ++i) {
        if (work[i]=='1')
            for (int j=0; j<5; ++j)
                work[i+j] = work[i+j] == polynomial[j] ? '0' : '1';
    }
    for (int i=0; i<4; ++i) result[i]=work[length-4+i];
    result[4]='\0';
}
void Sender(const char* input, const char* polynomial, char* frame) {
    char padded[17], fcs[5];
    for (int i=0; i<12; ++i) padded[i]=input[i];
    for (int i=12; i<16; ++i) padded[i]='0';
    padded[16]='\0';
    remainder(padded,16,polynomial,fcs);
    for (int i=0; i<12; ++i) frame[i]=input[i];
    for (int i=0; i<4; ++i) frame[12+i]=fcs[i];
    frame[16]='\0';
    cout << "Coded frame : " << frame << endl;
}
void Transmission_Channel(const char* frame, char* received) {
    for (int i=0; i<16; ++i)
        received[i] = rand()%20 == 0 ? (frame[i]=='0' ? '1' : '0') : frame[i];
    received[16]='\0';
}
void Receiver(const char* received, const char* polynomial) {
    char fcs[5], data[13];
    for (int i=0; i<12; ++i) data[i]=received[i];
    data[12]='\0';
    remainder(received,16,polynomial,fcs);
    cout << "Received frame : " << received << endl;
    cout << "Reconstructed data : " << data << endl;
    cout << (strcmp(fcs,"0000")==0 ? "No detected error" : "Receiver has detected error") << endl;
}
int main() {
    char input[50], frame[17], received[17], polynomial[]="11011";
    cout << "Data: "; cin.width(50);
    if (!(cin >> input) || strlen(input)!=12) { cerr << "Invalid data" << endl; return 1; }
    for (int i=0; i<12; ++i) if (input[i]!='0' && input[i]!='1') { cerr << "Invalid data" << endl; return 1; }
    srand(static_cast<unsigned int>(time(NULL)));
    Sender(input,polynomial,frame);
    Transmission_Channel(frame,received);
    Receiver(received,polynomial);
}
