#pragma once
#include "pch.h"
#include "MyNsTest.h"
#include "Include\NsGui\UIElementCollection.h"
#include "Include\NsGui\Style.h"
using namespace Noesis;

MyNsTest::MyNsTest(){
	this->Initialized() += MakeDelegate(this, &MyNsTest::OnInit);
	Noesis::GUI::LoadComponent(this, "xwp.xaml");

	_title = FindName<Grid>("titleGrid");
	createTitle();
}

MyNsTest::~MyNsTest(){

}

void MyNsTest::OnInit(Noesis::BaseComponent *sender, const Noesis::EventArgs& event)
{

}

void MyNsTest::createTitle()
{
	Noesis::ResourceDictionary *resource = GetResources();
	Noesis::Gui::Style* cellStyle = resource->FindName<Noesis::Gui::Style>("Button");
	for (int i = 0; i < 10; ++i) {
		Ptr<Noesis::Gui::Label> cell = *new Noesis::Gui::Label();
		cell->SetContent("title");
		cell->SetStyle(cellStyle);
		_title->SetRow(cell.GetPtr(), 0);
		_title->SetColumn(cell.GetPtr(), 0);
		_title->GetChildren()->Add(cell.GetPtr());
	}
}
