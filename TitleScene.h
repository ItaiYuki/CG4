#pragma once
#include "KamataEngine.h"


	


class TitleScene
{
public:
	// デストラクタ
	~TitleScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	bool IsFinished() const;

private:
	bool isFinished_ = false;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandleFont_ = 0;
	uint32_t textureHandleHit_ = 0;

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* spriteFont_ = nullptr;
	KamataEngine::Sprite* spriteHit_ = nullptr;

	int timer = 0;
};
