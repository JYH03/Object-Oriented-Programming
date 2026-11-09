// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "myMusic.h"
#include <iostream>
using namespace std;
int main() {
    myMusic music;
    char title[256], singer[256], album[256], comma;
    int year, track;
    cout << "Input the music information: ";
    if (!cin.getline(title, 256, ',') || !cin.getline(singer, 256, ',') ||
        !cin.getline(album, 256, ',') || !(cin >> year >> comma >> track) || comma != ',') {
        cerr << "Invalid music information\n";
        return 1;
    }
    music.setTitle(title);
    music.setSinger(singer);
    music.setAlbum(album);
    music.setYear(year);
    music.setTrackNo(track);
    cout << "Title: " << music.getTitle() << "\nSinger: " << music.getSinger()
         << "\nAlbum: " << music.getAlbum() << "\nYear: " << music.getYear()
         << "\nTrack No.: " << music.getTrackNo() << '\n';
}
