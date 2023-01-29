#pragma once

#include "Renderer2D.h"
#include "Player.h"
#include "SceneObject.h"

class EnemyBullet : public SceneObject
{
public:
	EnemyBullet(Player* _player);
	~EnemyBullet();

	void Initialise(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY);

	void OnUpdate(float _deltaTime) override;
	void Draw(aie::Renderer2D* _renderer);

	void Travel(float _deltaTime);
	void OnHit(Player* _player);
	void CheckCollision(Player* _player);

	bool IsAlive() const { return m_lifetime > 0; }

protected:
	float m_damage;
	float m_lifetime;

	float m_velocityX;
	float m_velocityY;
	float m_angle;

	bool m_hit;

	Player* m_player;
};

