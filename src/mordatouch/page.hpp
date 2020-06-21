#pragma once

#include <morda/widgets/widget.hpp>

#include "book.hpp"

namespace morda{

class page : public virtual widget{
protected:
	page(std::shared_ptr<morda::context> c, const puu::forest& desc);
	
	page(const page&) = delete;
	page& operator=(const page&) = delete;
	
	PageStack& parentPageStack();
public:
	virtual void onShow(){}
	virtual void onHide(){}
	virtual void onClose()noexcept{}
	
	void close()noexcept;
private:

};

}
