#include <morda/Morda.hpp>

#include "PageStack.hpp"

#include "Page.hpp"

using namespace morda;


PageStack::PageStack(const stob::Node* chain) :
		Widget(chain),
		Pile(nullptr)
{
	
}

void PageStack::push(std::shared_ptr<Page> page) {
	if(!page){
		throw morda::Exc("PageStack: tried to push nullptr");
	}
	
	auto& lp = this->getLayoutParams(*page);
	lp.dim.set(Widget::LayoutParams::fill_c);
	
	auto ps = this->sharedFromThis(this);
	
	morda::inst().postToUiThread_ts([ps, page](){
		if(ps->children().size() != 0){
			ASSERT(ps->children().size() == 1)
			auto p = std::dynamic_pointer_cast<Page>(ps->remove(ps->children().begin()));
			ASSERT(p)
			p->onHide();
			ps->pages.push_back(p);
		}

		ps->add(page);
		page->onShow();
	});
}

void PageStack::close(Page& page)noexcept{
	ASSERT(&page.parentPageStack() != this)
	
	for(auto i = this->pages.begin(), e = this->pages.end(); i != e; ++i){
		if((*i).operator->() == &page){
			(*i)->onClose();
			this->pages.erase(i);
			return;
		}
	}
	
	if(this->children().size() == 0){
		return;
	}
	
	ASSERT(this->children().size() == 1)
	auto p = std::dynamic_pointer_cast<Page>(this->remove(this->children().begin()));
	ASSERT(p)
	ASSERT(p.operator->() == &page)
	
	p->onClose();
	
	if(this->pages.size() != 0){
		this->add(this->pages.back());
		this->pages.back()->onShow();
		this->pages.pop_back();
	}
}


PageStack::~PageStack()noexcept{
	if(this->children().size() != 0){
		ASSERT(this->children().size() == 1)
		auto p = std::dynamic_pointer_cast<Page>(this->remove(this->children().begin()));
		ASSERT(p)
		p->onClose();
	}
	
	for(auto i = this->pages.rbegin(), e = this->pages.rend(); i != e; ++i){
		(*i)->onClose();
	}
}
