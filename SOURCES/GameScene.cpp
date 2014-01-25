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
    m_player = Player(m_x_begin, m_y_begin);
}

GameScene::~GameScene()
{

}

void GameScene::update()
{
    m_player.update();

    sf::Vector2i p = getPos(0);
    if (m_map[p.x][p.y].r)
        m_player.killRGB(0);
    p = getPos(1);
    if (m_map[p.x][p.y].g)
        m_player.killRGB(1);
    p = getPos(2);
    if (m_map[p.x][p.y].b)
        m_player.killRGB(2);

    if (not (m_required_color.getMask() == (m_required_color.getMask() & m_player.getMask())))
        // GAME OVER!!
}

void GameScene::draw()
{

}
