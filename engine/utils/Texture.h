//
// Created by an on 03.03.24.
//

#ifndef OPENGL_ENGINE_TEXTURE_H
#define OPENGL_ENGINE_TEXTURE_H

namespace cppzt::utils{
    class Texture {
    public:
        Texture(unsigned int id, int width, int height) : id(id), width(width), height(height) {};
        ~Texture() { glDeleteTextures(1, &id); };
        void bind();


        unsigned int id;
        int width;
        int height;
    private:

    };
}


#endif //OPENGL_ENGINE_TEXTURE_H
