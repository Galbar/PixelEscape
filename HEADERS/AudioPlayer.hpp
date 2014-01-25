#ifndef AUDIOPLAYER_HPP
#define AUDIOPLAYER_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>

class AudioPlayer
{
public:
  AudioPlayer();
  ~AudioPlayer();

static AudioPlayer* sharedAudioPlayer();

  void playMusic(int i);
  void playSound(int i);
  void stopMusic();
  void stopSound();
  int addMusic(std::string path);
  int addSound(std::string path);

private:
  static AudioPlayer* s_audio_player;
  std::vector<std::string>  m_music_list;
  std::vector<sf::SoundBuffer>  m_sound_list;
  sf::Sound* m_sound;
  sf::Music* m_music;


};

#endif