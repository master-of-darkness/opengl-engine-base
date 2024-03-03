//Pre-compiled headers
#include <iostream>
#include <fstream>
#include <sstream>

#define GLFW_INCLUDE_GLU
// OpenGL, GLFW, GLM
#include <GLES3/gl32.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ImGui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
