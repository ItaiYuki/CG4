#include "Effect.h"
using namespace KamataEngine;

#include <algorithm>

// void Effect::Initialize(Model* model, Vector3 position, float rotate, float size)
void Effect::Initialize(Model* model, Vector3 position, Vector3 color) {

	// 引数として受け取ったデータをメンバ変数に記録する
	// textureHandle_ = textureHandle;
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	worldTransform_.rotation_.y = 3.14f;
	worldTransform_.rotation_.z = 0.0f;

	worldTransform_.scale_ = {5.0f, 5.0f, 5.0f};

	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = {color.x, color.y, color.z, 1};
	objectColor_.SetColor(color_);
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera, &objectColor_);
	// model_->Draw(worldTransform_, camera);
}