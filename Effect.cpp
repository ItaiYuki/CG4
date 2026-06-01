#include "Effect.h"
using namespace KamataEngine;

#include <algorithm>
//
// void Effect::Initialize(Model* model, Vector3 position, float rotate, float size)
void Effect::Initialize(Model* model, float rotate, float size, Vector3 position, Vector3 color) {

	// 引数として受け取ったデータをメンバ変数に記録する
	// textureHandle_ = textureHandle;
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	// worldTransform_.translation_ = position;
	worldTransform_.rotation_.z = rotate;
	// worldTransform_.scale_ = { 0.2f, size, 1.0f };
	worldTransform_.scale_ = {0.32f, size / 0.5f, 1.0f};
	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = {color.x, color.y, color.z, 1};
}

void Effect::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		
	}

	worldTransform_.rotation_.y = 3.14f;

	
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera, &objectColor_);
	// model_->Draw(worldTransform_, camera);
}