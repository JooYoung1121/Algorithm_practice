#include <iostream>
#include <set>
using namespace std;

#define MAX 4

set<string> result; // set�� �Ⱦ��� ��ü bool�迭 �ϳ� ����� ������� ������ �迭�� true���� false���� Ȯ���ϸ�
// �ߺ� üũ ���� bool visit[1000000] = false; ���涧���� trueüũ �̷��� �ð��� �ٰ� �ݹ� �ɵ� 
// �̰� 4*4���� ����غ� �ſ��� ���ڰ� Ŀ���ٸ� ���� set�� ����ϸ� �ȵȴ�. 

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int map[MAX][MAX];

void solve(int x, int y, int cnt, string num) {
	if (cnt == 7) {
		result.insert(num);
		return;
	}

	num += map[x][y] + '0';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)continue;

		solve(nx, ny, cnt + 1, num);

	}

}

int main() {
	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		result.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				solve(i, j,0,"");
			}
		}

		cout << "#" << test_case << " " << result.size() << endl;
	}

	return 0;
}