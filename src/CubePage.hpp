#pragma once

#include <morda/widgets/core/container/Frame.hpp>
#include <morda/Updateable.hpp>

#include "Page.hpp"

class CubePage : public morda::Page, public morda::Frame{
	std::shared_ptr<morda::Updateable> cube;
public:
	CubePage();
	
	CubePage(const CubePage&) = delete;
	CubePage& operator=(const CubePage&) = delete;
	
	void onShow() override;
	void onHide() override;
	
private:

};

