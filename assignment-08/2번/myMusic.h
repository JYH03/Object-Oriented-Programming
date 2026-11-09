// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#pragma once
class myMusic {
    char m_title[256], m_singer[256], m_album[256];
    int m_track_no, m_year;

  public:
    myMusic();
    ~myMusic();
    void setTitle(const char *);
    void setSinger(const char *);
    void setAlbum(const char *);
    void setYear(int);
    void setTrackNo(int);
    const char *getTitle() const;
    const char *getSinger() const;
    const char *getAlbum() const;
    int getYear() const;
    int getTrackNo() const;
};
