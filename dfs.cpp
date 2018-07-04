#include <iostream>
#include <string>

using namespace std;

int needleX[4] = { -1,0,1,0 };
int needleY[4] = { 0,1,0,-1 };
bool search(int** table,int x, int y, int goalx, int goaly, int color) {
	if (x == goalx&&y == goaly)return true;
	if (table[y][x] == 0)return false;
	if (table[goaly][goalx] == 0)return false;
	table[y][x] = 0;
	//cout << x << " " << y << endl;
	for (int i =0; i < 4; i++) {
		int nextx = x + needleX[i];
		int nexty = y + needleY[i];
		if (table[nexty][nextx]==color) {
			bool flg = search(table, nextx, nexty, goalx, goaly, color);
			if (flg) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int w = -1, h = -1, startx, starty, goalx, goaly, n,c,d,x,y;

	while (1) {
		//����
		cin >> w >> h;

		//�I������
		if (w == 0 || h == 0) {
			return 0;
		}

		cin >> startx >> starty >> goalx >> goaly >> n;

		//�������m��
		int** table = new int*[h];
		for (int i = 0; i < h; i++) {
			table[i] = new int[w];
			for (int j = 0; j < w; j++) {
				table[i][j] = 0;
			}
		}

		//�e�[�u������
		for (int i = 0; i < n; i++) {
			cin >> c >> d >> x >> y;
			if (d == 0) {
				for (int j = 0; j < 2; j++) {
					for (int k = 0; k < 4; k++) {
						table[y + j][x + k] = c;
					}
				}
			}else {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 2; k++) {
						table[y + j][x + k] = c;
					}
				}
			}
		}

		//�T��
		if (search(table, startx, starty, goalx, goaly, table[starty][startx]))cout << "OK" << endl;
		else cout << "NG" << endl;

		/*for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}*/

		//���������
		for (int i = 0; i < w; i++) {
			delete[] table[i];
			table[i] = 0;//delete��̃|�C���^�폜�A�v��ʃf�[�^�j��Ȃǂ�h��
		}
		delete[] table;
	}
}