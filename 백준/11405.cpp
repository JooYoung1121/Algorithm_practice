#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;


#define INF 987654321
const int MAX = 100;
const int MAX_V = 2 * (MAX + 1); // �ִ� ���� ����
const int S = MAX_V - 2; // �ҽ� ����
const int E = MAX_V - 1; // ��ũ ����


int N, M;
int c[MAX_V][MAX_V] = { 0 }; // �� ���� �뷮
int d[MAX_V][MAX_V] = { 0 }; // �� ���� ���
int f[MAX_V][MAX_V] = { 0 }; // ����
vector<int> adj[MAX_V]; // ����Ʈ(�׷���)

int main() {

	cin >> N >> M;

	for (int i = MAX; i < MAX + N; i++) {
		cin >> c[i][E];
		adj[E].push_back(i);
		adj[i].push_back(E);
	}

	for (int i = 0; i < M; i++) {
		cin >> c[S][i];
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 0; i < M; i++) {
		for (int j = MAX; j < MAX + N; j++) {
			cin >> d[i][j];
			d[j][i] = -d[i][j];
			c[i][j] = INF;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	int result = 0;

	while (1) {
		int prev[MAX_V], dist[MAX_V];
		bool chk[MAX_V] = { false, }; // �ش� ������ ť�ȿ� �ִ���
		queue<int> q;

		memset(prev, -1, sizeof(prev));

		for (int i = 0; i < MAX_V; i++) {
			dist[i] = INF;
		}
		dist[S] = 0;
		chk[S] = true;
		q.push(S);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			chk[cur] = false;

			for (int next : adj[cur]) { // �ִ� ��θ� ã���鼭 ������ �־����
				if (c[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					prev[next] = cur;
					if (!chk[next]) {
						q.push(next);
						chk[next] = true;
					}
				}
			}
		}

		if (prev[E] == -1)break; // ���̻� ��ΰ� ������ Ż��

		int flow = INF;
		// ��λ󿡼� ���� residual�� ���� ������ ã�� �ִ� �긱 �� �ִ� flowã��
		for (int i = E; i != S; i=prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		// ��λ��� ��� ������ flow��ŭ�� ������ �긲 
		for (int i = E; i != S; i = prev[i]) {
			result += flow * d[prev[i]][i]; // �� ����� �� ���� ��븸ŭ ���� 
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

	}
	cout << result;

	system("pause");
	return 0;
}