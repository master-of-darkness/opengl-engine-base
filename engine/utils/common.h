#include "../pch/pch.h"

namespace cppzt::utils::common {
    namespace imgui{
        void Init(GLFWwindow* window);
        void PrepareNewFrame();
        void Destroy();
        void DebugWindow(bool a1);
    }
    namespace event{
        namespace keyboard{
            bool IsPressed(int key);
        }
        namespace mouse{
            // todo
        }
    }
}
