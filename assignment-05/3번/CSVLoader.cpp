#include "CSVLoader.h"
using namespace std;
CSVLoader::CSVLoader() : data(NULL), cols(0), rows(0) {}
CSVLoader::CSVLoader(const char* path) : data(NULL), cols(0), rows(0) { parse(path); }
CSVLoader::~CSVLoader() { clear(); }
void CSVLoader::clear() {
    for (int i=0; i<rows; ++i) delete[] data[i];
    delete[] data; data=NULL; rows=0; cols=0;
}
float** CSVLoader::getData() const { return data; }
int CSVLoader::getRows() const { return rows; }
int CSVLoader::getCols() const { return cols; }
// 원본 과제의 128칸 제한 안에서 한 줄을 숫자로 변환한다.
static bool parseRow(const char* line, float* values, int& count) {
    count=0; int i=0;
    while (line[i]!='\0') {
        while (line[i]==' ' || line[i]=='\t') ++i;
        int start=i, digits=0;
        if (line[i]=='+' || line[i]=='-') ++i;
        while (line[i]>='0' && line[i]<='9') { ++i; ++digits; }
        if (line[i]=='.') { ++i; while (line[i]>='0' && line[i]<='9') { ++i; ++digits; } }
        if (!digits || count >= 128) return false;
        if (line[i]=='e' || line[i]=='E') {
            ++i; if (line[i]=='+' || line[i]=='-') ++i;
            int expDigits=0;
            while (line[i]>='0' && line[i]<='9') { ++i; ++expDigits; }
            if (!expDigits) return false;
        }
        values[count++]=static_cast<float>(atof(line+start));
        while (line[i]==' ' || line[i]=='\t' || line[i]=='\r') ++i;
        if (line[i]=='\0') break;
        if (line[i++]!=',' || line[i]=='\0') return false;
    }
    return count>0;
}
void CSVLoader::parse(const char* path) {
    ifstream fin(path);
    if (!fin) { cerr << "Cannot open CSV file" << endl; return; }
    float temporary[128][128];
    char line[128]; int newRows=0, newCols=0;
    while (fin.getline(line,128)) {
        if (line[0]=='\0') continue;
        if (newRows==128) { cerr << "Too many rows" << endl; return; }
        int count=0;
        if (!parseRow(line,temporary[newRows],count) || (newRows>0 && count!=newCols)) {
            cerr << "Invalid CSV data" << endl; return;
        }
        if (newRows==0) newCols=count;
        ++newRows;
    }
    if (!fin.eof()) { cerr << "CSV read error" << endl; return; }
    float** next = newRows ? new float*[newRows] : NULL;
    for (int i=0; i<newRows; ++i) {
        next[i]=new float[newCols];
        for (int j=0; j<newCols; ++j) next[i][j]=temporary[i][j];
    }
    clear(); data=next; rows=newRows; cols=newCols;
}
void CSVLoader::print() {
    for (int i=0; i<rows; ++i) {
        cout << i+1 << ": ";
        for (int j=0; j<cols; ++j) cout << data[i][j] << "  ";
        cout << endl;
    }
}
