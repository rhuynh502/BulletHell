#pragma once

#include <cmath>
#include "Input.h"
#include "Renderer2D.h"
#include <random>
#include "BulletPool.h"
#include "Font.h"
#include "SceneObject.h"

class Player : public SceneObject
{
public:
	Player();
	~Player();

	//void Update(float _deltaTime);
	void Draw();
	void OnUpdate(float _deltaTime) override;

	float GetXPos();
	float GetYPos();

	void PlayerMovement(float _deltaTime, aie::Input* _input);
	void PlayerShoot();
	void TakeDamage();

protected:
	float m_xPos;
	float m_yPos;

	float m_moveSpeed;

	float m_health;

	float m_attTimer;
	float m_defAttTimer;
	float m_damage;
	aie::Font* m_font;

	BulletPool* m_bullets;

	aie::Renderer2D* m_playerRenderer;
};

