#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int kbs1_idx = -1;
  int kbs2_idx = -1;
  string answer = "";

  scanf("%d\n", &n);

  string channels[100] = { "", };

  for(int i = 0; i < n; i++) {
    getline(cin, channels[i]);

    if(channels[i] == "KBS1") {
      kbs1_idx = i;
    }

    if(channels[i] == "KBS2") {
      kbs2_idx = i;
    }
  }

  answer.insert(0, kbs1_idx, '1');
  answer.insert(answer.length(), kbs1_idx, '4');

  if(kbs1_idx > kbs2_idx) {
    kbs2_idx = kbs2_idx + 1;
  }

  answer.insert(answer.length(), kbs2_idx, '1');
  answer.insert(answer.length(), kbs2_idx - 1, '4');

  printf("%s", answer.c_str());

  return 0;
}