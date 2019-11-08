#include <iostream>
#define MAX_N 100
using namespace std;

char board00[MAX_N][MAX_N], board90[MAX_N][MAX_N];
int maxLen = 0;

bool isPalin(char board[MAX_N][MAX_N], const int r, int L, int R){

	while (L <= R){
		if (board[r][L] != board[r][R])
			return false;
		L++;
		R--;
	}

	return true;
}

int main(int argc, char** argv){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	for (int testcase = 1; testcase <= 10; testcase++){
		cin >> T;
		for (int r = 0; r < MAX_N; r++){
			for (int c = 0; c < MAX_N; c++){
				cin >> board00[r][c];
				board90[MAX_N - c - 1][r] = board00[r][c];
			}
		}

		maxLen = 0;
		int L, R;
		for (int r = 0; r < MAX_N; r++){
			for (int L = 0; L < MAX_N; L++){
				for (int R = L; R < MAX_N; R++){
					if (R - L + 1 <= maxLen)
						continue;
					else{
						if (isPalin(board00, r, L, R) || isPalin(board90, r, L, R)){
							maxLen = R - L + 1;
						}
					}
				}
			}
		}
		
		cout << "#" << T << " " << maxLen << "\n";
	}

	return 0;
}
