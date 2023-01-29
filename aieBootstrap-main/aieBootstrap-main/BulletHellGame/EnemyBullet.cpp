#include "EnemyBullet.h"
#include <cmath>

EnemyBullet::EnemyBullet(Player* _player)
{
	m_lifetime = 0;
	m_angle = 0;
	m_hit = true;
	m_player = _player;
	m_damage = 0;
	m_velocityX = 0;
	m_velocityY = 0;
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::Initialise(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY)
{
	m_damage = _damage;
	m_lifetime = _lifetime;
	m_velocityX = _velX;
	m_velocityY = _velY;
	Transform->SetTranslation(_posX, _posY);
	SetParent(_parent, this);
}

void EnemyBullet::OnUpdate(float _deltaTime)
{
	Travel(_deltaTime);

	m_angle += _deltaTime;

	// check if bullet is close enough to player to do collision detection

	Vec2* pos = Transform->GetTranslation();

	if (sqrt(pow(pos->x - m_player->GetXPos(), 2) + pow(pos->y - m_player->GetYPos(), 2)) > 15) return;

	CheckCollision(m_player);
}

void EnemyBullet::Draw(aie::Renderer2D* _renderer)
{
	auto gt = GetGlobalTransform();
	auto pos = gt->GetTranslation();

	_renderer->drawCircle(pos->x, pos->y, 4);

	delete gt;
	delete pos;
}

void EnemyBullet::Travel(float _deltaTime)
{
	if (!IsAlive())
		return;

	m_lifetime -= _deltaTime;

	Transform = Transform->CreateZRotation(0.04f)->Multiply(Transform);
	
	
	/*m_pos->x += std::cos(m_angle) * _deltaTime;
	m_pos->y += std::sin(m_angle) * _deltaTime;*/
}

void EnemyBullet::CheckCollision(Player* _player)
{
	Mat3* gt = GetGlobalTransform();
	auto pos = gt->GetTranslation();

	if (m_hit
		&& pos->x < _player->GetXPos() + 2.5 && pos->x > _player->GetXPos() - 2.5
		&& pos->y < _player->GetYPos() + 2.5 && pos->y > _player->GetYPos() - 2.5)
	{
		OnHit(_player);
		m_hit = false;
	}

	delete gt;
	delete pos;
}

void EnemyBullet::OnHit(Player* _player)
{
	_player->TakeDamage();
}
