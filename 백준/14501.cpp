#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 16

pair<int, int> Consulting[MAX];// Days, Cost

// dp �� Ǯ ��� dp[N] -> N�ϱ��� ��� ����
// dp[i] = max(Consulting[i] + dp[j],dp[i]) // N���� �������� N�� ������ ���� �� �ִ� ��� ��� �� 

/*
	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			if(i - j >= Consulting[j].first)
				dp[i] = max(Consulting[i].second + dp[j],dp[i]);
		}
	}

*/

int Answer = 0;

int N;

void solve(int Cost, int Idx) { // ����Ž��

	bool chk = true;

	for (int i = Idx; i <= N; i++) {
		int Next = i + Consulting[i].first;

		if (Next > N + 1)continue;
		
		chk = false;
		solve(Cost + Consulting[i].second, Next);
	}

	if (chk) // ���� �������� ���̻� ���� �� �� ���� ��� ������ �÷��� 
		Answer = max(Answer, Cost);
}

int main() {

	cin >> N;


	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		Consulting[i] = { a,b };
	}
	
	for (int i = 1; i <= N; i++) { // day
		int Next = i + Consulting[i].first;

		if (Next > N + 1) continue;

		solve(Consulting[i].second, Next);

	}

	cout << Answer;

	system("pause");
	return 0;
}