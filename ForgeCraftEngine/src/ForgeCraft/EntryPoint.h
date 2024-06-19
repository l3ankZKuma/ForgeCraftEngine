#pragma once


#ifdef FC_PLATFORM_WINDOWS


extern ForgeCraft::Application* ForgeCraft::CreateApplication();

int main(int argc,char **argv) {



  auto app = ForgeCraft::CreateApplication();
  app->Run();
  delete app;
  
  return 0;
}


#endif 
