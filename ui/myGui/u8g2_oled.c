
//----------------------------------------------------------------
//              VCC  ��5V��3.3v��Դ
//              GND  ��Դ��
//              D1   ��PB15��SDI��
//              D0   ��PB13��SCL��
//              CS   ��PB12 Ƭѡ    
//              RST  ��PB14 ϵͳ��λ
//              DC   ��PB1  ����/����  
//              NC   ����                     
//----------------------------------------------------------------
//******************************************************************************/
#include "u8g2_oled.h"
#include "stdio.h"
#include "u8g2_oled_font.h"
#include "spi.h"
#include "u8g2.h"
#include "u8x8.h"
#include "menu.h"

u8g2_t u8g2; // ��ʾ����ʼ���ṹ��
 
 
uint8_t u8x8_byte_4wire_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,void *arg_ptr)
{
    switch (msg)
    {
        case U8X8_MSG_BYTE_SEND: /*ͨ��SPI����arg_int���ֽ�����*/
//          HAL_SPI_Transmit_DMA(&hspi1, (uint8_t *)arg_ptr, arg_int);while(hspi1.TxXferCount);
			//ʹ��DMA���Խ������ע�ͽ���������治��DMA�ĸ�ע�͵�
			HAL_SPI_Transmit(&hspi2,(uint8_t *)arg_ptr,arg_int,200);
            break;
        case U8X8_MSG_BYTE_INIT: /*��ʼ������*/
            break;
        case U8X8_MSG_BYTE_SET_DC: /*����DC����,�������͵������ݻ�������*/
			HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin,arg_int);
            break;
        case U8X8_MSG_BYTE_START_TRANSFER: 
            u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_enable_level);
            u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO, u8x8->display_info->post_chip_enable_wait_ns, NULL);
            break;
        case U8X8_MSG_BYTE_END_TRANSFER: 
            u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO, u8x8->display_info->pre_chip_disable_wait_ns, NULL);
            u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_disable_level);
            break;
        default:
            return 0;
    }
    return 1;
}
 
uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,
    U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
    U8X8_UNUSED void *arg_ptr) 
{
    switch (msg)
    {
        case U8X8_MSG_GPIO_AND_DELAY_INIT: /*delay��GPIO�ĳ�ʼ������main���Ѿ���ʼ�������*/
            break;
        case U8X8_MSG_DELAY_MILLI: /*��ʱ����*/
            HAL_Delay(arg_int);     //����˭stm32ϵͳ��ʱ����
            break;
        case U8X8_MSG_GPIO_CS: /*Ƭѡ�ź�*/ //����ֻ��һ��SPI�豸������Ƭѡ�ź��ڳ�ʼ��ʱ�Ѿ�����ΪΪ����Ч
            HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, arg_int);
            break;
        case U8X8_MSG_GPIO_DC: /*����DC����,�������͵������ݻ�������*/
            HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin,arg_int);
            break;
        case U8X8_MSG_GPIO_RESET:
            break;
    }
    return 1;
}
 
 /********************************************     
U8G2_R0     //����ת��������     
U8G2_R1     //��ת90��
U8G2_R2     //��ת180��   
U8G2_R3     //��ת270��
U8G2_MIRROR   //û����ת��������ʾ���Ҿ���
U8G2_MIRROR_VERTICAL    //û����ת��������ʾ����
********************************************/
void u8g2Init(u8g2_t *u8g2)
{
	MD_OLED_RST_Set(); //��ʾ����λ����
	u8g2_Setup_ssd1306_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_hw_spi,             
    u8x8_stm32_gpio_and_delay);  // ��ʼ��0.96��OLED u8g2 �ṹ��
	u8g2_InitDisplay(u8g2);     //��ʼ����ʾ
	u8g2_SetPowerSave(u8g2, 0); //������ʾ
}

void draw(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2); 
	
    u8g2_SetFontMode(u8g2, 1); /*����ģʽѡ��*/
    u8g2_SetFontDirection(u8g2, 0); /*���巽��ѡ��*/
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf); /*�ֿ�ѡ��*/
    u8g2_DrawStr(u8g2, 0, 20, "U");
    
    u8g2_SetFontDirection(u8g2, 1);
    u8g2_SetFont(u8g2, u8g2_font_inb30_mn);
    u8g2_DrawStr(u8g2, 21,8,"8");
        
    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
    u8g2_DrawStr(u8g2, 51,30,"g");
    u8g2_DrawStr(u8g2, 67,30,"\xb2");
    
    u8g2_DrawHLine(u8g2, 2, 35, 47);
    u8g2_DrawHLine(u8g2, 3, 36, 47);
    u8g2_DrawVLine(u8g2, 45, 32, 12);
    u8g2_DrawVLine(u8g2, 46, 33, 12);
  
    u8g2_SetFont(u8g2, u8g2_font_4x6_tr);
    u8g2_DrawStr(u8g2, 1,54,"github.com/olikraus/u8g2");
		
	u8g2_SendBuffer(u8g2);
}
/********************************* end_of_file **********************************/
void u8g2_proc(void)
{
	//��ʾ����
   u8g2_FirstPage(&u8g2);
   do
   {
		draw(&u8g2);
   } while (u8g2_NextPage(&u8g2));

}

void u8g2_init(void)
{
	u8g2Init(&u8g2);
}