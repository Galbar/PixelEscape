#include "GameScene.hpp"

GameScene::GameScene()
{

}

GameScene::GameScene(sf::RenderWindow* window, const int lvl, const std::string& path) : Scene(window)
{
    // Load and Parse the level
    sf::Image map_image;
    if (not map_image.loadFromFile(path))
        std::cerr << "[GameScene] Imagen de mapa no encontrada." << std::endl;

    int width = map_image.getSize().x;
    int height = map_image.getSize().y;
    m_map = TileMatrix(width,std::vector<Tile>(height));
// Parse image
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            m_map[i][j] = Tile(map_image.getPixel(i, j));
            if (m_map[i][j].is_begin)
            {
                m_x_begin = i;
                m_y_begin = j;
            }
        }
    }
// Get required color
    m_required_color = m_map[0][0];
    m_map[0][0] = Tile(sf::Color::White);
}

GameScene::~GameScene()
{

}

void GameScene::update()
{
    m_player.update();

}

void GameScene::draw()
{

}
