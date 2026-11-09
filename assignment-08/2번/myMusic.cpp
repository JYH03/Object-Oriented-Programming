// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "myMusic.h"
static void copyText(char *dst, const char *src) {
    int i = 0;
    for (; i < 255 && src[i]; ++i)
        dst[i] = src[i];
    dst[i] = '\0';
}
myMusic::myMusic() : m_title{}, m_singer{}, m_album{}, m_track_no(0), m_year(0) {}
myMusic::~myMusic() = default;
void myMusic::setTitle(const char *p) { copyText(m_title, p); }
void myMusic::setSinger(const char *p) { copyText(m_singer, p); }
void myMusic::setAlbum(const char *p) { copyText(m_album, p); }
void myMusic::setYear(int y) { m_year = y; }
void myMusic::setTrackNo(int n) { m_track_no = n; }
const char *myMusic::getTitle() const { return m_title; }
const char *myMusic::getSinger() const { return m_singer; }
const char *myMusic::getAlbum() const { return m_album; }
int myMusic::getYear() const { return m_year; }
int myMusic::getTrackNo() const { return m_track_no; }
