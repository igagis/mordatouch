#pragma once

#include <morda/widgets/widget.hpp>

#include "PageStack.hpp"

namespace morda{

class Page : public virtual widget{
protected:
	Page(std::shared_ptr<morda::context> c, const puu::forest& desc);
	
	Page(const Page&) = delete;
	Page& operator=(const Page&) = delete;
	
	PageStack& parentPageStack();
public:
	virtual void onShow(){}
	virtual void onHide(){}
	virtual void onClose()noexcept{}
	
	void close()noexcept;
private:

};

}
