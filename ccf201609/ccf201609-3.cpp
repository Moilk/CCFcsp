#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

typedef struct T {
	int L;	// 生命值
	int A;	// 攻击值
} Doll;

Doll player[2][8];
int siz[2];
int N;

void insert(int who, int pos, int a, int l) {
	if (pos > 0) {
		siz[who]++;
		for (int i = siz[who]; i >pos; i--) {
			player[who][i] = player[who][i-1];
		}
		player[who][pos].A = a;
		player[who][pos].L = l;
	}
}

void remove(int who, int pos) {
	if (pos > 0) {
		for (int i = pos; i < siz[who]; i++) {
			player[who][i] = player[who][i + 1];
		}
		siz[who]--;
	}
}

void attack(int who, int r1, int r2) {
	player[who][r1].L -= player[1 - who][r2].A;
	player[1 - who][r2].L -= player[who][r1].A;
	if (player[who][r1].L <= 0) {
		remove(who, r1);
	}
	if (player[1 - who][r2].L <= 0) {
		remove(1 - who, r2);
	}
}

int main(void) {
	player[0][0].L = player[1][0].L = 30;
	player[0][0].A = player[1][0].A = 0;

	string cmd;
	string op;
	int r1, r2, ra, rl;
	int who = 0;

	cin >> N;
	getchar();
	while (N--) {
		getline(cin, cmd);
		stringstream in(cmd);
		in >> op;
		switch (op[0]) {
		case 's':
			in >> r1 >> ra >> rl;
			insert(who, r1, ra, rl);
			break;
		case 'a':
			in >> r1 >> r2;
			attack(who, r1, r2);
			break;
		case 'e':
			who = 1 - who;
			break;
		}
	}

	// 统计结果并输出
	if (player[0][0].L > 0 && player[1][0].L <= 0) {
		cout << 1 << endl;
	} else if (player[0][0].L <= 0 && player[1][0].L > 0) {
		cout << -1 << endl;
	} else {
		cout << 0 << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << player[i][0].L << endl;
		cout << siz[i] << ' ';
		for (int j = 1; j <= siz[i]; j++) {
			cout << player[i][j].L << ' ';
		}
		cout << endl;
	}

	return 0;
}
