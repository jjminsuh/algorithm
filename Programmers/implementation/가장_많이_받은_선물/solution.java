package Programmers.implementation.가장_많이_받은_선물;

import java.util.*;

class Solution {
  public int solution(String[] friends, String[] gifts) {
    int answer = 0;

    HashMap<String, Integer> points = new HashMap<String, Integer>();
    HashMap<List<String>, Integer> fromTo = new HashMap<List<String>, Integer>();

    for (int i = 0; i < gifts.length; i++) {
      String[] names = gifts[i].split(" ");

      if (points.containsKey(names[0])) {
        points.replace(names[0], points.get(names[0]) + 1);
      } else {
        points.put(names[0], 1);
      }

      if (points.containsKey(names[1])) {
        points.replace(names[1], points.get(names[1]) - 1);
      } else {
        points.put(names[1], -1);
      }

      List<String> namesList = Arrays.asList(names);

      if (fromTo.containsKey(namesList)) {
        fromTo.replace(namesList, fromTo.get(namesList) + 1);
      } else {
        fromTo.put(namesList, 1);
      }
    }

    for (int i = 0; i < friends.length; i++) {
      int cnt = 0;

      for (int j = 0; j < friends.length; j++) {
        if (i == j) {
          continue;
        }

        List<String> aTob = Arrays.asList(friends[i], friends[j]);
        List<String> bToa = Arrays.asList(friends[j], friends[i]);

        int giveCnt = 0;
        int getCnt = 0;

        if (fromTo.containsKey(aTob)) {
          giveCnt = fromTo.get(aTob);
        }

        if (fromTo.containsKey(bToa)) {
          getCnt = fromTo.get(bToa);
        }

        if (giveCnt > getCnt) {
          cnt++;
          continue;
        } else if (giveCnt < getCnt) {
          continue;
        }

        int aPoint = 0;
        int bPoint = 0;

        if (points.containsKey(friends[i])) {
          aPoint = points.get(friends[i]);
        }

        if (points.containsKey(friends[j])) {
          bPoint = points.get(friends[j]);
        }

        if (aPoint > bPoint) {
          cnt++;
        }
      }

      if (answer < cnt) {
        answer = cnt;
      }
    }

    return answer;
  }
}
