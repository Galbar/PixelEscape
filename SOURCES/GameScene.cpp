#include "GameScene.hpp"
#include <iostream>

int max(int a, int b)
{
    if (a >= b) return a;
    return b;
}

int min(int a, int b)
{
    if (a <= b) return a;
    return b;
}

GameScene::GameScene()
{
}

GameScene::GameScene(sf::RenderWindow* window, const int lvl, const std::string& path) : Scene(window)
{
    std::string music_path = "data/audio/music/Final Boss Song.wav";
    AudioPlayer* au = AudioPlayer::sharedAudioPlayer();
    int i = au->addMusic(music_path);
    au->playMusic(i);

     m_hud = new HUD(window, lvl);

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

    m_player = new Player(m_x_begin, m_y_begin, m_window);



}

GameScene::~GameScene()
{
    delete m_player;
}

void GameScene::update()
{

    m_player->update();

    sf::Vector2i p = m_player->getPos(0);
    if (m_map[p.x][p.y].r)
        m_player->killRGB(0);
    p = m_player->getPos(1);
    if (m_map[p.x][p.y].g)
        m_player->killRGB(1);
    p = m_player->getPos(2);
    if (m_map[p.x][p.y].b)
        m_player->killRGB(2);

    if (not (m_required_color.getMask() == (m_required_color.getMask() & m_player->getMask())))
    {
        // GAME OVER!!
    }
        
    if (m_map[m_player->getActivePos().x][m_player->getActivePos().y].is_end and
        (m_required_color.getMask() == m_player->getMask()))
    {
        // WIN!
        std::cerr << "HAS GANADO!!!" << std::endl;
    }
   
    m_hud->update();
}

void GameScene::draw()
{
    int tile_size = 16;
    Scene::draw();
    int tilemap_size = 8;
    sf::Sprite sprite;
    sf::Texture tilemap;
    if (!tilemap.loadFromFile("data/textures/tilemap.png")) std::cerr << "[GameScene] Error cargando tilemap" << endl;
    sprite.setTexture(tilemap);
    sf::Vector2i active_pos = m_player->getActivePos();
    active_pos.x = max(active_pos.x, 21);
    active_pos.x = min(active_pos.x, m_map.size()-22);
    active_pos.y = max(active_pos.y, 21);
    active_pos.y = min(active_pos.y, m_map[0].size()-22);
    int active_mask = m_player->getActiveMask();
    for (int x = active_pos.x-21; x <= active_pos.x+21; x++)
    {
        for (int y = active_pos.y-21; y <= active_pos.y+21; y++)
        {
            sprite.setPosition(tile_size*(x+21-active_pos.x), tile_size*(y+21-active_pos.y));
            int num = m_map[x][y].mask[active_mask];
            int tx = (num%tilemap_size)*tile_size;
            int ty = (num/tilemap_size)*tile_size;
            sprite.setTextureRect(sf::IntRect(tx,ty,tile_size,tile_size));
            m_window->draw(sprite);
            if (m_map[x][y].is_end)
            {
                Tile c = m_required_color;
                int goal_mask = 4*c.r+2*c.g+c.b;
                num = m_map[0][0].mask[goal_mask];
                tx = (num%tilemap_size)*tile_size;
                int ty = (num/tilemap_size)*tile_size;
                sprite.setTextureRect(sf::IntRect(tx,ty,tile_size/2,tile_size));
                m_window->draw(sprite);
            }
        }
    }
    m_player->draw(active_pos.x, active_pos.y);
    
    m_hud->draw();
}
