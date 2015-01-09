//system.c
//Header, der Allefunktionen enthält,die ALgemeibn wichtig sind...

#include "include/system.h"

/// Ein vom Linker gesezter pointer auf das Ende vom Kernel benutzen speichers
unsigned long int __kernel_end;


/// memset.
/// Setzt einen bestimmten Speicherbereich *p der länge n auf den in c angegeben wert.
/// \param p Die zu bearbeitende Position im Ram
/// \param c Der Wert auf den der Speicherbereich gesetzt werden soll
/// \param n Die Länge des Speicherbereichs
void *memset(void *p, int c, unsigned int n)
{
  char *pb = (char *) p;
  char *pbend = pb + n;
  while (pb != pbend) *pb++ = c;
  return p;
} 

/// Aktiviert das A20gate.
/// \return 1 wenn erflogreich
int A20Gate()
{
  int i;
  int outpb;

  while (inb(0x64) & 0x02); 
  outb(0xD0, 0x64);
  for (i = 0; i < 0xFFFF; i++);
  outpb = inb(0x60) | 0x02;
  while (inb(0x64) & 0x02);
  outb(0xD1, 0x64);
  while (inb(0x64) & 0x02);
  outb(outpb, 0x60);
  
  while (inb(0x64) & 0x02); //...
  outb(0xD0, 0x64);
  for (i = 0; i < 0xFFFF; i++);
  if (inb(0x60) & 0x02)
  {
    Printk("A20-Gate wurde erfolgreich aktiviert.\n");
    return 1;
  } else {
    Printk("A20-Gate konnte nicht aktiviert werden.\n");
    return 0;
  }
}

/// Initialisiert den Kernel.
/// Ruft alle initmethoden aller Sub-module auf
/// \param maxMem Der Pointer auf den Eintrag über den Maximalen Speicher in der Grub Multiboot Structur
void Init(unsigned int *maxMem)
{
  ClearScreen();
  A20Gate();
  DisplayTitle();
  GDTInstall();
  IDTInstall();
  IRQInstallHandler(1, KeyboardHandler);
  InitKeyboard();
  InitMemoryBitmap(&__kernel_end, *maxMem + 1);
  InitPaging(&__kernel_end);
  __asm__ __volatile__ ("sti");
}

/// Vergeleicht 2 Strings.
/// Geht Zeichen für Zeichen durch und überprüft ob diese identisch sind
/// \param str1 Der Pointer auf den ersten String
/// \param str2 Der Pointer auf den 2 String
/// \return 1 wenn str1 == str2
int StrComp(char* str1, char* str2)
{
   while(*str1 && *str2)
      {
         if(*str1!=*str2)return 0;
         str1++;
         str2++;
      }
   return 1;
}

/// CPU zurücksetzten.
/// Bewirkt einen Neustart
void CPUReset()
{
      outb(0xFE, 0x64);
}

/// Gibt die Länge eines Strings an.
/// Zält jedes einzelne Zeichen
/// \param str Der Pointer auf den zu zälenden String
/// \return die Länge des Strings
int StringLength(char *str) {
  int i;
  for (i=0;str[i];i++);
  return i;
}

/// Gibt eine Warnmeldung aus und hält das System an.
/// \param file Der Name der Datei in der der Fehler generiert wurde
/// \param line Die Linie in der der Fehler generiert wurde.
/// \param desc Eine beschreibung des Fehlers.
void PanicAssert(const char *file, u32int line, const char *desc)
{
   asm volatile("cli");

   Printf("ASSERTION-FAILED(%s) at %s : %d \n",desc,file,line);
   for(;;);
}
