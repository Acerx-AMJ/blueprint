#include "mngr/asset.hpp"
#include <filesystem>
#include <unordered_map>

// Globals

static std::unordered_map<std::string, Texture> textures;
static std::unordered_map<std::string, Font> fonts;

// Fallback functions

// Hopefully we won't need to call these
Texture &getFallbackTexture() {
   static Texture fallbackTexture;
   static bool loaded = false;

   if (!loaded) {
      Image image = GenImageChecked(8, 8, 2, 2, MAGENTA, BLACK);
      fallbackTexture = LoadTextureFromImage(image);
      UnloadImage(image);
      loaded = true;
   }
   return fallbackTexture;
}

Font &getFallbackFont() {
   static Font fallbackFont = GetFontDefault();
   return fallbackFont;
}

// Load functions

Texture &loadTexture(const std::string &name, const std::string &path) {
   if (textures.count(name)) {
      return textures[name];
   }

   Texture texture = LoadTexture(path.c_str());
   if (texture.id == 0) {
      printf("WARNING: failed to load texture from file '%s'. Using fallback texture.", path.c_str());
      return getFallbackTexture();
   }

   textures.insert({name, texture});
   return textures[name];
}

Font &loadFont(const std::string &name, const std::string &path) {
   if (fonts.count(name)) {
      return fonts[name];
   }

   // Do this to improve the quality of our fonts
   Font font = LoadFontEx(path.c_str(), 120, nullptr, 0);
   SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
   if (font.texture.id == 0) {
      printf("WARNING: failed to load font from file '%s'. Using fallback font.", path.c_str());
      return getFallbackFont();
   }

   fonts.insert({name, font});
   return fonts[name];
}

void loadTextures() {
   std::filesystem::create_directories("assets/sprites/");
   for (const auto &file: std::filesystem::recursive_directory_iterator("assets/sprites/")) {
      if (file.is_regular_file()) {
         loadTexture(file.path().stem().string(), file.path().string());
      }
   }
}

void loadFonts() {
   std::filesystem::create_directories("assets/fonts/");
   for (const auto &file: std::filesystem::recursive_directory_iterator("assets/fonts/")) {
      if (file.is_regular_file()) {
         loadFont(file.path().stem().string(), file.path().string());
      }
   }
}

// Get functions

Texture &getTexture(const std::string &name) {
   if (!textures.count(name)) {
      printf("WARNING: texture '%s' does not exist. Using fallback texture.", name.c_str());
      return getFallbackTexture();
   }
   return textures[name];
}

Font &getFont(const std::string &name) {
   if (!fonts.count(name)) {
      printf("WARNING: font '%s' does not exist. Using fallback font.", name.c_str());
      return getFallbackFont();
   }
   return fonts[name];
}
