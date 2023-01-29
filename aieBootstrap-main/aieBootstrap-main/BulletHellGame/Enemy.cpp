#include "Enemy.h"
#include <string>

Enemy::Enemy(Player* _player)
{
	m_enemyRenderer = new aie::Renderer2D;

	m_xPos = 250;
	m_yPos = 600;

	m_moveSpeed = 100;

	m_moveTimer = 0;

	m_damage = 2;
	m_attTimer = 0.2;
	m_defAttTimer = 0.2;

	m_player = _player;

	m_health = 100;

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_bullets = new EnemyBulletPool(_player);
}

Enemy::~Enemy()
{
	delete m_enemyRenderer;
	delete m_bullets;
}

void Enemy::OnUpdate(float _deltaTime)
{
	m_attTimer -= _deltaTime;

	if (m_attTimer < 0)
	{
		Shoot();
		m_attTimer = m_defAttTimer;
	}
}

void Enemy::Draw()
{
	m_enemyRenderer->begin();

	m_enemyRenderer->drawText(m_font, std::to_string(m_health).c_str(), 500, 100);

	m_enemyRenderer->setRenderColour(1, 0, 0);
	m_enemyRenderer->drawCircle(m_xPos, m_yPos, 5);

	m_bullets->Draw(m_enemyRenderer);

	m_enemyRenderer->end();
}

void Enemy::AIMovement(float _deltaTime, float _direction)
{
	if (_direction == 0)
	{
		m_yPos += m_moveSpeed * _deltaTime;
	}
	if (_direction == 1)
	{
		m_yPos -= m_moveSpeed * _deltaTime;
	}
	if (_direction == 2)
	{
		m_xPos -= m_moveSpeed * _deltaTime;
	}
	if (_direction == 3)
	{
		m_xPos += m_moveSpeed * _deltaTime;
	}
}

void Enemy::Shoot()
{
	// pattern one
	//m_bullets->GetBullet(this, m_damage, 20, -60, -25, m_xPos + 1, m_yPos);
	
}

std::random_device rd;
std::mt19937 gen(rd());

int Enemy::RandomDirection()
{
	int min = 0;
	int max = 3;

	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}