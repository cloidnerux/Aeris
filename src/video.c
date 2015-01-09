//video.c
//Hier sind alle video-funktionen  deklariert

#include "system.h"

short line=3;
short spalte=0;
char *video=(char*)0xB8000;
char color=0x1E;
char clearColor=0x11;


/// Setz die Farbe der console.
/// \param foreground Die Schriftfarbe
/// \param background Die Hintergrundfarbe
void SetColor(char foreground, char background)         //ich nehme nur char da diese nur bis 255 gehen
{
	color = (background<<4) | foreground;
	clearColor=(background<<4)|background;
}

/// Zeigt Oben eine Titelleiste an.
void DisplayTitle()
{
	char* title="Aeris v 0.4 [32-Bit Protected mode] Interrupts + Heap";
	video = (char*)0xB8000;
	char zeichen = '=';
	int i;
	for(i=0;i<320;i++)
	{
		*video=clearColor;
		video++;
	}
	video-=320;
	while(*title)
	{
		*video = *title;
		video++;
		*video = color;
		video++;
		title++;
	}
	video = (char*)0xB8000;
	video+=160;
	for(i=0; i<80; i++)
	{
		*video=zeichen;
        video++;
        *video=color;
        video++;
   }
}

/// Scrolt den Bildschirm.
/// \param lines Anzahl an linien die geScrollt werden soll
void Scroll(int lines)
{
	int i;
	int a;
	video = (char*)0xB8000;
	char *video2 = (char*)0xB80A0;
	for(a=0;a<lines;a++)
    {
		for(i=0;i<3840;i++)
        {
			*video=*video2;
            video++;
            video2++;
        }
        for(i=0;i<160;i++)
        {
			*video=clearColor;
            video++;
        }
    }
	DisplayTitle();
}

/// Ein Zeichen ausgeben.
/// \param zeichen Das auszuegbende zeichen
void PutChr(char zeichen)
{
if(zeichen == '\n')      //Wenn man in die Nächste zeile springen soll
   {
      ++line;      //In die nächste Zeile
      spalte = 0;      //Man ist amanfang der Nächsten zeile
      if(line >= 25)      //Wenn man in derLezten zeile ist
	{
	   Scroll(1);
	   line=25;
	}
   }
else if(zeichen == '\r')
   {
      if(spalte == 0)
      {
         --line;
         spalte = 80;
		 video = (char*)0xB8000;
         video += ((spalte * 2) + (line - 1) * 160);
         video++;
         *video = clearColor;
      }
      else
      {
		  --spalte;
		  video = (char*)0xB8000;
		  video += ((spalte * 2) + 160 * (line - 1));
		  video++;
		  *video = clearColor;
      }
   }
else 
   {   
      if(spalte >= 80)
      {
         ++line;
         spalte = 0;
      }
      video = (char*)0xB8000;
      video += (((line - 1) * 160) + (spalte * 2));
      *video=zeichen;
      video++;
      *video=color;
      ++spalte;
   }
}

/// Simple Funktion zum Ausgeben von Text.
/// \param msg Die Naricht die ausgegben werden soll.
void Printk(char *msg)
{
while(*msg)
   {
      PutChr(*msg);
      msg++;
   }
}

/// Gibt einen String in weißer Farbe aus, der aber nur angezeigt wird, solange
/// das Debugflag gesetzt ist.
/// \param format Der String der Ausgegben werden soll
void PrintDebug(const char *format, ...)
{
#ifdef DEBUG
	color=0x1F;
	register int *varg = (int *)(&format);
	Print(0, varg);
	color=0x1E;
#endif
}

/// Gibt einen grünen Text aus.
/// \param msg Die Naricht die ausgegben werden soll.
void PrintSuccessful(char *msg)
{
	color=0x12;
	while(*msg)
	{
		PutChr(*msg);
		msg++;
	}
	color=0x1E;
}

/// Gibt einen roten String aus.
/// \param msg Die Naricht die ausgegben werden soll.
void PrintFailed(char *msg)
{
	color=0x1C;
	while(*msg)
	{
		PutChr(*msg);
		msg++;
	}
	color=0x1E;
}

/// Löscht allen Bildschriminhalt.
void ClearScreen()
{
	video = (char*)0xB8000;
	for(video += 4000; video != (char*)0xB8000 ; video--)
	{
		*video=clearColor;
	}
	line=3;
	DisplayTitle();
}

/*void displaycursor(char col,char row) {
   short int tmp;
   tmp = row*80+col;
   outw(0x3D4,14);
   outw(0x3D5,tmp>>8);
   outw(0x3D4,15);
   outw(0x3D5,tmp);
 }*/



/*
//
////////////////////////////////////////////////////////
//Variablen für die Ansteuerung des Seriellen Anschlusses  by Jside

int cminit = FALSE;
int enable = FALSE;
int baudlow, baud, port;
int bauds[5] = {2400, 4600, 9600, 19200, 38400 };

//
//////////////////////////////////////////////////////////
//Funktionen zum ANsteuern des Seriellen Anschlusses  by Jside

int init_port(int val, int portr, int baudr) {
    if(!portr) return 0;
    port = portr;
    baudlow = bauds[baudr];
    if(!baudr) baudlow = 9600; 
    baud = 115200/baudlow;
      outb(port+1,0x00); // no interrupts
      outb(port+3,0x80);
      outb(port+0,baud); // Baudrate
      outb(port+1,baud>>8); // Baudrate
      outb(port+3,0x03); // 8 Bits, 1 stopbit
      outb(port+2,0xC7);
      outb(port+4,0x0B);
      cminit = TRUE;
      if(val) enable = 1;
      return 1;
}

void comen(int an) {
     enable = an;
}

int prop() {
  int i;
  i = inb(port+5)&0x20;
  return i;
}
void charsend(char a) {
  if(!cminit) return;
  while (!prop());
  outb(port,a);
}

*/