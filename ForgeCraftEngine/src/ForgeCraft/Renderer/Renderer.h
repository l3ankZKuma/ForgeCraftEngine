#pragma once



#include<ForgeCraft/Renderer/Buffer.h>
#include<ForgeCraft/Renderer/VertexArray.h>
#include<ForgeCraft/Renderer/RenderCommand.h>
#include<ForgeCraft/Renderer/Camera/Orthographic2DCamera.h>

#include<Platform/OpenGL/OpenGLShader.h>

namespace ForgeCraft {
  
	using VAO = VertexArray<OpenGLVertexArray>;



  
	class Renderer
	{
	public:
		static void Init( );
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(const Orthographic2DCamera& camera);
		static void EndScene();

		static void Submit(VAO*  vertexArray,OpenGLShader * shader);
		//static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		//static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		inline static SceneData* s_SceneData = new SceneData;

	};
}
