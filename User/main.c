/********************************** (C) COPYRIGHT *******************************
1���¶����Ĳ���0.5-4HZ,���˯��
2�������Ȳ���4-7HZ����˯��ڤ��
3��������������8-13Hz������ڤ��
4�������²���13-30Hz������רע
5��٤���ò���>30HZ����Ϣ����

������7.83hZ��7.5hz��7.2hz

���ߣ�������  wx: dsx2668
2021/06/21
 *******************************************************************************/


#include "debug.h"


/* Global define */


/* Global Variable */
vu8 val;

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 **********************************************************************/

/*����Ƭѡ/ģʽ */
#define SD_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_4,i)    //SD�ź�
#define MODE_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_2,i)    //MODE�ź�
#define IN_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_1,i)       //���������ź�

void AUD_IO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOC, &GPIO_InitStructure );
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    AUD_IO_Init();

    while(1)
    {
        SD_(0);     //0=ON,1=OFF
        MODE_(0);       //1ΪD�࣬0ΪAB��
        IN_(0);
        Delay_Us(112500);    //11111-45Hz/12500-40Hz/14286-35Hz/16666-30hz/64000-7.8hz/42000-12hz
        IN_(1);
        Delay_Us(12500);
    }
}