#pragma once

#include "PlayerBullet.h"
#include "Renderer2D.h"
#include <vector>

class BulletPool
{
public:
	BulletPool(bool _isEnemy);
	~BulletPool();

	void GetBullet(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY);

	void Update(float _deltaTime);
	void Draw(aie::Renderer2D* _renderer);

protected:
	std::vector<PlayerBullet*> m_bullets;

	bool m_isEnemy;

	int m_increasedClip;
};

