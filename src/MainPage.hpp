#pragma once

#include <morda/widgets/core/container/Frame.hpp>

#include "Page.hpp"

class MainPage :
		public morda::Page,
		private morda::Frame
{
public:
	MainPage();
	
	MainPage(const MainPage&) = delete;
	MainPage& operator=(const MainPage&) = delete;
	
private:

};
