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
	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	pFile = fopen("myfile.bin", "rb");
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (char*)malloc(sizeof(char)*lSize);
	if (buffer == NULL) { fputs("Memory error", stderr); exit(2); }

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("Reading error", stderr); exit(3); }

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(pFile);
	free(buffer);


	Noesis::ResourceDictionary *resource = GetResources();
	Noesis::Gui::Style* cellStyle = resource->FindName<Noesis::Gui::Style>("TitleButtonStle");
	for (int i = 0; i < 8; ++i) {
		Ptr<Noesis::Gui::Button> btn = *new Noesis::Gui::Button();
		btn->SetContent("title");
		btn->SetStyle(cellStyle);
		_title->SetRow(btn.GetPtr(), 0);
		_title->SetColumn(btn.GetPtr(), i);
		_title->GetChildren()->Add(btn.GetPtr());

		Ptr<Noesis::ImageSource> img = Noesis::BitmapSource::Create(300, 300, 0,
			0,  buffer, lSize, 0);
		
	}
}
