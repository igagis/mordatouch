#pragma once

#include <morda/widgets/group/pile.hpp>
#include <morda/updateable.hpp>

#include <morda/widgets/group/book.hpp>

class CubePage :
		public morda::page,
		public morda::pile
{
	std::shared_ptr<morda::updateable> cube;
public:
	CubePage(std::shared_ptr<morda::context> c);
	
	CubePage(const CubePage&) = delete;
	CubePage& operator=(const CubePage&) = delete;
	
	void on_show() override;
	void on_hide()noexcept override;
	
private:

};

