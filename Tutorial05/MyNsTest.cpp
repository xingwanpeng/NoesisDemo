#pragma once
#include "pch.h"
#include "MyNsTest.h"
#include "Include\NsGui\UIElementCollection.h"
#include "Include\NsGui\Style.h"
#include <fstream>


using namespace Noesis;

MyNsTest::MyNsTest(){
	this->Initialized() += MakeDelegate(this, &MyNsTest::OnInit);
	Noesis::GUI::LoadComponent(this, "xwp.xaml");
	 _curViewGrid = FindName<Grid>("MyNsTest");
	_title = FindName<Grid>("titleGrid");;
	createTitle();
}

MyNsTest::~MyNsTest(){

}

void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event)
{

}

void MyNsTest::onMouseClick(Noesis::Core::BaseComponent* sender, const Noesis::MouseButtonEventArgs& e)
{
	Noesis::Point curPoint = _curViewGrid->PointFromScreen(e.position);
	_addBtn = *new Noesis::Gui::Button();
	_addBtn->SetBackground(_brush.GetPtr());	
	_addBtn->SetWidth(100);
	_addBtn->SetHeight(100);
	_curViewGrid->GetChildren()->Add(_addBtn.GetPtr());

	/*
	NsSize width =_curViewGrid->GetWidth();
	NsSize height = _curViewGrid->GetHeight();
	Noesis::Drawing::Thickness tmpmargin;
	tmpmargin.left = curPoint.x;
	tmpmargin.top = curPoint.y;
	tmpmargin.bottom = height - curPoint.y - 100;
	tmpmargin.right = width - curPoint.x - 100;
	*/
	Noesis::Drawing::Thickness tmpmargin = this->getMovesMargin(curPoint);
	_addBtn->SetMargin(tmpmargin);

}

void MyNsTest::upState(Noesis::Core::BaseComponent* sender, const Noesis::MouseButtonEventArgs& e)
{

}

void MyNsTest::moveState(Noesis::Core::BaseComponent* sender, const Noesis::MouseEventArgs& e)
{
	if (e.leftButton == MouseButtonState_Pressed) {
		Noesis::Point curPoint = _curViewGrid->PointFromScreen(e.position);
		Noesis::Drawing::Thickness tmpmargin = this->getMovesMargin(curPoint);
		_addBtn->SetMargin(tmpmargin);
	}
}

Noesis::Drawing::Thickness MyNsTest::getMovesMargin(Noesis::Point curPoint)
{
	NsSize width = _curViewGrid->GetWidth();
	NsSize height = _curViewGrid->GetHeight();
	Noesis::Drawing::Thickness tmpmargin;
	tmpmargin.left = curPoint.x;
	tmpmargin.top = curPoint.y;
	tmpmargin.bottom = 220 - curPoint.y;
	tmpmargin.right = 840 - curPoint.x - 100;
	return tmpmargin;
}


void MyNsTest::createTitle()
{
	Noesis::Ptr<Noesis::BitmapImage> image = *new Noesis::BitmapImage("tupian.jpg");
	_brush = *new Noesis::ImageBrush(image.GetPtr());

	Noesis::ResourceDictionary *resource = GetResources();
	Noesis::Gui::Style* cellStyle = resource->FindName<Noesis::Gui::Style>("TitleButtonStyle");
	for (int i = 0; i < 8; ++i) {
		Ptr<Noesis::Gui::Button> btn = *new Noesis::Gui::Button();
		btn->MouseDown() += MakeDelegate(this,&MyNsTest::onMouseClick);
		btn->MouseUp() += MakeDelegate(this, &MyNsTest::upState);
		btn->MouseMove() += MakeDelegate(this, &MyNsTest::moveState);
		btn->SetStyle(cellStyle);
		_title->SetRow(btn.GetPtr(), 0);
		_title->SetColumn(btn.GetPtr(), i);
		_title->GetChildren()->Add(btn.GetPtr());

	}
}


