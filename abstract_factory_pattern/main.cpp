#include <iostream>
class Button{
public:
	virtual void paint() = 0;
};

class WinButton: public Button{
public:
	virtual void paint(){
		std::cout<<"this is win button."<<std::endl;
	}
};

class MacButton: public Button{
public:
	virtual void paint(){
		std::cout<<"this is mac button."<<std::endl;
	} 
};

class ScrollBar{
	virtual void paint() = 0;
};

class WinScrollBar: public ScrollBar{
	virtual	void paint(){
		std::cout<<"this is win scroll bar."<<std::endl;
	}
};

class MacScrollBar: public ScrollBar{
	virtual void paint(){
		std::cout<<"this is mac scroll bar."<<std::endl;
	}
};

class GUIFactory{
public:
virtual Button*  createButton() = 0;
virtual ScrollBar* createScrollBar() = 0;
};

class WinFactory: public GUIFactory{
public:
	virtual Button* createButton(){
		return new WinButton();
	}
};

class MacFactory: public GUIFactory{
public:
	virtual Button* createButton(){
		return new MacButton();
	}
};

int main(){
GUIFactory* factory;
Button* button;
ScrollBar* scrollBar;
factory = new MacFactory;
factory->createButton()->paint();
factor->createScrollBar()->paint();
delete factory;
factory = new WinFactory;
factor->createButton()->paint();
factor->createScrollbar()->paint();
}
