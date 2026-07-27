#pragma once

//#include "DrawNumber.h"
#include "GraphBar.h"
#include "KamataEngine.h"
#include "Player.h"
#include "Stage.h"

// ゲームシーン
class GameScene {
public:
	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandleStage_ = 0;
	uint32_t textureHandleGraph_ = 0;
	uint32_t textureHandleNumber_ = 0;
	// 3Dモデル
	KamataEngine::Model* modelPlayer_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	// クラス
	Stage* stage_ = nullptr;
	Player* player_ = nullptr;
	GraphBar* graphBar_ = nullptr;
	/*DrawNumber* drawNumber_ = nullptr;*/
	// HP
	int hp_ = 200;
	// score
	int gameScore_ = 0;
};
