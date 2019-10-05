
#ifndef EXTIENUM_H_
#define EXTIENUM_H_

#define ENABLE      1
#define DISABLE     0
#define INT_0       ENABLE
#define INT_1       ENABLE
#define INT_2       DISABLE
typedef enum
{
	LOW_LEVEL_0 ,
	FALLING_EDGE,
	RAISING_EDGE,
	CHANGE
}tenu_Trigger_Level;

typedef struct
{
	tenu_Trigger_Level level ;
}tstrInterruptCfg;

void ExtI0_Init(tstrInterruptCfg *pstrInterruptCfg) ;
void ExtI1_Init(tstrInterruptCfg *pstrInterruptCfg);
void ExtI2_Init(tstrInterruptCfg *pstrInterruptCfg);
void ExtI_Init(void);


#endif  /*EXTIENUM_H_*/

