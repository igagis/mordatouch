#include "book.hpp"

#include <morda/context.hpp>

#include "page.hpp"

using namespace morda;

book::book(std::shared_ptr<morda::context> c, const puu::forest& desc) :
		widget(std::move(c), desc),
		pile(nullptr, puu::forest())
{}

void book::push(std::shared_ptr<page> pg) {
	if(!pg){
		throw std::logic_error("book: tried to push nullptr");
	}
	
	auto& lp = this->get_layout_params(*pg);
	lp.dims.set(widget::layout_params::fill);
	
	auto ps = utki::make_shared_from_this(*this);
	
	this->context->run_from_ui_thread([ps, pg](){
		if(ps->children().size() != 0){
			ASSERT(ps->children().size() == 1)
			auto p = std::dynamic_pointer_cast<morda::page>(ps->children().front());
			ASSERT(p)
			ps->erase(ps->children().begin());
			p->onHide();
			ps->pages.push_back(p);
		}

		ps->push_back(pg);
		pg->onShow();
	});
}

void book::close(page& pg)noexcept{
	ASSERT(&pg.parentPageStack() != this)
	
	for(auto i = this->pages.begin(), e = this->pages.end(); i != e; ++i){
		if((*i).operator->() == &pg){
			(*i)->onClose();
			this->pages.erase(i);
			return;
		}
	}
	
	if(this->children().size() == 0){
		return;
	}
	
	ASSERT(this->children().size() == 1)
	auto p = std::dynamic_pointer_cast<morda::page>(this->children().front());
	ASSERT(p)
	ASSERT(p.operator->() == &pg)

	this->erase(this->children().begin());
	
	p->onClose();
	
	if(this->pages.size() != 0){
		this->push_back(this->pages.back());
		this->pages.back()->onShow();
		this->pages.pop_back();
	}
}

book::~book()noexcept{
	if(this->children().size() != 0){
		ASSERT(this->children().size() == 1)
		auto p = std::dynamic_pointer_cast<page>(this->children().front());
		ASSERT(p)

		this->erase(this->children().begin());

		p->onClose();
	}
	
	for(auto i = this->pages.rbegin(), e = this->pages.rend(); i != e; ++i){
		(*i)->onClose();
	}
}
