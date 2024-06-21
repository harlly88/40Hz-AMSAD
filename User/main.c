/********************************** (C) COPYRIGHT *******************************
1、德尔塔δ波，0.5-4HZ,深度睡眠
2、西塔θ波，4-7HZ，轻睡眠冥想
3、阿尔法α波，8-13Hz，放松冥想
4、贝塔β波，13-30Hz，清醒专注
5、伽马γ波，>30HZ，信息处理

舒曼波7.83hZ，7.5hz，7.2hz

作者：都市熊  wx: dsx2668
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

/*功放片选/模式 */
#define SD_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_4,i)    //SD信号
#define MODE_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_2,i)    //MODE信号
#define IN_(i) GPIO_WriteBit(GPIOC,GPIO_Pin_1,i)       //阿尔法波信号

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
        MODE_(0);       //1为D类，0为AB类
        IN_(0);
        Delay_Us(14286);    //11111-45Hz/12500-40Hz/14286-35Hz/16666-30hz/64000-7.8hz/42000-12hz
        IN_(1);
        Delay_Us(14286);
    }
}
