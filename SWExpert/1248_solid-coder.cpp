#include <iostream>
#define MAX_V 10000
using namespace std;

struct VERTEX{
	int depth;
	int parents[14];
	int child[2];
}V[MAX_V+1];

void init(){
	for (int i = 0; i <= MAX_V; i++){
		V[i].depth = 0;
		V[i].child[0] = 0;
		V[i].child[1] = 0;
		for (int k = 0; k < 14; k++)
			V[i].parents[k] = 0;
	}
}

void setDepth(const int i){
	if (V[i].child[0] != 0){
		V[V[i].child[0]].depth = V[i].depth + 1;
		setDepth(V[i].child[0]);
	}
	if (V[i].child[1] != 0){
		V[V[i].child[1]].depth = V[i].depth + 1;
		setDepth(V[i].child[1]);
	}
}

void setParents(const int i){
	if (V[i].parents[0] != 0){
		int n = 1, m = V[i].parents[0];

		while (m != 0){
			V[i].parents[n] = V[m].parents[n - 1];
			m = V[m].parents[n - 1];
			n++;
		}
	}
	
	if (V[i].child[0] != 0)
		setParents(V[i].child[0]);
	if (V[i].child[1] != 0)
		setParents(V[i].child[1]);
}

int findLCA(int v1, int v2){
	// find same level
	if (V[v1].depth > V[v2].depth){
		while ((V[v1].depth != V[v2].depth)){
			for (int k = 0; k < 14; k++){
				if (V[V[v1].parents[k]].depth < V[v2].depth){
					v1 = V[v1].parents[k - 1];
					break;
				}
			}
		}
	}
	else if (V[v1].depth < V[v2].depth){
		while ((V[v1].depth != V[v2].depth)){
			for (int k = 0; k < 14; k++){
				if (V[V[v2].parents[k]].depth < V[v1].depth){
					v2 = V[v2].parents[k - 1];
					break;
				}
			}
		}
	}

	while (V[v1].parents[0] != V[v2].parents[0]){
		for (int k = 0; k < 14; k++){
			if (V[v1].parents[k] == V[v2].parents[k]){
				v1 = V[v1].parents[k - 1];
				v2 = V[v2].parents[k - 1];
				break;
			}
		}
	}

	return V[v1].parents[0];
}

int cntSubtree(int i){
	int ans = 1;
	if (V[i].child[0] != 0)
		ans += cntSubtree(V[i].child[0]);
	if (V[i].child[1] != 0)
		ans += cntSubtree(V[i].child[1]);
	return ans;
}

int main(int argc, char** argv){
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, numV, numE, V1, V2;
	cin >> T;

	for (int testcase = 1; testcase <= T; testcase++){
		init();
		cin >> numV >> numE >> V1 >> V2;

		int e1, e2;
		for (int e = 0; e < numE; e++){
			cin >> e1 >> e2;
			V[e2].parents[0] = e1;
			if (V[e1].child[0] == 0)
				V[e1].child[0] = e2;
			else
				V[e1].child[1] = e2;
		}

		V[1].depth = 1;
		setDepth(1);
		setParents(1);

		int LCA = findLCA(V1, V2);

		cout << "#" << testcase << " " << LCA << " " << cntSubtree(LCA) << "\n";
	}


	return 0;
}
