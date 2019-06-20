#include "DxLib.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
	
	// Window���[�h�ɐݒ�
	ChangeWindowMode(1);

	// DX���C�u������������
	if (DxLib_Init() == -1) { 
		MessageBox(nullptr, "DX���C�u�����̏������Ɏ��s���܂���", "�G���[", MB_OK | MB_ICONERROR);
		return -1; 
	}
	
	// �`�����o�b�N�o�b�t�@�ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//**************************************
	// ����������
	//**************************************


	// �Q�[�����[�v
	while (ProcessMessage() != -1) {
		// ESC�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { break; }
		
		// ��ʏ���
		ClearDrawScreen();

		//**************************************
		// �X�V�ƕ`�揈��
		//**************************************
		

		// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ�
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();
	return 0;
}