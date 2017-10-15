#include "DxLib.h"
using namespace DxLib;

static WNDPROC pPrevWndProc;

static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_NCHITTEST:
		// �E�C���h�E�̘g�̏�ɃJ�[�\�������邱�Ƃɂ���
		return HTCAPTION;
	}
	return CallWindowProc(pPrevWndProc, hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�^�̒�`
	using define = const int;
	using graph = int;

	//�錾��
	

	//�E�B���h�E�̏c���̒����̒�`
	define SCREEN_SIZE_W = 560; 
	define SCREEN_SIZE_H = 450;

	//�E�B���h�E�̐ݒ��DxLib�̏���������
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(1, 0, 0);//�w�i�F�ݒ�
	SetGraphMode(SCREEN_SIZE_W, SCREEN_SIZE_H, 32);	// �`��X�N���[���̃T�C�Y���w�肵�܂�
	SetWindowStyleMode(2);	// �E�B���h�E�̘g����
	SetUseBackBufferTransColorFlag(TRUE);	// �E�B���h�E�𓧖�

	//�摜�ǂݍ���
	graph character = LoadGraph("../pictures/yuyuko.png");
	graph massagewindow1 = LoadGraph("../pictures/message_window1.png");
	graph string_1 = LoadGraph("../pictures/string1.png");

	//���ߐF�̐ݒ�
	SetTransColor(1, 0, 0);

	// �E�B���h�E�̃T�u�N���X��(�E�B���h�E�v���V�[�W���̃t�b�N)
	pPrevWndProc = (WNDPROC)GetWindowLongPtr(GetMainWindowHandle(), GWLP_WNDPROC);
	SetWindowLongPtr(GetMainWindowHandle(), GWLP_WNDPROC, (LONG_PTR)WndProc);

	//���̎擾
	SYSTEMTIME st;
	GetLocalTime(&st);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		DrawGraph(0, 0, massagewindow1, TRUE);
		DrawGraph(0, 0, string_1, TRUE);

		DrawGraph(280, 0, character,TRUE);
	}
	DxLib_End();
	return 0;
}