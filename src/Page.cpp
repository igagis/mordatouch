#include "Page.hpp"


using namespace morda;

PageStack& Page::parentPageStack() {
	if(!this->parent()){
		throw morda::Exc("Page: the page is not yet shown, i.e. not added to any PageStack");
	}
	auto p = static_cast<PageStack*>(this->parent());
	ASSERT(dynamic_cast<PageStack*>(this->parent()))
	
	return *p;
}


Page::Page(const stob::Node* chain) :
		Widget(chain)
{}
