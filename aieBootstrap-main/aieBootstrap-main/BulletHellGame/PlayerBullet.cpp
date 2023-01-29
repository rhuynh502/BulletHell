#include "PlayerBullet.h"


PlayerBullet::PlayerBullet()
{
	m_lifetime = 0;
}

PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::Initialise(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY)
{
	m_damage = _damage;
	m_lifetime = _lifetime;
	m_velocityX = _velX;
	m_velocityY = _velY;
	Transform->SetTranslation(_posX, _posY);
	SetParent(_parent, this);
}

void PlayerBullet::Update(float _deltaTime)
{
	Travel(_deltaTime);
	
}

void PlayerBullet::Draw(aie::Renderer2D* _renderer)
{
	auto gt = GetGlobalTransform();
	auto pos = gt->GetTranslation();

	_renderer->drawCircle(pos->x, pos->y, 4);

	delete gt;
	delete pos;
}

void PlayerBullet::Travel(float _deltaTime)
{
	if (!IsAlive())
		return;

	m_lifetime -= _deltaTime;

	auto gt = GetGlobalTransform();
	auto pos = gt->GetTranslation();

	pos->x += m_velocityX * _deltaTime;
	pos->y += m_velocityY * _deltaTime;
}

void PlayerBullet::OnHit()
{
}
