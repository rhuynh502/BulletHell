#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float _deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	Player* m_player;

	std::vector<Enemy *> m_enemies;

	float m_timer;
};