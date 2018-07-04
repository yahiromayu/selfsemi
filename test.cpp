#include "DxLib.h"

int Key[256];

int gpUpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetOutApplicationLogValidFlag(false);
	SetBackgroundColor(255,255,255);
	SetGraphMode(480, 480, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	int Image[16];
	LoadDivGraph("img/pazzle.jpg", 16, 4, 4, 120, 120, Image);
	int Sort[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int Crack[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	int tmp=0;
	SRand(123);
	
	for (int i = 0; i < 14; i++) {
		for (int j = i + 1; j < 15;j++) {
			if (GetRand(100) > 50) {
				tmp = Sort[i];
				Sort[i] = Sort[j];
				Sort[j] = tmp;
			}
		}
	}

	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0) {
		if (Key[KEY_INPUT_RIGHT] == 1) {
			if (Crack[0] != 1 && Crack[4] != 1 && Crack[8] != 1 && Crack[12] != 1) {
				for (int i = 0; i < 16; i++) {
					if (Crack[i] == 1) {
						tmp = Sort[i];
						Sort[i] = Sort[i - 1];
						Sort[i - 1] = tmp;
						Crack[i] = 0;
						Crack[i - 1] = 1;
						break;
					}
				}
			}
		}
		else if (Key[KEY_INPUT_LEFT] == 1) {
			if (Crack[3] != 1 && Crack[7] != 1 && Crack[11] != 1 && Crack[15] != 1) {
				for (int i = 0; i < 16; i++) {
					if (Crack[i] == 1) {
						tmp = Sort[i];
						Sort[i] = Sort[i + 1];
						Sort[i + 1] = tmp;
						Crack[i] = 0;
						Crack[i + 1] = 1;
						break;
					}
				}
			}
		}
		else if (Key[KEY_INPUT_UP] == 1) {
			if (Crack[12] != 1 && Crack[13] != 1 && Crack[14] != 1 && Crack[15] != 1) {
				for (int i = 0; i < 16; i++) {
					if (Crack[i] == 1) {
						tmp = Sort[i];
						Sort[i] = Sort[i + 4];
						Sort[i + 4] = tmp;
						Crack[i] = 0;
						Crack[i + 4] = 1;
						break;
					}
				}
			}
		}
		else if (Key[KEY_INPUT_DOWN] == 1) {
			if (Crack[0] != 1 && Crack[1] != 1 && Crack[2] != 1 && Crack[3] != 1) {
				for (int i = 0; i < 16; i++) {
					if (Crack[i] == 1) {
						tmp = Sort[i];
						Sort[i] = Sort[i - 4];
						Sort[i - 4] = tmp;
						Crack[i] = 0;
						Crack[i - 4] = 1;
						break;
					}
				}
			}
		}
			
		ClearDrawScreen();
		for (int i = 0; i < 16; i++) {
			if (i == 15)Crack[15] = 0;
			if (Sort[i] != i)break;
		}
		/*
		//crack check
		DrawFormatString(0, 0, (255, 255, 255), "%d,%d,%d,%d", Crack[0], Crack[1], Crack[2], Crack[3]);
		DrawFormatString(0, 100, (255, 255, 255), "%d,%d,%d,%d", Crack[4], Crack[5], Crack[6], Crack[7]);
		DrawFormatString(0, 200, (255, 255, 255), "%d,%d,%d,%d", Crack[8], Crack[9], Crack[10], Crack[11]);
		DrawFormatString(0, 300, (255, 255, 255), "%d,%d,%d,%d", Crack[12], Crack[13], Crack[14], Crack[15]);
		*/
		/*
		//number check
		DrawFormatString(0, 0, (255, 255, 255), "%d,%d,%d,%d", Sort[0], Sort[1], Sort[2], Sort[3]);
		DrawFormatString(0, 100, (255, 255, 255), "%d,%d,%d,%d", Sort[4], Sort[5], Sort[6], Sort[7]);
		DrawFormatString(0, 200, (255, 255, 255), "%d,%d,%d,%d", Sort[8], Sort[9], Sort[10], Sort[11]);
		DrawFormatString(0, 300, (255, 255, 255), "%d,%d,%d,%d", Sort[12], Sort[13], Sort[14], Sort[15]);
		*/

		if(Crack[0] == 0)DrawGraph(0, 0, Image[Sort[0]], FALSE);
		if (Crack[1] == 0)DrawGraph(120, 0, Image[Sort[1]], FALSE);
		if (Crack[2] == 0)DrawGraph(240, 0, Image[Sort[2]], FALSE);
		if (Crack[3] == 0)DrawGraph(360, 0, Image[Sort[3]], FALSE);
		if (Crack[4] == 0)DrawGraph(0, 120, Image[Sort[4]], FALSE);
		if (Crack[5] == 0)DrawGraph(120, 120, Image[Sort[5]], FALSE);
		if (Crack[6] == 0)DrawGraph(240, 120, Image[Sort[6]], FALSE);
		if (Crack[7] == 0)DrawGraph(360, 120, Image[Sort[7]], FALSE);
		if (Crack[8] == 0)DrawGraph(0, 240, Image[Sort[8]], FALSE);
		if (Crack[9] == 0)DrawGraph(120, 240, Image[Sort[9]], FALSE);
		if (Crack[10] == 0)DrawGraph(240, 240, Image[Sort[10]], FALSE);
		if (Crack[11] == 0)DrawGraph(360, 240, Image[Sort[11]], FALSE);
		if (Crack[12] == 0)DrawGraph(0, 360, Image[Sort[12]], FALSE);
		if (Crack[13] == 0)DrawGraph(120, 360, Image[Sort[13]], FALSE);
		if (Crack[14] == 0)DrawGraph(240, 360, Image[Sort[14]], FALSE);
		if (Crack[15] == 0)DrawGraph(360, 360, Image[Sort[15]], FALSE);
		
	}
	DxLib_End();
    return 0;
}
