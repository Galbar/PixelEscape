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
    m_hud = new HUD(window, lvl);

    ifstream lvl_info;
    lvl_info.open(path.c_str());
    if (!lvl_info.good())
    {
        std::cerr << "[Game] Error al abrir info de nivel." << std::endl;
    }
    string s;
    getline(lvl_info, s);
    float t = atof(s.c_str());
    if (t > 0)
    {
        m_is_dynamic = true;
    }
    else
    {
        m_is_dynamic = false;    
    }
    m_dyn_shift = t;
    while (not lvl_info.eof())
    {
        getline(lvl_info, s);
        
        // Load and Parse the level
        sf::Image map_image;
        if (not map_image.loadFromFile(s))
            std::cerr << "[GameScene] Imagen de mapa no encontrada. " << s << std::endl;

        int width = map_image.getSize().x;
        int height = map_image.getSize().y;
        TileMatrix curr_map = TileMatrix(width,std::vector<Tile>(height));
        // Parse image
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < height; ++j)
            {
                curr_map[i][j] = Tile(map_image.getPixel(i, j));
                if (curr_map[i][j].is_begin)
                {
                    m_x_begin = i;
                    m_y_begin = j;
                }
            }
        }
        m_map.push_back(curr_map);
    }

    m_timer.restart();

    m_active_map = 0;
    m_current_map_frame = 0;
// Get required color
    m_required_color = m_map[m_active_map][0][0];
    m_map[m_active_map][0][0] = Tile(sf::Color::White);
    m_game_over = false;
    m_win = false;
    m_player = new Player(m_x_begin, m_y_begin, m_window);
}

GameScene::~GameScene()
{
    delete m_player;
    delete m_hud;
}

void GameScene::update()
{

    m_player->update();

    sf::Vector2i p = m_player->getPos(0);
    if (m_map[m_active_map][p.x][p.y].r)
        m_player->killRGB(0);
    p = m_player->getPos(1);
    if (m_map[m_active_map][p.x][p.y].g)
        m_player->killRGB(1);
    p = m_player->getPos(2);
    if (m_map[m_active_map][p.x][p.y].b)
        m_player->killRGB(2);

    if (not (m_required_color.getMask() == (m_required_color.getMask() & m_player->getMask())))
    {
        m_game_over = true;
    }
        
    if (m_map[m_active_map][m_player->getActivePos().x][m_player->getActivePos().y].is_end and
        (m_required_color.getMask() == m_player->getActiveMask()))
    {
        m_win = true;
    }
   
    m_hud->update();

    if (m_is_dynamic and m_timer.getElapsedTime().asSeconds() > m_dyn_shift)
    {
        m_timer.restart();
        m_current_map_frame++;
        m_active_map = m_current_map_frame % m_map.size();
    }
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
    active_pos.x = min(active_pos.x, m_map[m_active_map].size()-22);
    active_pos.y = max(active_pos.y, 21);
    active_pos.y = min(active_pos.y, m_map[m_active_map][0].size()-22);
    int active_mask = m_player->getActiveMask();
    for (int x = active_pos.x-21; x <= active_pos.x+21; x++)
    {
        for (int y = active_pos.y-21; y <= active_pos.y+21; y++)
        {
            sprite.setPosition(tile_size*(x+21-active_pos.x), tile_size*(y+21-active_pos.y));
            int num = m_map[m_active_map][x][y].mask[active_mask];
            int tx = (num%tilemap_size)*tile_size;
            int ty = (num/tilemap_size)*tile_size;
            sprite.setTextureRect(sf::IntRect(tx,ty,tile_size,tile_size));
            m_window->draw(sprite);
            if (m_map[m_active_map][x][y].is_end)
            {
                Tile c = m_required_color;
                int goal_mask = 4*c.r+2*c.g+c.b;
                num = m_map[m_active_map][0][0].mask[goal_mask];
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

void GameScene::pause()
{
    m_hud->pause();
}

void GameScene::resume()
{
    m_hud->resume();
}

bool GameScene::gameOver()
{
    return m_game_over;
}

bool GameScene::win()
{
    return m_win;
}