#include "HUD.hpp"

std::string itoa(int x)
{
	std::string res;
	if (x == 0) res = "0";
	while(x != 0)
	{
		res.insert(res.begin(), x%10 +'0');
		x /= 10;
	}
	return res;
}

HUD::HUD(sf::RenderWindow* window, int level)
{
	m_window = window;

	if (!m_font.loadFromFile("data/fonts/PressStart2P.ttf"))
	{
		std::cerr << "[HUD] Fuente no encontrada." << std::endl;
	}

	std::string levelLabelString("level:" + itoa(level));

	m_levelLabel.setFont(m_font);
	m_levelLabel.setString(levelLabelString);
	m_levelLabel.setCharacterSize(25);
	m_levelLabel.setPosition(10,10);
	m_levelLabel.setColor(sf::Color::Blue);


	m_PauseLabel.setFont(m_font);
	m_PauseLabel.setString("PAUSE");
	m_PauseLabel.setCharacterSize(100);
	m_PauseLabel.setPosition(100,200);
	m_PauseLabel.setColor(sf::Color::Green);

	sf::Texture TexMex;
	if (!TexMex.loadFromFile("data/textures/pause_background.png"))
		std::cerr << "[TexMex] No encuentro mi puta textura, búscamela!" << std::endl;
	m_PauseSprite.setTexture(TexMex);
	m_PauseSprite.setColor(sf::Color(0,0,0,155));
	m_PauseSprite.setPosition(0,0);
	m_PauseSprite.setScale(700,700);

	isPaused = false;

}

HUD::~HUD()
{

}

void HUD::draw()
{
	m_window->draw(m_levelLabel);	

	if(isPaused)
	{
		m_window->draw(m_PauseSprite);		
		m_window->draw(m_PauseLabel);		
	}
}

void HUD::update()
{
	
}

void HUD::reset()
{

}

void HUD::pause()
{
	isPaused = true;
}

void HUD::resume()
{
	isPaused = false;
}
