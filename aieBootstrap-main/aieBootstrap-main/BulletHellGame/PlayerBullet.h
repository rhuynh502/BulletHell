#pragma once

#include "Renderer2D.h"
#include "Vec2.h"
#include "SceneObject.h"

class PlayerBullet : public SceneObject
{
public:
	PlayerBullet();
	~PlayerBullet();

	void Initialise(SceneObject* _parent, float _damage, float _lifetime, float _velX, float _velY, float _posX, float _posY);

	void Update(float _deltaTime);
	void Draw(aie::Renderer2D* _renderer);

	void Travel(float _deltaTime);
	void OnHit();

	bool IsAlive() const { return m_lifetime > 0; }

protected:
	float m_damage;
	float m_lifetime;

	float m_velocityX;
	float m_velocityY;

};

