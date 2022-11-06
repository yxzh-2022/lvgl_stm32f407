#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "touch.h" 
#include "time.h" 

#include "../../lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "../lv_demos.h"

extern void TIM3_Int_Init(u16 arr,u16 psc);
#define CONFIG_LV_USE_DEMO_STRESS 1
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	TIM3_Int_Init(10-1,8400-1);
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化 
	KEY_Init(); 				//按键初始化  
	
	
	lv_init(); //lvgl 系统初始化
	
  lv_port_disp_init(); //lvgl 显示接口初始化,放在 lv_init()的后面
  lv_port_indev_init(); //lvgl 输入接口初始化,放在 lv_init()的后面
#if 0 
lv_obj_t *label = lv_label_create(lv_scr_act());
 lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_RED),
LV_STATE_DEFAULT);
 lv_obj_set_style_bg_color(lv_scr_act(),lv_palette_main(LV_PALETTE_BLUE),
LV_STATE_DEFAULT);
 lv_obj_set_style_text_font(label,&lv_font_montserrat_14, LV_STATE_DEFAULT);
 lv_label_set_text(label,"Hello Alientek!!!");
#endif 

 //lv_demo_stress();
 //lv_demo_keypad_encoder();
 //lv_demo_music();
 lv_demo_widgets();
 while(1)
 {
	 tp_dev.scan(0);
	 lv_timer_handler(); /* LVGL 管理函数相当于 RTOS 触发任务调度函数 */
	 delay_ms(5);
 }
}
