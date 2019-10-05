#ifndef LCD_PROJECT_VARIABLE_H_
#define LCD_PROJECT_VARIABLE_H_
#include "util.h"
#include "REGISTERS.h"
#include "std_type1.h"
u8 lcd_pass[15]={'E','N','T','E','R',' ','P','A','S','S','W','O','R','D',0};

u8 lcd_user[16]={'E','N','T','E','R',' ','U','S','E','R',' ','N','A','M','E',0};

u8 finish[12]={'P','R','E','S','S',' ','E','N','T','E','R',0};

u8 reenter1[12]={'T','R','Y',' ','A','G','A','I','N','1',0};

u8 reenter2[12]={'T','R','Y',' ','A','G','A','I','N','2',0};

u8 terminate[16]={'T','H','R','E','A','T',' ','D','E','T','E','C','T','E','D',0};

u8 hello[6]={'H','E','L','L','O',0};

u8 temp[11]={'T','E','M','P','R','A','T','U','R','E',0};

u8 temp1[5]={'C','O','L','D',0};

u8 temp2[7]={'N','O','R','M','A','L',0};

u8 temp3[5]={'W','A','R','M',0};

u8 user_id[4]={0} ;
u8 pass_id[4]={0} ;

u8 errors =0 , error_counter =0 ;

u8 i= 0 ;



#endif /*LCD_PROJECT_VARIABLE_H_*/
