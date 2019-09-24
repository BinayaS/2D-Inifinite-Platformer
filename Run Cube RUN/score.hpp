#ifndef SCORE
#define SCORE

class Score {
public:
  Score();
  ~Score();

  int getScore() { return score; }
  int addScore(int points) { this->score += points; }

private:
  int score;

};


#endif
