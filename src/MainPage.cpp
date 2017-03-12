#include <mordavokne/App.hpp>
#include <morda/widgets/button/Button.hpp>

#include "MainPage.hpp"

#include "CubePage.hpp"

MainPage::MainPage() :
		Widget(nullptr),
		Frame(stob::load(*mordavokne::inst().createResourceFileInterface("res/mainPage.gui.stob")).get())
{
	auto b = this->findChildByNameAs<morda::PushButton>("main_button");
	b->clicked = [this](morda::PushButton& b){
		this->parentPageStack().push(utki::makeShared<CubePage>());
	};
}
