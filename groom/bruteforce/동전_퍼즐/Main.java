package groom.bruteforce.동전_퍼즐;

import java.io.*;
import java.util.*;

class Main {
    static char[][] map1;
    static char[][] map2;

    static int[] findIdx(int h, int w, char[][] map) {
        // 모양의 실제 크기 확인
        int startR = h - 1;
        int startC = w - 1;
        int endR = 0;
        int endC = 0;

        // original 크기 구하기
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 'O') {
                    if (i < startR) {
                        startR = i;
                    }

                    if (j < startC) {
                        startC = j;
                    }

                    if (i > endR) {
                        endR = i;
                    }

                    if (j > endC) {
                        endC = j;
                    }
                }
            }
        }

        if (startR == h - 1) {
            startR = 0;
        }

        if (startC == w - 1) {
            startC = 0;
        }

        if (endR == 0) {
            endR = h - 1;
        }

        if (endC == 0) {
            endC = w - 1;
        }

        int[] idx = new int[4];
        idx[0] = startR;
        idx[1] = startC;
        idx[2] = endR;
        idx[3] = endC;

        return idx;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int totalCnt = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        int h1 = Integer.parseInt(st.nextToken());
        int w1 = Integer.parseInt(st.nextToken());

        map1 = new char[h1][w1];

        for (int i = 0; i < h1; i++) {
            String line = br.readLine();

            for (int j = 0; j < w1; j++) {
                map1[i][j] = line.charAt(j);

                if (map1[i][j] == 'O') {
                    totalCnt++;
                }
            }
        }

        st = new StringTokenizer(br.readLine());

        int h2 = Integer.parseInt(st.nextToken());
        int w2 = Integer.parseInt(st.nextToken());

        map2 = new char[h2][w2];

        for (int i = 0; i < h2; i++) {
            String line = br.readLine();

            for (int j = 0; j < w2; j++) {
                map2[i][j] = line.charAt(j);
            }
        }

        int[] originalIdx = findIdx(h1, w1, map1);
        char[][] originalMap = new char[originalIdx[2] - originalIdx[0] + 1][originalIdx[3] - originalIdx[1] + 1];

        for (int i = 0; i < originalMap.length; i++) {
            for (int j = 0; j < originalMap[0].length; j++) {
                originalMap[i][j] = map1[originalIdx[0] + i][originalIdx[1] + j];
            }
        }

        int[] finalIdx = findIdx(h2, w2, map2);
        char[][] finalMap = new char[finalIdx[2] - finalIdx[0] + 1][finalIdx[3] - finalIdx[1] + 1];

        for (int i = 0; i < finalMap.length; i++) {
            for (int j = 0; j < finalMap[0].length; j++) {
                finalMap[i][j] = map2[finalIdx[0] + i][finalIdx[1] + j];
            }
        }

        int answer = 100;

        // original과 final을 움직이면서 비교하기
        int maxH = Math.max(originalMap.length, finalMap.length);
        int maxW = Math.max(originalMap[0].length, finalMap[0].length);

        char[][] compareMap = new char[maxH * 3][maxW * 3];

        for (int i = 0; i < maxH * 3; i++) {
            Arrays.fill(compareMap[i], '.');
        }

        // final을 가운데에 넣어놓기
        for (int i = 0; i < finalMap.length; i++) {
            for (int j = 0; j < finalMap[0].length; j++) {
                compareMap[maxH + i][maxW + j] = finalMap[i][j];
            }
        }

        // originalMap과 비교
        for (int i = 0; i <= compareMap.length - originalMap.length; i++) {
            for (int j = 0; j <= compareMap[0].length - originalMap[0].length; j++) {
                // 내부에서 비교
                int cnt = 0;

                for (int r = 0; r < originalMap.length; r++) {
                    for (int c = 0; c < originalMap[0].length; c++) {
                        if (originalMap[r][c] == 'O' && compareMap[i + r][j + c] == 'O') {
                            cnt++;
                        }
                    }
                }

                if (answer > totalCnt - cnt) {
                    answer = totalCnt - cnt;
                }
            }
        }

        System.out.println(answer);

    }
}