#include <NoesisGUI.h>

class MyNsTest : public Noesis::Grid
{
public:
	MyNsTest();
	~MyNsTest();
	Noesis::Grid *_title;
	Noesis::Image *_curImage;
	Noesis::Ptr<Noesis::ImageBrush> _brush;
	void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event);
	void MyNsTest::createTitle();

	NS_IMPLEMENT_INLINE_REFLECTION(MyNsTest, Noesis::Grid)
	{
		NsMeta<Noesis::TypeId>("MyNsTest");
		NsProp("Brush", &MyNsTest::_brush);
	}
};