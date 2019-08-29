#pragma once

#include <morda/widgets/group/Pile.hpp>
#include <morda/Updateable.hpp>

#include "../../../src/mordatouch/Page.hpp"

class CubePage :
		public morda::Page,
		public morda::Pile
{
	std::shared_ptr<morda::Updateable> cube;
public:
	CubePage();
	
	CubePage(const CubePage&) = delete;
	CubePage& operator=(const CubePage&) = delete;
	
	void onShow() override;
	void onHide() override;
	
private:

};

