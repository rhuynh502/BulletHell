#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_player = new Player();
	m_enemies.push_back(new Enemy(m_player));

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_player;

	for (int i = 0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
	}
}

void Application2D::update(float _deltaTime) {

	m_timer += _deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	m_player->Update(_deltaTime);

	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Update(_deltaTime);
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// draw characters
	m_player->Draw();

	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Draw();
	}

	// begin drawing sprites
	m_2dRenderer->begin();

	/*m_2dRenderer->setRenderColour(1, 0, 0);

	for (int i = 0; i <= 5; i++)
	{
		m_2dRenderer->drawLine(100 * i, 0, 100 * i, 900);
	}

	for (int i = 0; i <= 9; i++)
	{
		m_2dRenderer->drawLine(0, 100 * i, 500, 100 * i);
	}*/

	// fps
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}