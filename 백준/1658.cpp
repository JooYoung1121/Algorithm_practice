#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

int pig[MAX];
vector<int> custom[101]; // ù��° ���� ������ �ִ� ���� ���� �� �������� � �������� �������� �� ���� ������

// ��Ʈ��ũ �÷ο� ������ �����ϰ� Ǯ��� 

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int M, N;

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		cin >> pig[i];
	}
	
	for (int i = 1; i <= N; i++) {
		int a;

		cin >> a;

		custom[i].push_back(a);
		for (int j = 0; j < a; j++) {
			int k;
			cin >> k;
			custom[i].push_back(k);
		}

		int b;

		cin >> b;

		custom[i].push_back(b);
	}





	return 0;

}