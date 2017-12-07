#pragma once

#include <morda/widgets/core/container/Pile.hpp>

#include "Page.hpp"

class MainPage :
		public morda::Page,
		private morda::Pile
{
public:
	MainPage();
	
	MainPage(const MainPage&) = delete;
	MainPage& operator=(const MainPage&) = delete;
	
private:

};
