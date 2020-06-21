#pragma once

#include <morda/widgets/group/pile.hpp>

namespace morda{

class Page;

class PageStack :
		private pile,
		public virtual widget
{
	friend class Page;
	
	std::vector<std::shared_ptr<Page>> pages;
public:
	PageStack(std::shared_ptr<morda::context> c, const puu::forest& desc);
	
	PageStack(const PageStack&) = delete;
	PageStack& operator=(const PageStack&) = delete;
	
	void push(std::shared_ptr<Page> page);
	
	~PageStack()noexcept;
private:

	void close(Page& page)noexcept;
};

}
