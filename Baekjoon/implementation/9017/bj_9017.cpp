#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  int t = 0;

  scanf("%d", &t);

  for(int i = 0; i < t; i++) {
    int n = 0;
    scanf("%d", &n);

    int input_tmp = 0;
    vector<int> input;
    map<int, int> teams;
    map<int, pair<int, vector<int> > > scores;

    for(int j = 0; j < n; j++) {
      scanf(" %d", &input_tmp);

      input.push_back(input_tmp);

      if(teams.find(input_tmp) == teams.end()) {
        teams.insert(make_pair(input_tmp, 1));
      } else {
        teams[input_tmp]++;
      }
    }

    int score = 1;

    for(int j = 0; j < n; j++) {
      if(teams[input[j]] == 6) {
        if(scores.find(input[j]) == scores.end()) {
          vector<int> tmp = {score};
          scores.insert(make_pair(input[j], make_pair(score, tmp)));
        } else {
          if(scores[input[j]].second.size() < 4) {
            scores[input[j]].first += score;
            scores[input[j]].second.push_back(score);
          } else {
            scores[input[j]].second.push_back(score);
          }
        }
        
        score++;
      }
    }

    int min_index = 0;
    int min = 0;

    for(auto iter = scores.begin(); iter != scores.end(); iter++) {
      if(iter == scores.begin()) {
        min_index = iter -> first;
        min = iter -> second.first;
        continue;
      }

      if(iter -> second.first == min) {
        if(scores[iter -> first].second[4] < scores[min_index].second[4]) {
          min_index = iter -> first;
          min = iter -> second.first;
        }
      } else if (iter -> second.first < min) {
        min_index = iter -> first;
        min = iter -> second.first;
      }
    }

    printf("%d\n", min_index);
  }

  return 0;
}