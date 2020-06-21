#include <morda/gui.hpp>

#include "page.hpp"


using namespace morda;

book& page::parent_book() {
	if(!this->parent()){
		throw std::logic_error("page: the page is not yet shown, i.e. not added to any book");
	}
	auto p = static_cast<book*>(this->parent());
	ASSERT(dynamic_cast<book*>(this->parent()))
	
	return *p;
}

page::page(std::shared_ptr<morda::context> c, const puu::forest& desc) :
		widget(std::move(c), desc)
{}

void page::close()noexcept{
	this->context->run_from_ui_thread([this](){
		this->parent_book().close(*this);
	});
}
