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
    sf::Vector2i pos = m_player.getPos();
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
        
    if (m_map[m_player.getActivePos().x][m_player.getActivePos().y].is_end)
        // WIN!
}

void GameScene::draw()
{
    int tile_size = 32;
    Scene::render();
    sf::Texture tilemap;
    if (!tilemap.loadFromFile("data/textures/tilemap.png")) std::cerr << "ERROR LOADING IMAGE" << endl;
    int tilemap_size = 8;
    sf::Sprite sprite;
    sprite.setTexture(tilemap);
    sf::Vector2i active_pos = m_player.getActivePos();
    active_pos.x = std::max(active_pos.x, 10);
    active_pos.x = std::min(active_pos.x, m_map.size()-11);
    active_pos.y = std::max(active_pos.y, 10);
    active_pos.y = std::min(active_pos.y, m_map[0].size()-11);
    for (int x = ; x < scene_map.size(); x++)
    {
        for (int y = 0; y < scene_map[x].size(); y++)
        {
            sprite.setPosition(tile_size*x, tile_size*y);
            int num = m_map[active_pos.x][active_pos.y];
            int tx = (num%tilemap_size)*tile_size;
            int ty = (num/tilemap_size)*tile_size;
            sprite.setTextureRect(sf::IntRect(tx,ty,tile_size,tile_size));
            window->draw(sprite);
        }
    }
}
