#pragma once

#include <morda/widgets/group/Pile.hpp>

#include "../../../src/mordatouch/Page.hpp"

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
