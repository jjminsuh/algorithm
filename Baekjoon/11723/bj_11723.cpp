#include <iostream>
#include <set>

using namespace std;

int main() {

  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  long long m = 0;
  set<int> s;

  cin >> m;

  string operation = "";
  int num = 0;

  for(long long i = 0; i < m; i++) {
    cin >> operation;

    if(operation == "add") {
      cin >> num;
      s.insert(num);
    } else if(operation == "remove") {
      cin >> num;
      s.erase(num);
    } else if(operation == "check") {
      cin >> num;
      if(s.find(num) != s.end()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else if(operation == "toggle") {
      cin >> num;
      if(s.find(num) != s.end()) {
        s.erase(num);
      } else {
        s.insert(num);
      }
    } else if(operation == "all") {
      for(int i = 1; i <= 20; i++) {
        s.insert(i);
      }
    } else if(operation == "empty") {
      s.clear();
    }
  }

  return 0;
}