#include"key.h"

int NowKeyPressFrame[KeyKindMax];
int PreviousKeyPressFrame[KeyKindMax];

//������
void KeyInit() {

	for (int i = 0; i < KeyKindMax; i++) {

		NowKeyPressFrame[i] = 0;
		PreviousKeyPressFrame[i] = 0;
	}

	return;
}

//�X�V
void KeyUpdate() {

	//�ꎞ�I�ɕێ�����L�[���
	char KeyState[KeyKindMax];

	//���ׂẴL�[������x�Ɏ擾
	GetHitKeyStateAll(KeyState);

	//�L�[�����X�V
	for (int i = 0; i < KeyKindMax; i++) {

		PreviousKeyPressFrame[i] = NowKeyPressFrame[i];

		//���݁A������Ă���Ƃ�
		if (KeyState[i] > 0) {
			//������Ă���t���[�������J�E���g�A�b�v

			NowKeyPressFrame[i]++;
		}

		else if (KeyState[i] == 0) {

			//������Ă��Ȃ���΁A�t���[�������[���N���A
			NowKeyPressFrame[i] = 0;
		}
	}

	return;
}

//����̃L�[����������
bool KeyDown(int KEY_INPUT_) {

	if (NowKeyPressFrame[KEY_INPUT_] > 0) {

		return true;
	}
	{
		return false;
	}
}


bool KeyClick(int KEY_INPUT_) {

	if (NowKeyPressFrame[KEY_INPUT_] == 0 && PreviousKeyPressFrame[KEY_INPUT_] > 0) {

		return true;
	}
	{
		return false;
	}
}



//�t���[�����ŕԂ�
int KeyPressFrame(int KEY_INPUT_) {

	return NowKeyPressFrame[KEY_INPUT_];
}