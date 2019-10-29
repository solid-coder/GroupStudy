package study.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class bky373 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			int cnt = Integer.parseInt(br.readLine());
			String[] line = br.readLine().split(" ");
			LinkedList<Integer> match = new LinkedList<Integer>();
			for (int i = 0; i < Math.pow(2, cnt); i++)
				match.offer(Integer.parseInt(line[i]));
			int score = 0, k = 0;
			while (match.size() != 1) {
				score += Math.abs(match.get(k) - match.get(k + 1));
				if (match.get(k) < match.get(k + 1)) {
					match.remove(k);
					k = k == match.size() - 1 ? 0 : ++k;
				} else {
					match.remove(k + 1);
					k = k == match.size() - 1 ? 0 : ++k;
				}
			}
			System.out.printf("#%d %d\n", tc+1, score);
		}
	}
}
