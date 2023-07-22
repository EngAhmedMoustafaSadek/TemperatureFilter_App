 


#ifndef TEMP_FILTER_H_
#define TEMP_FILTER_H_



void TEMP_Filter_Init(void);

void TEMP_Filter_Runnable(void);

u16 TEMP_Filter_GetFilteredTemp(void);

u16 TEMP_Filter_GetUnFilteredTemp(void);

#endif /* TEMP_FILTER_H_ */