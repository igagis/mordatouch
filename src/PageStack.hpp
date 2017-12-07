#pragma once

#include <morda/widgets/core/container/Pile.hpp>

namespace morda{

class Page;

class PageStack :
		private Pile,
		public virtual Widget
{
	friend class Page;
	
	std::vector<std::shared_ptr<Page>> pages;
public:
	PageStack(const stob::Node* chain = nullptr);
	
	PageStack(const PageStack&) = delete;
	PageStack& operator=(const PageStack&) = delete;
	
	void push(std::shared_ptr<Page> page);
	
	~PageStack()noexcept;
private:

	void close(Page& page)noexcept;
};

}
