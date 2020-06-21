#pragma once

#include <morda/widgets/widget.hpp>

#include "book.hpp"

namespace morda{

class page : public virtual widget{
protected:
	page(std::shared_ptr<morda::context> c, const puu::forest& desc);
	
	page(const page&) = delete;
	page& operator=(const page&) = delete;
	
	book& parent_book();
public:
	virtual void on_show(){}
	virtual void on_hide(){}
	virtual void on_close()noexcept{}
	
	void close()noexcept;
private:

};

}
