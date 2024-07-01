#include<ForgeCraft.h>



class Layers : public ForgeCraft::Layer {

  Layers();
  ~Layers() = default;




};




class Sandbox : public ForgeCraft::Application {

public:

  Sandbox() {



  }

  ~Sandbox() {

  }


};



ForgeCraft::Application* ForgeCraft::CreateApplication() {
  return new Sandbox();
}

