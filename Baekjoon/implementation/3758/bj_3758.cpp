#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  int t = 0;

  scanf("%d", &t);

  for(int i = 0; i < t; i++) {
    int n = 0;
    int k = 0;
    int id = 0;
    int m = 0;

    scanf(" %d %d %d %d", &n, &k, &id, &m);

    map<int, pair<map<int, int>, pair<int, pair<int, int> > > > score_board;

    for(int j = 0; j < m; j++) {
      int team_id = 0;
      int prob_num = 0;
      int score = 0;

      scanf(" %d %d %d", &team_id, &prob_num, &score);

      if(score_board.find(team_id) == score_board.end()) {
        map<int, int> scores;
        scores.insert(make_pair(prob_num, score));
        score_board.insert(make_pair(team_id, make_pair(scores, make_pair(score, make_pair(1, j)))));
      } else {
        map<int, int> scores = score_board[team_id].first;
        int last_cnt = score_board[team_id].second.second.first;
        int total = score_board[team_id].second.first;

        if(scores.find(prob_num) == scores.end()) {
          scores.insert(make_pair(prob_num, score));
          total = total + score;
        } else {
          if(scores[prob_num] < score) {
            total = total - scores[prob_num];
            scores[prob_num] = score;
            total = total + score;
          }
        }

        score_board[team_id] = make_pair(scores, make_pair(total, make_pair(last_cnt + 1, j)));
      }
    }

    int my_score = score_board[id].second.first;
    int my_cnt = score_board[id].second.second.first;
    int my_last = score_board[id].second.second.second;
    int rank = 1;

    for(auto i = score_board.begin(); i != score_board.end(); i++) {
      if(i->first != id) {
        if(i->second.second.first == my_score) {
          if(i->second.second.second.first == my_cnt) {
            if(i->second.second.second.second < my_last) {
              rank++;
            }
          } else if(i->second.second.second.first < my_cnt) {
            rank++;
          }
        } else if(i->second.second.first > my_score) {
          rank++;
        }
      }
    }

    printf("%d\n", rank);

  }

  return 0;
}