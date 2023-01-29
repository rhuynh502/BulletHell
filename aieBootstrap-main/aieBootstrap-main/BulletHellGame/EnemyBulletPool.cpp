#include "EnemyBulletPool.h"

EnemyBulletPool::EnemyBulletPool(Player* _player)
{
	m_player = _player;
}

EnemyBulletPool::~EnemyBulletPool()
{
}

void EnemyBulletPool::GetBullet(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY)
{
	for (auto& bullet : m_bullets)
	{
		if (!bullet->IsAlive())
		{
			bullet->Initialise(_parent, _damage, _lifetime, _velX, _velY, _posX, _posY);
			return;
		}
	}

	EnemyBullet* temp = new EnemyBullet(m_player);
	temp->Initialise(_parent, _damage, _lifetime, _velX, _velY, _posX, _posY);
	m_bullets.push_back(temp);
}

void EnemyBulletPool::Update(float _deltaTime)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->IsAlive())
		{
			m_bullets[i]->Update(_deltaTime);
		}
	}
}

void EnemyBulletPool::Draw(aie::Renderer2D* _renderer)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->IsAlive())
		{
			_renderer->setRenderColour(0, 0.3, 0.5);
			m_bullets[i]->Draw(_renderer);
		}
	}
}