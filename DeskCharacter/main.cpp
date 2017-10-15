#include "DxLib.h"
using namespace DxLib;

static WNDPROC pPrevWndProc;

static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_NCHITTEST:
		// ウインドウの枠の上にカーソルがあることにする
		return HTCAPTION;
	}
	return CallWindowProc(pPrevWndProc, hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//型の定義
	using define = const int;
	using graph = int;

	//宣言部
	

	//ウィンドウの縦横の長さの定義
	define SCREEN_SIZE_W = 560; 
	define SCREEN_SIZE_H = 450;

	//ウィンドウの設定とDxLibの初期化処理
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(1, 0, 0);//背景色設定
	SetGraphMode(SCREEN_SIZE_W, SCREEN_SIZE_H, 32);	// 描画スクリーンのサイズを指定します
	SetWindowStyleMode(2);	// ウィンドウの枠無し
	SetUseBackBufferTransColorFlag(TRUE);	// ウィンドウを透明

	//画像読み込み
	graph character = LoadGraph("../pictures/yuyuko.png");
	graph massagewindow1 = LoadGraph("../pictures/message_window1.png");
	graph string_1 = LoadGraph("../pictures/string1.png");

	//透過色の設定
	SetTransColor(1, 0, 0);

	// ウィンドウのサブクラス化(ウィンドウプロシージャのフック)
	pPrevWndProc = (WNDPROC)GetWindowLongPtr(GetMainWindowHandle(), GWLP_WNDPROC);
	SetWindowLongPtr(GetMainWindowHandle(), GWLP_WNDPROC, (LONG_PTR)WndProc);

	//月の取得
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