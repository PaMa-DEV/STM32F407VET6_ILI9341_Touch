#include <gui/screen_screen/screenView.hpp>

screenView::screenView()
{
	count=0;
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}



void screenView::handleTickEvent()
{

#define wait_Time 60u
	static uint16_t tick=0;
//	count++;
	if (tick++ >= wait_Time )
	{
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",count++);
		textArea1.invalidate();
		tick=0;
	}
}
