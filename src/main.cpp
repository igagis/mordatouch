#include <mordavokne/AppFactory.hpp>
#include <morda/widgets/button/SimpleButton.hpp>



class Application : public mordavokne::App{
	static mordavokne::App::WindowParams GetWindowParams()noexcept{
		mordavokne::App::WindowParams wp(kolme::Vec2ui(320, 480));
		
		return wp;
	}
public:
	Application() :
			App(GetWindowParams())
	{
		morda::Morda::inst().initStandardWidgets(*this->createResourceFileInterface());
		
//		morda::Morda::inst().resMan.mountResPack(*this->createResourceFileInterface("res/"));
//		this->ResMan().MountResPack(morda::ZipFile::New(papki::FSFile::New("res.zip")));
		
//		std::shared_ptr<morda::Widget> c = morda::Morda::inst().inflater.inflate(
//				*this->createResourceFileInterface("res/test.gui.stob")
//			);
//		morda::Morda::inst().setRootWidget(c);
		morda::Morda::inst().setRootWidget(
				morda::inst().inflater.inflate(*stob::parse("PushButton{TextLabel{text{Hello}}}"))
			);
	}
};



std::unique_ptr<mordavokne::App> mordavokne::createApp(int argc, const char** argv, const utki::Buf<std::uint8_t> savedState){
	return utki::makeUnique<Application>();
}
