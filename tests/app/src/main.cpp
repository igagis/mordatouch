#include <mordavokne/application.hpp>
#include <morda/widgets/button/nine_patch_push_button.hpp>

#include "../../../src/mordatouch/book.hpp"
#include "../../../src/mordatouch/page.hpp"
#include "MainPage.hpp"


class Application : public mordavokne::application{
	static mordavokne::window_params GetWindowParams()noexcept{
		mordavokne::window_params wp(r4::vec2ui(320, 480));

		return wp;
	}
public:
	Application() :
			application("mordatouch-test", GetWindowParams())
	{
		this->gui.initStandardWidgets(*this->get_res_file());

		this->gui.context->loader.mount_res_pack(*this->get_res_file("res/"));
//		this->ResMan().MountResPack(morda::ZipFile::New(papki::FSFile::New("res.zip")));

		this->gui.context->inflater.register_widget<morda::PageStack>("PageStack");

//		auto c = morda::Morda::inst().inflater.inflate(
//				*this->createResourceFileInterface("res/main.gui.stob")
//			);
		auto ps = std::make_shared<morda::PageStack>(this->gui.context, puu::forest());
		this->gui.set_root(ps);

		ps->push(std::make_shared<MainPage>(this->gui.context));

//		morda::Morda::inst().setRootWidget(
//				morda::inst().inflater.inflate(*stob::parse("PushButton{TextLabel{text{Hello}}}"))
//			);
	}
};

std::unique_ptr<mordavokne::application> mordavokne::create_application(int argc, const char** argv){
	return std::make_unique<Application>();
}
