#pragma once


#include"ForgeCraft/Application.h"
#include"ForgeCraft/Log.h"
#include"ForgeCraft/Core/Layer.h"
#include"ForgeCraft/Imgui/ImguiLayer.h"

//---------------------------------
//        |Renderer|

#include"ForgeCraft/Renderer/Renderer.h"
#include"ForgeCraft/Renderer/RendererAPI.h"
#include"ForgeCraft/Renderer/RenderCommand.h"
// Shader
#include <Platform/OpenGL/OpenGLShader.h>

// Vertex Buffer
#include <ForgeCraft/Renderer/Buffer.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

// Vertex Array
#include<ForgeCraft/Renderer/VertexArray.h>
#include<Platform/OpenGL/OpenGLVertexArray.h>

// Renderer
#include <ForgeCraft/Renderer/Renderer.h>
#include <ForgeCraft/Renderer/RenderCommand.h>

//Camera
#include "ForgeCraft/Renderer/Camera/Camera.h"
#include "ForgeCraft/Renderer/Camera/CameraManager.h"
#include "ForgeCraft/Renderer/Camera/Orthographic2DCamera.h"

//---------------------------------




//---------------------------------
//        |Entry Point|
#include"ForgeCraft/EntryPoint.h"
//---------------------------------


