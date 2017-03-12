#pragma once

#include <morda/widgets/core/container/Container.hpp>

#include "Page.hpp"

namespace morda{

class PageStack : private Container, public virtual Widget{
public:
	PageStack();
	
	PageStack(const PageStack&) = delete;
	PageStack& operator=(const PageStack&) = delete;
	

private:

};

}
