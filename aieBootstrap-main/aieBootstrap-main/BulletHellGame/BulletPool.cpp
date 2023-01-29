#include "BulletPool.h"

BulletPool::BulletPool(bool _isEnemy)
{
	m_isEnemy = _isEnemy;

	m_increasedClip = 0;
}

BulletPool::~BulletPool()
{
}

void BulletPool::GetBullet(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY)
{
	for (auto& bullet : m_bullets)
	{
		if (!bullet->IsAlive())
		{
			bullet->Initialise(_parent, _damage, _lifetime, _velX, _velY, _posX, _posY);
			return;
		}
	}

	PlayerBullet* temp = new PlayerBullet();
	m_bullets.push_back(temp);
	temp->Initialise(_parent, _damage, _lifetime, _velX, _velY, _posX, _posY);
}

void BulletPool::Update(float _deltaTime)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->IsAlive())
		{
			m_bullets[i]->Update(_deltaTime);
		}
	}
}

void BulletPool::Draw(aie::Renderer2D* _renderer)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->IsAlive())
		{
			m_isEnemy ? _renderer->setRenderColour(0, 0.3, 0.5) : _renderer->setRenderColour(0.3, 0.5, 0);
			m_bullets[i]->Draw(_renderer);
		}
	}
}

