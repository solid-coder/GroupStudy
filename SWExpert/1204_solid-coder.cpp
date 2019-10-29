#include <iostream>
using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for (int testcase = 1; testcase <= T; testcase++){
        int t;
        cin >> t;
        int score[101] = {0, }, input, freqScore = 0, freq = 0;
        for (int i = 0; i < 1000; i++){
            cin >> input;
            score[input]++;
            if (score[input] > freq){
                freq = score[input];
                freqScore = input;
            }
            else if (score[input] == freq && input > freqScore){
                freqScore = input;
            }
        }
        
		cout << "#" << t << " " <<freqScore << "\n";        
    }
    
    return 0;
}
