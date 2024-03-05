//
// Created by an on 03.03.24.
//

#ifndef OPENGL_ENGINE_SHADER_H
#define OPENGL_ENGINE_SHADER_H

namespace cppzt::utils {
    class Shader {
    public:
        // the program ID
        unsigned int ID;

        // constructor reads and builds the shader
        Shader(const char *vertexPath, const char *fragmentPath);

        // use/activate the shader
        void use() const;

        // utility uniform functions
        void setBool(const std::string &name, bool value) const;

        void setInt(const std::string &name, int value) const;

        void setFloat(const std::string &name, float value) const;

        void uniformMatrix(const char *name, glm::mat4 matrix) const;

    private:
        static void checkCompileErrors(unsigned int shader, std::string type) {
            int success;
            char infoLog[1024];
            if (type != "PROGRAM") {
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if (!success) {
                    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog
                              << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            } else {
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if (!success) {
                    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog
                              << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }
    };
}
#endif //OPENGL_ENGINE_SHADER_H
