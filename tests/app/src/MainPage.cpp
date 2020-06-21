#include <mordavokne/application.hpp>
#include <morda/widgets/button/push_button.hpp>

#include "MainPage.hpp"

#include "CubePage.hpp"

MainPage::MainPage(std::shared_ptr<morda::context> c) :
		widget(std::move(c), puu::forest()),
		Page(this->context, puu::forest()),
		pile(this->context, puu::read(*mordavokne::inst().get_res_file("res/mainPage.gui")))
{
	auto& b = this->get_widget_as<morda::push_button>("main_button");
	b.click_handler = [this](morda::push_button& b){
		this->parentPageStack().push(std::make_shared<CubePage>(this->context));
	};
}
