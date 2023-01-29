#pragma once

#include <random>
#include "Renderer2D.h"
#include "EnemyBulletPool.h"
#include "Player.h"
#include "Font.h"
#include "SceneObject.h"

class Enemy : public SceneObject
{
public:
	Enemy(Player* _player);
	~Enemy();

	void OnUpdate(float _deltaTime) override;
	void Draw();

	int RandomDirection();
	void AIMovement(float _deltaTime, float _direction);

	void Shoot();

protected:
	float m_xPos;
	float m_yPos;

	float m_moveSpeed;
	float m_moveTimer;

	float m_health;

	float m_damage;
	float m_attTimer;
	float m_defAttTimer;

	float m_currDirection;

	Player* m_player;

	aie::Font* m_font;

	EnemyBulletPool* m_bullets;

	aie::Renderer2D* m_enemyRenderer;
};

