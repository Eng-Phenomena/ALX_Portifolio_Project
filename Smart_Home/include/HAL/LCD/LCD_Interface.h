/*
 * LCD_Interface.h
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum{
	ROW1=1,
	ROW2
}LCD_ROW_e;

typedef enum{
	COL1=1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16
}LCD_COL_e;

void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidClearDisplay(void);
void HLCD_voidInit(void);
void HLCD_voidGoToPos (LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol);
void HLCD_voidSendString (u8 *A_u8PtrToString);
void LCD_VOID_WRITE_MESSAGE(u8 *message, u8 ROW, u8 COL);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
