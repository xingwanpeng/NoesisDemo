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

	_title = FindName<Grid>("titleGrid");;
	createTitle();
}

MyNsTest::~MyNsTest(){

}

void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event)
{

}

void MyNsTest::createTitle()
{

	Noesis::Ptr<Noesis::BitmapImage> backImage = *new Noesis::BitmapImage("a.jpg");
	

	Noesis::Ptr<Noesis::BitmapImage> image = *new Noesis::BitmapImage("test.jpg");
	
	_brush = *new Noesis::ImageBrush(image.GetPtr());


	Noesis::ResourceDictionary *resource = GetResources();
	Noesis::Gui::Style* cellStyle = resource->FindName<Noesis::Gui::Style>("TitleButtonStyle");
	for (int i = 0; i < 8; ++i) {
		Ptr<Noesis::Gui::Button> btn = *new Noesis::Gui::Button();
		btn->SetContent("title");
		//btn->GetBackground()->SetValueObject(ImageBrush, _brush);
		btn->SetStyle(cellStyle);
		_title->SetRow(btn.GetPtr(), 0);
		_title->SetColumn(btn.GetPtr(), i);
		_title->GetChildren()->Add(btn.GetPtr());

	}
}
