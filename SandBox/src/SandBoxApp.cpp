#include<ForgeCraft.h>



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

