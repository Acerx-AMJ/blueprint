#ifndef MNGR_ASSET_HPP
#define MNGR_ASSET_HPP

#include <raylib.h>
#include <string>

// Load functions

Texture &loadTexture(const std::string &name, const std::string &path);
Font &loadFont(const std::string &name, const std::string &path);

void loadTextures();
void loadFonts();

// Get functions

Texture &getTexture(const std::string &name);
Font &getFont(const std::string &name);

#endif
