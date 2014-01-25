#include "AudioPlayer.hpp"

AudioPlayer* AudioPlayer::s_audio_player = NULL;

AudioPlayer::AudioPlayer()
{
    m_music.setLoop(true);
}

AudioPlayer::~AudioPlayer()
{
    
}

AudioPlayer* AudioPlayer::sharedAudioPlayer()
{
    if (s_audio_player == NULL)
    {
        s_audio_player = new AudioPlayer();
    }
    return s_audio_player;
}

void AudioPlayer::playMusic(int i)
{
    if (!m_music.openFromFile(m_music_list[i]))
        std::cerr << "[AudioPlayer] Error al cargar musica: " << m_music_list[i] << std::endl;
    m_music.play();
}

void AudioPlayer::playSound(int i)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile(m_sound_list[i]);
    m_sound.setBuffer(buffer);
    m_sound.play();
}

void AudioPlayer::stopMusic()
{
    m_music.stop();
}

void AudioPlayer::stopSound()
{
    m_sound.stop();
}

int AudioPlayer::addMusic(std::string& path)
{
    m_music_list.push_back(path);
    return m_music_list.size()-1;
}

int AudioPlayer::addSound(std::string& path)
{
    m_sound_list.push_back(path);
    return m_sound_list.size()-1;
}
