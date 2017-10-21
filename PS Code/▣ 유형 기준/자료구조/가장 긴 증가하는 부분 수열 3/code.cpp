#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef vector<int> vi;

int MAX = 1000000;

int query(vi& tree, int node, int start, int end, int i, int j) {
	if (end < i || j < start) {
		return 0;
	}
	if (i <= start && end <= j) {
		return tree[node];
	}
	int m1 = query(tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	return max(m1, m2);
}

void update(vi&tree, int node, int start, int end, int i, int val) {
	if (i > end || i < start) {
		return;
	}
	tree[node] = max(tree[node], val);
	if (start != end) {
		update(tree, 2 * node, start, (start + end) / 2, i, val);
		update(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, val);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vi A(N), B(N);	
	for (int i = 0; i<N; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	map<int, int> d;
	for (int i = 0; i<B.size(); i++) {
		d[B[i]] = i + 1;
	}
	for (int i = 0; i<N; i++) {
		A[i] = d[A[i]];
	}

	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	int ans = 0;
	for (int i = 0; i<N; i++) {
		int num = A[i];
		int cur = query(tree, 1, 1, MAX, 1, num - 1);
		if (ans < cur + 1) {
			ans = cur + 1;
		}
		update(tree, 1, 1, MAX, num, cur + 1);
	}
	printf("%d\n", ans);
	return 0;
}
