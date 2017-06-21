#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int n;
vector<pi> a;
pi ans[2];

bool cmp(pi a, pi b) {
	return a.second < b.second;
}

int dist(pi x, pi y) {
	return (y.second - x.second) * (y.second - x.second)
		+ (y.first - x.first) * (y.first - x.first);
}

int square(int x) {
	return x*x;
}

int closest_pair(int s, int e) {
	//���� ��� 3���� ���� ���� ��
	if (s == e - 2) {
		return min(min(dist(a[s], a[s + 1]), dist(a[s + 1], a[s + 2])), dist(a[s], a[s + 2]));
	}
	//���� ��� 2���� ���� ���� ��
	if (s == e - 1) {
		return dist(a[s], a[e]);
	}

	//��� �κ� 
	int mid = (s + e) / 2;
	//Divide & Conquer
	int rst = min(closest_pair(s, mid), closest_pair(mid + 1, e));

	//combine�� �� ���� �� ��� ���� ���� ���
	vector<pi> sub; //���� rst �ȿ� ��� ��� ������ vector
					//rst ���� ���̿� ��� ������ �ϴ� �ִ´�.
	for (int i = s; i <= e; i++) {
		if (abs(a[i].first - a[mid].first) < rst) {
			sub.push_back(a[i]);
		}
	}

	//����� ���鸸 y�� �������� �����Ѵ�.
	sort(sub.begin(), sub.end(), cmp);
	for (int i = 0; i<sub.size(); i++) {
		for (int j = i + 1; j < sub.size(); ++j) {
			//�̹� ������ �Ѿ�� ������.
			if (square((sub[j].second - sub[i].second)) >= rst) {
				break;
			}
			//�ּڰ� ����
			rst = min(rst, dist(sub[j], sub[i]));
		}
	}
	return rst;
}

int main() {
	scanf("%d", &n);
	a = vector<pi>(n);

	for (int i = 0; i<n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	//x�� �������� ���� �����Ѵ�.
	sort(a.begin(), a.end());
	printf("%d", closest_pair(0, n - 1));
}