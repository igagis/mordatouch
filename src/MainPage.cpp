#include <mordavokne/App.hpp>
#include <morda/widgets/button/PushButton.hpp>

#include "MainPage.hpp"

#include "CubePage.hpp"

MainPage::MainPage() :
		Widget(nullptr),
		Pile(stob::load(*mordavokne::inst().getResFile("res/mainPage.gui.stob")).get())
{
	auto b = this->findChildByNameAs<morda::PushButton>("main_button");
	b->clicked = [this](morda::PushButton& b){
		this->parentPageStack().push(utki::makeShared<CubePage>());
	};
}
