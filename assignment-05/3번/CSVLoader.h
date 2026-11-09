#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
class CSVLoader {
public:
    static constexpr unsigned int MAX_BUFFER_SIZE = 128;
    CSVLoader();
    explicit CSVLoader(const char* path);
    ~CSVLoader();
    CSVLoader(const CSVLoader&) = delete;
    CSVLoader& operator=(const CSVLoader&) = delete;
    float** getData() const;
    int getRows() const;
    int getCols() const;
    void parse(const char* path);
    void print();
private:
    float** data;
    int cols;
    int rows;
    void clear();
};
