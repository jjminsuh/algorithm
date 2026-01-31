package groom.data_structures.블록_게임;

import java.io.*;
import java.util.*;

class Block {
    int x;
    int y;
    int score;

    Block(int x, int y, int score) {
        this.x = x;
        this.y = y;
        this.score = score;
    }
}

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String d = br.readLine();
        StringTokenizer scoreTokens = new StringTokenizer(br.readLine());

        Stack<Block> blocks = new Stack<>();
        HashMap<List<Integer>, Boolean> map = new HashMap<>();

        blocks.push(new Block(0, 0, 1));
        map.put(Arrays.asList(0, 0), true);

        int[] dirX = { -1, 1, 0, 0 };
        int[] dirY = { 0, 0, 1, -1 };

        for (int i = 0; i < n; i++) {
            int dir = 0;
            int score = Integer.parseInt(scoreTokens.nextToken());

            if (d.charAt(i) == 'L') {
                dir = 0;
            } else if (d.charAt(i) == 'R') {
                dir = 1;
            } else if (d.charAt(i) == 'U') {
                dir = 2;
            } else if (d.charAt(i) == 'D') {
                dir = 3;
            }

            Block top = blocks.peek();

            int targetX = top.x + dirX[dir];
            int targetY = top.y + dirY[dir];
            List<Integer> target = Arrays.asList(targetX, targetY);

            if (map.containsKey(target)) {
                // 이미 블록이 있는 경우
                if (map.get(target)) {
                    while (!blocks.isEmpty()) {
                        Block toCheck = blocks.peek();
                        blocks.pop();

                        map.put(Arrays.asList(toCheck.x, toCheck.y), false);

                        if (toCheck.x == targetX && toCheck.y == targetY) {
                            break;
                        }
                    }
                }
            }

            map.put(target, true);
            blocks.push(new Block(targetX, targetY, score));
        }

        int answer = 0;

        while (!blocks.isEmpty()) {
            Block top = blocks.peek();
            answer = answer + top.score;

            blocks.pop();
        }

        System.out.println(answer);
    }
}
