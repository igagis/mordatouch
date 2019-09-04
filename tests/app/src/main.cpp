#include <mordavokne/AppFactory.hpp>
#include <morda/widgets/button/NinePatchPushButton.hpp>

#include "../../../src/mordatouch/PageStack.hpp"
#include "../../../src/mordatouch/Page.hpp"
#include "MainPage.hpp"


class Application : public mordavokne::App{
	static mordavokne::App::WindowParams GetWindowParams()noexcept{
		mordavokne::App::WindowParams wp(kolme::Vec2ui(320, 480));

		return wp;
	}
public:
	Application() :
			App("mordatouch-test", GetWindowParams())
	{
		morda::inst().initStandardWidgets(*this->getResFile());

		morda::inst().resMan.mountResPack(*this->getResFile("res/"));
//		this->ResMan().MountResPack(morda::ZipFile::New(papki::FSFile::New("res.zip")));

		morda::inst().inflater.addWidget<morda::PageStack>("PageStack");

//		auto c = morda::Morda::inst().inflater.inflate(
//				*this->createResourceFileInterface("res/main.gui.stob")
//			);
		auto ps = utki::makeShared<morda::PageStack>();
		morda::Morda::inst().setRootWidget(ps);

		ps->push(utki::makeShared<MainPage>());

//		morda::Morda::inst().setRootWidget(
//				morda::inst().inflater.inflate(*stob::parse("PushButton{TextLabel{text{Hello}}}"))
//			);
	}
};



std::unique_ptr<mordavokne::App> mordavokne::createApp(int argc, const char** argv){
	return utki::makeUnique<Application>();
}