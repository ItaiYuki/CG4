#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

// デストラクタ
GameScene::~GameScene() {
	// 3Dモデルデータの解放
	delete modelParticle_;

	// パーティクルの解放
	delete particle_;
	particle_ = nullptr;
}

// 初期化
void GameScene::Initialize() {
	// 乱数の初期化
	srand((unsigned)time(NULL));

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルを1個だけ生成
	Particle* particle = new Particle();
	particle->Initialize(modelParticle_, {0.0f, 0.0f, 0.0f});

	particle_ = particle;
}

// 更新
void GameScene::Update() {
	if (particle_) {
		particle_->Update();
	}
}
void GameScene::Draw() {
	// 3Dモデル描画前処理
	Model::PreDraw();

	// パーティクル描画
	if (particle_) {
		particle_->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}


