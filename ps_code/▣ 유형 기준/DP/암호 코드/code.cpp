#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	
	vector<ll> dp(s.size() + 10);
	int MOD = 1000000;

	dp[0] = 1;
	int N = s.size();
	s = " " + s;
	for (int i = 1; i <= N; ++i) {
		int x = s[i] - '0';
		// 1�ڸ� ��ȣ�� �ؼ��ϴ� ���
		if (1 <= x && x <= 9) {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}

		// ���̰� 1�� ��ȣ�� �ش��ϹǷ� ���̰� 2�� ��ȣ�� ����
		if (i == 1) continue;
		// ���ڸ��� 0�� ��ȣ�� ���̰� 2�� ��ȣ�� �� �� ����.
		if (s[i - 1] == '0') continue;
		
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
	
	printf("%lld", dp[N]);

	

}