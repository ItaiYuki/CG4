#include "Particle.h"
#include <cassert>

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {2.0f, 2.0f, 2.0f};
	worldTransform_.UpdateMatrix();

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};
	objectColor_.SetColor(color_);
}

void Particle::Update() { worldTransform_.UpdateMatrix(); }

void Particle::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }