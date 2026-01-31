package groom.two_pointer.개미_집합의_지름;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] ants = new int[n];

        for (int i = 0; i < n; i++) {
            ants[i] = Integer.parseInt(st.nextToken());
        }

        // 개미 정렬
        Arrays.sort(ants);

        int answer = n;
        int start = 0;
        int end = 0;

        while (start < n) {
            while (end < n) {
                if (ants[end] - ants[start] > d) {
                    if (n - (end - start) < answer) {
                        answer = n - (end - start);
                    }

                    end--;
                    break;
                }

                end++;
            }

            if (end == n) {
                if (n - (end - start) < answer) {
                    answer = n - (end - start);
                }

                end--;
            }

            start++;
            end++;
        }

        System.out.println(answer);
    }
}
