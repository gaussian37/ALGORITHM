#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

vi A, tree; 
void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = A[start];
	}
	else {
		init(2 * node, start, (start + end) / 2);
		init(2 * node + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int node, int start, int end, int i, int j) {
	if (j < start || end < i) return -1;
	if (i <= start && end <= j) return tree[node];

	int m1 = query(2 * node, start, (start + end) / 2, i, j);
	int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	A = tree = vi(N * 4);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}	
	
	vector<pi> range(M), ans(M);

	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &range[i].first, &range[i].second);
	}

	//Minimum
	init(1, 1, N);
	for (int i = 0; i < M; ++i) {
		ans[i].first = query(1, 1, N, range[i].first, range[i].second);
	}

	//Maximum
	for (int i = 1; i <= N; ++i) {
		A[i] = -A[i];
	}
	tree = vi(N * 4);
	init(1, 1, N);
	for (int i = 0; i < M; ++i) {
		ans[i].second = -query(1, 1, N, range[i].first, range[i].second);
	}

	for (pi a : ans) {
		printf("%d %d\n", a.first, a.second);
	}
}