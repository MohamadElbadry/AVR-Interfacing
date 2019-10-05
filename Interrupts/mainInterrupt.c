#include"ExtIEnum.h"
#include"ExtICfg.h"

int main()
{

	ExtI_Init();
	ExtI0_Init(&strInterrupt0);
	ExtI1_Init(&strInterrupt1);

	while(1)
	{

	}
	return 0 ;
}
