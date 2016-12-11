#include <NoesisGUI.h>

class MyNsTest : public Noesis::Grid
{
public:
	MyNsTest();
	~MyNsTest();
	Noesis::Grid *_title;
	Noesis::Grid * _curViewGrid;
	Noesis::Ptr<Noesis::Gui::Button> _addBtn;
	Noesis::Ptr<Noesis::ImageBrush> _brush;
	void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event);
	void MyNsTest::createTitle();
	void onMouseClick(Noesis::Core::BaseComponent* sender, const Noesis::MouseButtonEventArgs& e);
	void upState(Noesis::Core::BaseComponent* sender, const Noesis::MouseButtonEventArgs& e);
	void MyNsTest::moveState(Noesis::Core::BaseComponent* sender, const Noesis::MouseEventArgs& e);

	Noesis::Drawing::Thickness MyNsTest::getMovesMargin(Noesis::Point curPoint);

	NS_IMPLEMENT_INLINE_REFLECTION(MyNsTest, Noesis::Grid)
	{
		NsMeta<Noesis::TypeId>("MyNsTest");
		NsProp("BackImage", &MyNsTest::_brush);
	}
};