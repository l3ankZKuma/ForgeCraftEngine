#pragma once


#ifdef FC_PLATFORM_WINDOWS


extern ForgeCraft::Application* ForgeCraft::CreateApplication();

int main(int argc,char **argv) {


  ForgeCraft::Log::Init();

  FC_CORE_WARN("Initialized Log!");

  int a = 5;
  FC_INFO("Hello! Var={0}",a);





  auto app = ForgeCraft::CreateApplication();
  app->Run();
  delete app;
  
  return 0;
}


#endif 
