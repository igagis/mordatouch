#include <morda/gui.hpp>

#include "page.hpp"


using namespace morda;

PageStack& page::parentPageStack() {
	if(!this->parent()){
		throw std::logic_error("page: the page is not yet shown, i.e. not added to any PageStack");
	}
	auto p = static_cast<PageStack*>(this->parent());
	ASSERT(dynamic_cast<PageStack*>(this->parent()))
	
	return *p;
}

page::page(std::shared_ptr<morda::context> c, const puu::forest& desc) :
		widget(std::move(c), desc)
{}

void page::close()noexcept{
	this->context->run_from_ui_thread([this](){
		this->parentPageStack().close(*this);
	});
}
