#include"fcpch.h"
#include "Application.h"

namespace ForgeCraft {




  void Application::Run() {
    WindowResizeEvent e(1280, 720);
    if (e.IsInCategory(EventCategoryApplication)) {
      FC_TRACE(e.ToString());  // This should work if the formatter specialization is defined correctly
    }
  }



}