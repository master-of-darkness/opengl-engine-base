//
// Created by an on 03.03.24.
//

#include "Texture.h"
using namespace cppzt::utils;

void Texture::bind(){
    glBindTexture(GL_TEXTURE_2D, id);
}
