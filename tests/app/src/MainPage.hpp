#pragma once

#include <morda/widgets/group/pile.hpp>

#include "../../../src/mordatouch/page.hpp"

class MainPage :
		public morda::page,
		private morda::pile
{
public:
	MainPage(std::shared_ptr<morda::context> c);
	
	MainPage(const MainPage&) = delete;
	MainPage& operator=(const MainPage&) = delete;
	
private:

};
