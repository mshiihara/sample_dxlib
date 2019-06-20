#include "DxLib.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
	
	// Windowモードに設定
	ChangeWindowMode(1);

	// DXライブラリを初期化
	if (DxLib_Init() == -1) { 
		MessageBox(nullptr, "DXライブラリの初期化に失敗しました", "エラー", MB_OK | MB_ICONERROR);
		return -1; 
	}
	
	// 描画先をバックバッファに設定
	SetDrawScreen(DX_SCREEN_BACK);

	//**************************************
	// 初期化処理
	//**************************************


	// ゲームループ
	while (ProcessMessage() != -1) {
		// ESCキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { break; }
		
		// 画面消去
		ClearDrawScreen();

		//**************************************
		// 更新と描画処理
		//**************************************
		

		// バックバッファとフロントバッファを入れ替え
		ScreenFlip();
	}

	// DXライブラリの終了処理
	DxLib_End();
	return 0;
}