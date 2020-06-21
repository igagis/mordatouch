#include "PageStack.hpp"

#include <morda/context.hpp>

#include "Page.hpp"

using namespace morda;

PageStack::PageStack(std::shared_ptr<morda::context> c, const puu::forest& desc) :
		widget(std::move(c), desc),
		pile(nullptr, puu::forest())
{}

void PageStack::push(std::shared_ptr<Page> page) {
	if(!page){
		throw std::logic_error("PageStack: tried to push nullptr");
	}
	
	auto& lp = this->get_layout_params(*page);
	lp.dims.set(widget::layout_params::fill);
	
	auto ps = utki::make_shared_from_this(*this);
	
	this->context->run_from_ui_thread([ps, page](){
		if(ps->children().size() != 0){
			ASSERT(ps->children().size() == 1)
			auto p = std::dynamic_pointer_cast<Page>(ps->children().front());
			ASSERT(p)
			ps->erase(ps->children().begin());
			p->onHide();
			ps->pages.push_back(p);
		}

		ps->push_back(page);
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
	auto p = std::dynamic_pointer_cast<Page>(this->children().front());
	ASSERT(p)
	ASSERT(p.operator->() == &page)

	this->erase(this->children().begin());
	
	p->onClose();
	
	if(this->pages.size() != 0){
		this->push_back(this->pages.back());
		this->pages.back()->onShow();
		this->pages.pop_back();
	}
}

PageStack::~PageStack()noexcept{
	if(this->children().size() != 0){
		ASSERT(this->children().size() == 1)
		auto p = std::dynamic_pointer_cast<Page>(this->children().front());
		ASSERT(p)

		this->erase(this->children().begin());

		p->onClose();
	}
	
	for(auto i = this->pages.rbegin(), e = this->pages.rend(); i != e; ++i){
		(*i)->onClose();
	}
}
