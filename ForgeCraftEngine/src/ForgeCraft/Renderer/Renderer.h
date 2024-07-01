#pragma once



#include<ForgeCraft/Renderer/Buffer.h>
#include<ForgeCraft/Renderer/VertexArray.h>
#include<ForgeCraft/Renderer/RenderCommand.h>

namespace ForgeCraft {
  
	using VAO = VertexArray<OpenGLVertexArray>;



  
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene();
		static void EndScene();

		static void Submit(VAO*  vertexArray);
		//static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		//static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		//static Scope<SceneData> s_SceneData;
	};
}
