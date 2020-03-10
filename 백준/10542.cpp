#include <iostream>
#include <vector>
using namespace std;

#define MAX 500001

int Select[MAX];
int Point[MAX];

bool Mafia[MAX] = { false, }; // ���Ǿ��ΰ� Ȯ��
bool Chk[MAX] = { false, }; // �� ����� �ù����� ���Ǿ����� �Ǻ� �Ϸ����� Ȯ��

void Solve(int Idx,bool isMafia) {
	if (!Chk[Idx]) {
		Chk[Idx] = true;
		if (isMafia) // ���Ǿƶ�� ���Ѵٸ� �׻���� ���Ǿ� 
			Mafia[Idx] = true;
		Point[Select[Idx]]--;
		if (Point[Select[Idx]] == 0 || isMafia)
			Solve(Select[Idx], !isMafia);
	}
}

int main() {
	int N;

	cin >> N;

	int Cnt = 0;

	for (int i = 1; i <= N; i++) {
		int Number;
		cin >> Number;
		Select[i] = Number;
		Point[Number]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (Point[i] == 0) { // ������ �Ѹ� �ȴ��ߴٸ� �� ����� ���Ǿƶ�� ���� 
			Solve(i, true); // ���Ǿ��ΰŷ� ���� 
		}
	}

	for (int i = 1; i <= N; i++) {
		Solve(i, false); // ���δ� Ȯ���� �� �������� 
	}

	for (int i = 1; i <= N; i++) {
		if (Mafia[i])
			Cnt++;
	}

	cout << Cnt;

	system("pause");
	return 0;
}