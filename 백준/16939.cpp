#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

// �޸�, �ظ�, �ո�, ���ʸ�, �����ʸ�, ���� ������� �Է� 

#define MAX 25

vector<int> cube[7];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;
	int index = 1;
	for (int i = 0; i < 24; i++) {
		int n;
		cin >> n;
		cube[index].push_back(n);
		count++;
		if (count == 4) {
			count = 0;
			index++;
		}
	}

	// �� ���ϴ� �Լ��� ������ �Ұ� ���⵵ �ϰ� 


	


	system("pause");
	return 0;
}