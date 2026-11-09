// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
char *duplicate(const char *text) {
    char *p = new char[strlen(text) + 1];
    strcpy(p, text);
    return p;
}
int compare(const char *a, const char *b) {
    while (*a && *b) {
        unsigned char x = *a++, y = *b++;
        if (x >= 'A' && x <= 'Z')
            x += 32;
        if (y >= 'A' && y <= 'Z')
            y += 32;
        if (x != y)
            return x < y ? -1 : 1;
    }
    return *a ? 1 : (*b ? -1 : 0);
}
struct SongNode {
    char *song_name;
    SongNode *next_song;
    explicit SongNode(const char *s) : song_name(duplicate(s)), next_song(nullptr) {}
    ~SongNode() { delete[] song_name; }
};
struct ArtistNode {
    char *artist_name;
    SongNode *song_head;
    ArtistNode *next_artist;
    explicit ArtistNode(const char *s)
        : artist_name(duplicate(s)), song_head(nullptr), next_artist(nullptr) {}
    ~ArtistNode() {
        while (song_head) {
            SongNode *n = song_head->next_song;
            delete song_head;
            song_head = n;
        }
        delete[] artist_name;
    }
};
class MyMusic {
    ArtistNode *artist_head;
    ArtistNode *artist_tail;
    MyMusic(const MyMusic &) = delete;
    MyMusic &operator=(const MyMusic &) = delete;
    void insertion(ArtistNode *artist, const char *song) {
        SongNode **at = &artist->song_head;
        while (*at && compare((*at)->song_name, song) <= 0)
            at = &(*at)->next_song;
        SongNode *p = new SongNode(song);
        p->next_song = *at;
        *at = p;
    }

  public:
    MyMusic() : artist_head(nullptr), artist_tail(nullptr) {}
    ~MyMusic() {
        if (artist_tail)
            artist_tail->next_artist = nullptr;
        while (artist_head) {
            ArtistNode *next = artist_head->next_artist;
            delete artist_head;
            artist_head = next;
        }
    }
    void adding(const char *artist, const char *song) {
        ArtistNode *p = artist_head;
        if (p)
            do {
                if (strcmp(p->artist_name, artist) == 0) {
                    insertion(p, song);
                    return;
                }
                p = p->next_artist;
            } while (p != artist_head);
        p = new ArtistNode(artist);
        if (!artist_head)
            artist_head = p;
        else
            artist_tail->next_artist = p;
        artist_tail = p;
        p->next_artist = artist_head;
        insertion(p, song);
    }
    void reading(const char *filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Not found the file\n";
            return;
        }
        char line[4096];
        while (file.getline(line, sizeof(line))) {
            char *slash = strchr(line, '/');
            if (!slash)
                continue;
            *slash = '\0';
            char *artist = line;
            char *song = strchr(slash + 1, '\t');
            song = song ? song + 1 : slash + 1;
            while (*song == ' ' || *song == '\t')
                ++song;
            int n = static_cast<int>(strlen(artist));
            while (n > 0 && (artist[n - 1] == ' ' || artist[n - 1] == '\t'))
                artist[--n] = '\0';
            n = static_cast<int>(strlen(song));
            if (n && song[n - 1] == '\r')
                song[n - 1] = '\0';
            if (*artist && *song && compare(artist, "Artist") != 0)
                adding(artist, song);
        }
        if (!file.eof())
            cerr << "Music line exceeds buffer\n";
    }
    void printMusic() const {
        if (!artist_head) {
            cout << "The list is empty.\n";
            return;
        }
        ArtistNode *p = artist_head;
        do {
            cout << "Artist: " << p->artist_name << '\n';
            for (SongNode *s = p->song_head; s; s = s->next_song)
                cout << "Song: " << s->song_name << '\n';
            cout << '\n';
            p = p->next_artist;
        } while (p != artist_head);
    }
};
int main() {
    MyMusic music;
    music.reading("Music_Info.txt");
    music.printMusic();
}
