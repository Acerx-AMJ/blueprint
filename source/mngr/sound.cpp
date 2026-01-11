#include "mngr/sound.hpp"
#include "utils/math.hpp"
#include <filesystem>
#include <unordered_map>

// Globals

static std::unordered_map<std::string, Sound> sounds;
static std::unordered_map<std::string, Music> music;
static std::unordered_map<std::string, std::vector<std::string>> savedSounds;

// Load functions

void loadSound(const std::string &name, const std::string &path) {
   Sound sound = LoadSound(path.c_str());
   sounds[name] = sound;
}

void loadMusic(const std::string &name, const std::string &path) {
   Music track = LoadMusicStream(path.c_str());
   music[name] = track;
}

void saveSound(const std::string &name, const std::vector<std::string> &soundList) {
   savedSounds[name] = soundList;
}

void loadSounds() {
   std::filesystem::create_directories("assets/sounds/");
   for (const auto &file: std::filesystem::recursive_directory_iterator("assets/sounds/")) {
      if (file.is_regular_file()) {
         loadSound(file.path().stem().string(), file.path().string());
      }
   }
}

void loadMusic() {
   std::filesystem::create_directories("assets/music/");
   for (const auto &file: std::filesystem::recursive_directory_iterator("assets/music/")) {
      if (file.is_regular_file()) {
         loadMusic(file.path().stem().string(), file.path().string());
      }
   }
}

void loadSavedSounds() {
   // Put any saved sounds in here!
}

// Play functions

void playSound(const std::string &name) {
   if (!savedSounds.count(name) && !sounds.count(name)) {
      printf("ERROR: sound '%s' does not exist.", name.c_str());
      std::exit(EXIT_FAILURE);
   }
   Sound sound;

   if (savedSounds.count(name)) {
      std::string &randomName = random(savedSounds[name]);
      sound = sounds[randomName];
   } else {
      sound = sounds[name];
   }
   SetSoundPitch(sound, random(0.95f, 1.05f));
   PlaySound(sound);
}

void playMusic(const std::string &name) {
   if (!music.count(name)) {
      printf("ERROR: music '%s' does not exist.", name.c_str());
      std::exit(EXIT_FAILURE);
   }
   PlayMusicStream(music[name]);
}
