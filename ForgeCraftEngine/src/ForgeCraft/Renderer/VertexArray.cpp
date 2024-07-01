#include "fcpch.h"
#include "VertexArray.h"


 #include "Platform/OpenGL/OpenGLVertexArray.h"

namespace ForgeCraft {

    OpenGLVertexArray* VertexArray<OpenGLVertexArray>::Create() {
        switch (RendererAPI<OpenGLVertexArray>::GetAPI()) {
        case RendererAPI<OpenGLVertexArray>::API::None:
            FC_CORE_WARN("RendererAPI::None is not supported");
            return nullptr;
        case RendererAPI<OpenGLVertexArray>::API::OpenGL:
            return new OpenGLVertexArray();
        }
        FC_CORE_WARN("Unknown RendererAPI!");
        return nullptr;
    }



}  // namespace ForgeCraft
