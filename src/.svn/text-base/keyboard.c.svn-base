//keyboard.c
//deklariert alle keyboardfunktionen


#include "include/system.h"

char zeichenBuffer;

char key_map[90];
struct keyboard_flags flags;

///Änderungen:
/// outb-Reihenfolge
int SelbstTest()                  //Testet die tastatur 1:OK 0:Fehler
{
	int status;
	while(inb(0x64)&0x02);
	outb(0xAA, 0x64);
	status=inb(0x60);
	if(status == 0x55)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///Änderungen:
/// outb-Reihenfolge
void DisableKeyboard()
{
	while(inb(0x64)&0x02);
	outb(0xAD, 0x64);
}

///Änderungen:
/// outb-Reihenfolge
void EnableKeyboard()
{
	while(inb(0x64)&0x02);
	outb(0xAE, 0x64);
}

void InitKeyboard()
{
	int i=0;
	Printf("Init Keyborad!\n");
	char *fehler="Fehler beim Initialiseren der Tastatur";
    EnableKeyboard();
    key_map[i++]='~';
    key_map[i++]='1';
    key_map[i++]='2';
    key_map[i++]='3';
    key_map[i++]='4';
    key_map[i++]='5';
    key_map[i++]='6';
    key_map[i++]='7';
    key_map[i++]='8';
    key_map[i++]='9';
    key_map[i++]='0';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='q';
    key_map[i++]='w';
    key_map[i++]='e';
    key_map[i++]='r';
    key_map[i++]='t';
    key_map[i++]='z';
    key_map[i++]='u';
    key_map[i++]='i';
    key_map[i++]='o';
    key_map[i++]='p';
    key_map[i++]='u';
    key_map[i++]='+';
    key_map[i++]='\n';
    key_map[i++]='~';
    key_map[i++]='a';
    key_map[i++]='s';
    key_map[i++]='d';
    key_map[i++]='f';
    key_map[i++]='g';
    key_map[i++]='h';
    key_map[i++]='j';
    key_map[i++]='k';
    key_map[i++]='l';
    key_map[i++]='o';
    key_map[i++]='a';
    key_map[i++]='^';
    key_map[i++]='~';
    key_map[i++]='#';
    key_map[i++]='y';
    key_map[i++]='x';
    key_map[i++]='c';
    key_map[i++]='v';
    key_map[i++]='b';
    key_map[i++]='n';
    key_map[i++]='m';
    key_map[i++]=',';
    key_map[i++]='.';
    key_map[i++]='-';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]=' ';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='7';
    key_map[i++]='8';
    key_map[i++]='9';
    key_map[i++]='-';
    key_map[i++]='4';
    key_map[i++]='5';
    key_map[i++]='6';
    key_map[i++]='+';
    key_map[i++]='1';
    key_map[i++]='2';
    key_map[i++]='3';
    key_map[i++]='0';
    key_map[i++]=',';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    key_map[i++]='~';
    
	flags.shift = 0;
    flags.lock = 0;
    flags.strg = 0;
    flags.alt = 0;
    
	zeichenBuffer=0;
    
	if(!SelbstTest())
    {
		Printk(fehler);
		DisableKeyboard();
		EnableKeyboard();
    }
    PrintSuccessful("   Done.\n");
}

char GetScancode()
{
	char scancode;
	scancode = inb(0x60);
	return scancode;
}

///Änderungen:
/// outb-Reihenfolge
void Led(char num, char lock, char scroll)
{
	char erg=(0x01*scroll)+(0x02*num)+(0x04*lock);
	outb(0xED, 0x60);
	while(inb(0x64)&0x02);
	outb(erg, 0x60);
}

///Änderungen:
/// "Tastaturhandler aufgerufen!" war ja nur zu Debug-Zwecken, oder?
/// Ein bisschen neu formatiert
/// KeyUp und KeyDown "vereinfacht"
void KeyboardHandler(struct regs *r)
{
	unsigned char buffer;
	char keyDown;
  
	buffer = GetScancode();
	keyDown = ((buffer & 0x80) >> 7) ^ 1; //Ist praktischer als ein "KeyUp"
	buffer &= 0x7F;
	switch (buffer)
	{
		case (LSHIFT):
    	case (RSHIFT):
			flags.shift = keyDown;
			break;
		case (LOCK):
			flags.lock ^= 1; //Status wehcseln
			Led(0, 1, 0);
			break;
		case (CTRL):
			flags.shift = keyDown;
			break;
		case (ALT):
			flags.alt = keyDown;
			break;
		case (BACKSPACE):
			PutChr('\r');
			break;
    default:
		if (keyDown && (buffer > 0) && (buffer < 92))
		{
			buffer = key_map[buffer-1]; //Speichert jetzt das entsprechende ASCII-Zeichen in "buffer"
			if (buffer == 0)
			{
				buffer = 'x';
			}
			if (buffer != '|')
			{
				if (flags.lock)
				{
					if (!flags.shift)
						buffer -= 32;
				}
				else if (flags.shift)
				{
					buffer -= 32;
				}
			}
			zeichenBuffer = buffer;
			PutChr(zeichenBuffer);
		}
	}
}


void GetString(char *targetVar)
{
	while(1)
	{
		if(zeichenBuffer!=0)
		{
			if(zeichenBuffer=='\n')
			{
				zeichenBuffer=0;
				break;
			}
			if(zeichenBuffer=='\r')
			{
				--targetVar;
				targetVar=0;
				PutChr(zeichenBuffer);
				zeichenBuffer=0;
				continue;
			}
			//PutChr(zeichenBuffer);
			*targetVar=zeichenBuffer;
			targetVar++;
			zeichenBuffer=0;
		}
	}
}


 
