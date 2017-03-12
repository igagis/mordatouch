#pragma once

#include <morda/widgets/core/Widget.hpp>

#include "PageStack.hpp"

namespace morda{

class Page : public virtual Widget{
protected:
	Page(const stob::Node* chain = nullptr);
	
	Page(const Page&) = delete;
	Page& operator=(const Page&) = delete;
	
	PageStack& parentPageStack();
public:
	virtual void onShow(){}
	virtual void onHide(){}
	virtual void onClose()noexcept{}
private:

};

}
