#include <NoesisGUI.h>

class MyNsTest : public Noesis::Page
{
public:
	MyNsTest();
	~MyNsTest();
	Noesis::Grid *_title;
	Noesis::Image *_curImage;
	void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event);
	void MyNsTest::createTitle();

	NS_IMPLEMENT_INLINE_REFLECTION(MyNsTest, Noesis::Page)
	{
		NsMeta<Noesis::TypeId>("MyNsTest");
	}
};