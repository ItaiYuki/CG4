#include <Windows.h>

 #include "GameScene.h"
#include "KamataEngine.h"
#include "TitleScene.h"
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_05_イタイ_ユウキ_CG4");

	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	 GameScene* gameScene = new GameScene();
	// ゲームシーンの初期化
	 gameScene->Initialize();
	// タイトルシーンのインスタンス生成
	TitleScene* titleScene = new TitleScene();
	// タイトルシーンの初期化
	titleScene->Initialize();

	enum Scene {
		TITLE,
		GAME,
	};

	Scene scene = TITLE;


	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		if (scene == TITLE) {
			titleScene->Update();

			// タイトル終了ならゲームへ
			if (titleScene->IsFinished()) {
				scene = GAME;
			}
		} else if (scene == GAME) {
			gameScene->Update();
		}

		// 描画開始
		dxCommon->PreDraw();

		if (scene == TITLE) {
			titleScene->Draw();
		} else if (scene == GAME) {
			gameScene->Draw();
		}

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの削除
	 delete gameScene;
	// nullptrの代入
	 gameScene = nullptr;

	// タイトルシーンの削除
	 delete titleScene;
	// nullptrの代入
	 titleScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}