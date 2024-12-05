#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {

  int p = 0;
  int m = 0;

  cin >> p >> m;

  vector<pair< map<string, int>, pair<int, int> > > rooms;

  for(int i = 0; i < p; i++) {
    int level = 0;
    string name = "";
    bool isInserted = false;

    cin >> level >> name;

    for(int i = 0; i < rooms.size(); i++) {
      if(rooms[i].first.size() == m) {
        continue;
      }

      if(level >= rooms[i].second.first && level <= rooms[i].second.second) {
        rooms[i].first.insert(make_pair(name, level));
        isInserted = true;
        break;
      }
    }

    if(!isInserted) {
      pair<int, int> range = make_pair(level - 10, level + 10);
      map<string, int> player;
      player.insert(make_pair(name, level));

      rooms.push_back(make_pair(player, range));
    }
  }

  for(int i = 0; i < rooms.size(); i++) {
    if(rooms[i].first.size() == m) {
      cout << "Started!\n";
    } else {
      cout << "Waiting!\n";
    }

    for(auto iter = rooms[i].first.begin(); iter != rooms[i].first.end(); iter++) {
      cout << iter->second << " " << iter->first << "\n";
    }
  }

  return 0;
}