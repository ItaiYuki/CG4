#pragma once

#include "KamataEngine.h"

class TitleScene {
public:
	~TitleScene();

	void Initialize();
	void Update();
	void Draw();

private:
	// テクスチャ
	uint32_t textureHandle_ = 0;
	uint32_t textureHandleFont_ = 0;
	uint32_t textureHandleHit_ = 0;

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* spriteFont_ = nullptr;
	KamataEngine::Sprite* spriteHit_ = nullptr;

	// 点滅・アニメーション用
	int timer = 0;

	// タイトル文字の落下速度（使う場合）
	float fontSpeed_ = 2.0f;
};