#include<ForgeCraft.h>

class ExampleLayer : public ForgeCraft::Layer {

public:

  ExampleLayer()
    : Layer("Example") {

  }

  ~ExampleLayer() = default;

  void OnUpdate() override {
    FC_INFO("ExampleLayer::Update");
  }

  void OnEvent(ForgeCraft::Event& event) override {
    FC_TRACE("{0}", event.ToString());
  }


};



class Sandbox : public ForgeCraft::Application {

public:

  Sandbox() {


    PushLayer(new ExampleLayer());
    PushOverlay(new ForgeCraft::ImguiLayer());

  }

  ~Sandbox() {

  }


};



ForgeCraft::Application* ForgeCraft::CreateApplication() {
  return new Sandbox();
}

