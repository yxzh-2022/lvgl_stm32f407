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

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	TIM3_Int_Init(10-1,8400-1);
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ�� 
	KEY_Init(); 				//������ʼ��  
	
	
	lv_init(); //lvgl ϵͳ��ʼ��
	
  lv_port_disp_init(); //lvgl ��ʾ�ӿڳ�ʼ��,���� lv_init()�ĺ���
  lv_port_indev_init(); //lvgl ����ӿڳ�ʼ��,���� lv_init()�ĺ���
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
	 lv_timer_handler(); /* LVGL �������൱�� RTOS ����������Ⱥ��� */
	 delay_ms(5);
 }
}
