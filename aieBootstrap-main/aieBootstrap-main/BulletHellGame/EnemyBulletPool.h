#pragma once

#include "Renderer2D.h"
#include <vector>
#include "EnemyBullet.h"
#include "Player.h"

class EnemyBulletPool
{
public:
	EnemyBulletPool(Player* _player);
	~EnemyBulletPool();

	void GetBullet(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY);

	void Update(float _deltaTime);
	void Draw(aie::Renderer2D* _renderer);

protected:
	std::vector<EnemyBullet*> m_bullets;

	Player* m_player;

};

