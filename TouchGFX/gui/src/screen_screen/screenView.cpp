#include <gui/screen_screen/screenView.hpp>
#include "main.h"
#include <cstring>
#include "usbd_cdc_if.h"

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
void screenView::Button1Action()
{
	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
}

/*
 * no sys reqmts
 * legarea soft de sysreq
 *
 * */



void screenView::handleTickEvent()
{

#define wait_Time 60u



	static uint16_t tick=0;
	if (tick++ >= wait_Time )
	{
		//		memset(textArea1Buffer, 0 ,TEXTAREA1_SIZE );
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",count++);
		textArea1.resizeToCurrentText();
		textArea1.invalidate();
		tick=0;
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	}
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d  ",tim2_cnt);
	//	if (tim2_cnt<100)
	//		textArea2Buffer[2]=0u;

	static uint16_t old_cnt=0;

	if(old_cnt != tim2_cnt )
	{
		old_cnt=tim2_cnt;

//		Unicode::snprintf(usb_buff,10, "%d\r\n", tim2_cnt);
		 sprintf((char*)usb_buff, "%d\n\r", tim2_cnt);
		CDC_Transmit_FS(usb_buff, 6u);
//		CDC_Transmit_FS("dinRE", 6u);
	}


	textArea2.resizeToCurrentText();
	textArea2.invalidate();


}
