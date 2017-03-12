#pragma once

#include <morda/widgets/core/container/Frame.hpp>

namespace morda{

class Page : public Frame{
public:
	Page();
	
	Page(const Page&) = delete;
	Page& operator=(const Page&) = delete;
	
private:

};

}
