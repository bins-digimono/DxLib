#include"DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�ɐݒ�

	if (DxLib_Init() == -1) {

		return -1;
	}

	while (1) {
	
	
	}

	
	DxLib_End();

	return 0;
}