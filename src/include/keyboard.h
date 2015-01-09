//keyboard.h
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "interrupt.h" 

#define ESC 0x01
#define DIK_1 0x02
#define DIK_2 0x03
#define DIK_3 0x04
#define DIK_4 0x05
#define DIK_5 0x06
#define DIK_6 0x07
#define DIK_7 0x08
#define DIK_8 0x09
#define DIK_9 0x0A
#define DIK_0 0x0B
#define KEY_SZ 0x0C
#define KEY_KOMMA 0x0D
#define BACKSPACE 0x0E
#define TAB 0x0F
#define KEY_Q 0x10
#define KEY_W 0x11
#define KEY_E 0x12
#define KEY_R 0x13
#define KEY_T 0x14
#define KEY_Z 0x15
#define KEY_U 0x16
#define KEY_I 0x17
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_UE 0x1A
#define KEY_PLUS 0x1B
#define ENTER 0x1C
#define CTRL 0x1D
#define KEY_A 0x1E
#define KEY_S 0x1F
#define KEY_D 0x20
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_OE 0x27
#define KEY_AE 0x28
#define KEY_DACH 0x29
#define LSHIFT 0x2A
#define KEY_RAUTE 0x2B
#define KEY_Y 0x2C
#define KEY_X 0x2D
#define KEY_C 0x2E
#define KEY_V 0x2F
#define KEY_B 0x30
#define KEY_N 0x31
#define KEY_M 0x32
#define KOMMA 0x33
#define KEY_POINT 0x34
#define KEY_LINE 0x35
#define RSHIFT 0x36
#define DRUCK 0x37
#define ALT 0x38
#define SPACE 0x39
#define LOCK 0x3A
#define F1 0x3B
#define F2 0x3C
#define F3 0x3D
#define F4 0x3E
#define F5 0x3F
#define F6 0x40
#define F7 0x41
#define F8 0x42
#define F9 0x43
#define F10 0x44
#define NUM_LOCK 0x45
#define ROLLEN 0x46
#define NUM_7 0x47
#define NUM_8 0x48
#define NUM_9 0x49
#define MINUS 0x4A
#define NUM_4 0x4B
#define NUM_5 0x4C
#define NUM_6 0x4D
#define PLUS 0x4E
#define NUM_1 0x4F
#define NUM_2 0x50
#define NUM_3 0x51
#define NUM_0 0x52
#define EINFUEGEN 0x53
#define F11 0x57
#define F12 0x58

struct keyboard_flags
   {
    short int shift;
    short int lock;
    short int strg;
    short int alt;
};

void InitKeyboard();
void KeyboardHandler(struct regs *r);
void DisableKeyboard();
void EnableKeyboard();
void GetString(char *target_var);

#endif
