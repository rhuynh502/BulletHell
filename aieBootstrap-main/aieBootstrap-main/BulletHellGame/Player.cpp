#include "Player.h"
#include <string>

Player::Player()
{
	m_playerRenderer = new aie::Renderer2D;

	m_xPos = 50;
	m_yPos = 100;

	m_moveSpeed = 100;

	m_attTimer = 0.3f;
	m_defAttTimer = 0.3f;
	m_damage = 10;

	m_health = 5;

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_bullets = new BulletPool(false);
}

Player::~Player()
{
	delete m_playerRenderer;
	delete m_bullets;
}

void Player::Draw()
{
	m_playerRenderer->begin();

	m_playerRenderer->drawText(m_font, std::to_string(m_health).c_str(), 100, 100);

	m_playerRenderer->setRenderColour(0, 1, 0);
	m_playerRenderer->drawCircle(m_xPos, m_yPos, 5);

	m_playerRenderer->setRenderColour(0, 0, 1);
	
	m_bullets->Draw(m_playerRenderer);

	m_playerRenderer->end();

}

void Player::OnUpdate(float _deltaTime)
{
	m_attTimer -= _deltaTime;

	aie::Input* playerInput = aie::Input::getInstance();

	PlayerMovement(_deltaTime, playerInput);

	if (playerInput->isKeyDown(aie::INPUT_KEY_Z))
	{
		if (m_attTimer < 0)
		{
			PlayerShoot();
			m_attTimer = m_defAttTimer;
		}
	}

	//m_bullets->Update(_deltaTime);
}

float Player::GetXPos()
{
	return m_xPos;
}

float Player::GetYPos()
{
	return m_yPos;
}

void Player::PlayerMovement(float _deltaTime, aie::Input* _input)
{

	// Strafe
	if (_input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
	{
		m_moveSpeed = 50;
	}
	else
	{
		m_moveSpeed = 100;
	}

	// Movement
	if (_input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_yPos += m_moveSpeed * _deltaTime;
	}
	if (_input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_yPos -= m_moveSpeed * _deltaTime;
	}
	if (_input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_xPos -= m_moveSpeed * _deltaTime;
	}
	if (_input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_xPos += m_moveSpeed * _deltaTime;
	}
}

void Player::PlayerShoot()
{
	m_bullets->GetBullet(this, m_damage, 5, 0, 100, m_xPos, m_yPos + 5);
}

void Player::TakeDamage()
{
	m_health--;
}

