#include "GameScene.h"

using namespace KamataEngine;
using namespace MathUtility;

// デストラクタ
GameScene::~GameScene() {

	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();

	delete modelEffect_;
	modelEffect_ = nullptr;
}

// 初期化
void GameScene::Initialize() {

	// 菱形モデル
	modelEffect_ = Model::CreateFromOBJ("plane");

	// カメラ初期化
	camera_.Initialize();

	// Effectを1個生成
	Vector3 position = {0.0f, 0.0f, 0.0f};
	EffectBorn(position);
}

// 更新
void GameScene::Update() {

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

// 描画
void GameScene::Draw() {

	Model::PreDraw();

	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	Model::PostDraw();
}

// エフェクト生成
void GameScene::EffectBorn(Vector3 position) {

	Vector3 color = {1.0f, 1.0f, 1.0f};

	Effect* effect = new Effect();

	effect->Initialize(modelEffect_, position, color);

	effects_.push_back(effect);
}