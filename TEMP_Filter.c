
#include "StdTypes.h"
#include "SENSORS_Interface.h"
#include "TEMP_Filter_Cfg.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include <util/delay.h>

static u16 TEMP_Filter_TempArr[SAMPLES_NUM];
static u16 TEMP_Filter_FilteredTemp;
static u16 TEMP_Filter_UnFilteredTemp;

void TEMP_Filter_Init(void)
{
	u8 j=0;
	u16 FilterTemp_Init =  SENSORS_GetTEMP();
	TEMP_Filter_UnFilteredTemp = FilterTemp_Init;
	for (j=0;j<SAMPLES_NUM;j++)
	{
		TEMP_Filter_TempArr[j]=FilterTemp_Init;
	}
}

void TEMP_Filter_Runnable(void)
{
	u8 static i=0;
	u8 j=0;
	u16 TempSum=0;
	TEMP_Filter_TempArr[i] = SENSORS_GetTEMP();
	i++;
	
	TEMP_Filter_UnFilteredTemp=TEMP_Filter_TempArr[i];
	if (i==10)
	{
		i=0;
	}
	for (j=0;j<SAMPLES_NUM;j++)
	{
		TempSum+=TEMP_Filter_TempArr[j];
	}
	TEMP_Filter_FilteredTemp=TempSum/SAMPLES_NUM;
}

u16 TEMP_Filter_GetFilteredTemp(void)
{
	return TEMP_Filter_FilteredTemp;
}

u16 TEMP_Filter_GetUnFilteredTemp(void)
{
	return TEMP_Filter_UnFilteredTemp;
}
