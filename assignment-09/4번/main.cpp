// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <iostream>

using namespace std;

class Score {
  private:
    Score *m_pNext;
    Score *m_pPrev;
    double m_Avg;

  public:
    Score();
    ~Score();
    void SetAvg(double avg);
    void SetNext(Score *pNext);
    void SetPrev(Score *pPrev);
    double GetAvg();
    Score *GetNext();
    Score *GetPrev();
};

Score::Score() : m_pNext(nullptr), m_pPrev(nullptr), m_Avg(0) {}

Score::~Score() {}

void Score::SetAvg(double avg) { m_Avg = avg; }

void Score::SetNext(Score *pNext) { m_pNext = pNext; }

void Score::SetPrev(Score *pPrev) { m_pPrev = pPrev; }

double Score::GetAvg() { return m_Avg; }

Score *Score::GetNext() { return m_pNext; }

Score *Score::GetPrev() { return m_pPrev; }

class StudentScoreList {
  private:
    Score *m_pHead;
    Score *m_pTail;

  public:
    StudentScoreList();
    ~StudentScoreList();
    void Insert(Score *pScore);
    void PrintList(bool isAscending);
};

StudentScoreList::StudentScoreList() : m_pHead(nullptr), m_pTail(nullptr) {}

StudentScoreList::~StudentScoreList() {
    while (m_pHead != nullptr) {
        Score *pNext = m_pHead->GetNext();
        delete m_pHead;
        m_pHead = pNext;
    }
    m_pTail = nullptr;
}

void StudentScoreList::Insert(Score *pScore) {
    if (!pScore)
        return;

    if (m_pHead == nullptr) {

        m_pHead = pScore;
        m_pTail = pScore;
    }

    else {
        Score *pCurrent = m_pHead;

        while (pCurrent != nullptr && pCurrent->GetAvg() < pScore->GetAvg()) {

            pCurrent = pCurrent->GetNext();
        }

        if (pCurrent == m_pHead) {

            pScore->SetNext(m_pHead);
            m_pHead->SetPrev(pScore);

            m_pHead = pScore;
        }

        else if (pCurrent == nullptr) {

            m_pTail->SetNext(pScore);
            pScore->SetPrev(m_pTail);

            m_pTail = pScore;
        }

        else {

            pScore->SetPrev(pCurrent->GetPrev());
            pScore->SetNext(pCurrent);
            pCurrent->GetPrev()->SetNext(pScore);
            pCurrent->SetPrev(pScore);
        }
    }
}

void StudentScoreList::PrintList(bool isAscending) {
    if (isAscending) {

        Score *pCurrent = m_pHead;
        while (pCurrent != nullptr) {
            cout << pCurrent->GetAvg() << " ";
            pCurrent = pCurrent->GetNext();
        }
    } else {

        Score *pCurrent = m_pTail;
        while (pCurrent != nullptr) {
            cout << pCurrent->GetAvg() << " ";
            pCurrent = pCurrent->GetPrev();
        }
    }
    cout << endl;
}

int main() {
    StudentScoreList scoreList;

    double scores[][3] = {{85.0, 90.0, 92.0}, {90.0, 85.0, 80.0}, {78.0, 90.0, 95.0}};

    for (int i = 0; i < 3; i++) {
        double avgScore = (scores[i][0] + scores[i][1] + scores[i][2]) / 3.0;
        Score *score = new Score();
        score->SetAvg(avgScore);

        scoreList.Insert(score);
    }

    cout << "isAscending : true " << endl;
    scoreList.PrintList(true);
    cout << "isAscending : false " << endl;
    scoreList.PrintList(false);

    return 0;
}
