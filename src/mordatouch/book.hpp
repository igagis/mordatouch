#pragma once

#include <morda/widgets/group/pile.hpp>

namespace morda{

class page;

class PageStack :
		private pile,
		public virtual widget
{
	friend class page;
	
	std::vector<std::shared_ptr<page>> pages;
public:
	PageStack(std::shared_ptr<morda::context> c, const puu::forest& desc);
	
	PageStack(const PageStack&) = delete;
	PageStack& operator=(const PageStack&) = delete;
	
	void push(std::shared_ptr<page> page);
	
	~PageStack()noexcept;
private:

	void close(page& page)noexcept;
};

}
