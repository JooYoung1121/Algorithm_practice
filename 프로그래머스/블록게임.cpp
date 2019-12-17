#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 51

vector<vector<int>> map;
vector<int> block[201];

bool block_check(int x,int y) {
	for (int i = 0; i < x; i++) {
		if (map[i][y] != 0)return false;
	}
	return true;
}


bool solve(int x,int y,int w,int h) {
	int empty_bolck = 0;
	int erase_block = -1; // ������ �� Ȯ��

	for (int i = x; i < x + h; i++) {
		for (int j = y; j < y + w; j++) {
			if (map[i][j] == 0) { // 0�̸� 0 ���� �����̰� 0�� ������ 2 �ʰ��̸� �´� ������ �ƴϱ� ������ false
				if (!block_check(i, j))return false;

				empty_bolck++;
				if (empty_bolck > 2) return false;
			}
			else {
				if (erase_block != -1 && erase_block != map[i][j]) return false;
				erase_block = map[i][j];
			}
		}
	}

	for (int i = x; i < x + h; i++) {
		for (int j = y; j < y + w; j++) {
			map[i][j] = 0;
		}
	}

	return true;
}


int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size();
	map = board;

	int cnt = 1;

	while (cnt != 0) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// ���ΰ� 3 ���ΰ� 2�� ��� �˻�
				if (i <= n - 2 && j <= n - 3)
					cnt += solve(i,j,3,2);
				// ���Ұ� 2 ���ΰ� 3�� ��� �˻� 
				if (i <= n - 3 && j <= n - 2)
					cnt += solve(i,j,2,3);
			}
		}
		
		answer += cnt;
	}

	return answer;
}

int main() {
	int N;

	cin >> N;

	vector<vector<int>> board;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		board.push_back(tmp);
	}

	cout << solution(board);

	system("pause");
	return 0;
}