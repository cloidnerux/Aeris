//System.h
//Header, der AlleFunktionen aller Header Bereitstellt
#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "types.h"
#include "video.h"
#include "stdio.h"
#include "gdt.h"
#include "keyboard.h"
#include "interrupt.h"
#include "memory.h"
#include "hardwareIO.h"
#include "console.h"
#include "orderdList.h"


#ifndef TRUE
   #define TRUE  1 //für typedefs und sonstiges zeug wie dieses gibbet es übrigends normalerweise eine types.h ;)
#endif
#ifndef FALSE
   #define FALSE 0 //Nützt zwar nicht viel, macht den Code aber übersichtlicher
#endif

#ifndef DEBUG
   #define DEBUG
#endif

#define FP_OFF(fptr)	((unsigned)(fptr))

#define FP_SEG(fptr) ((unsigned)((unsigned long)(fptr) >> 16))

#define io_wait()                  asm("jmp 1f;1:jmp 1f;1:")

/// Gibt eine Warnmeldung aus und hält das System an.
/// \param file Der Name der Datei in der der Fehler generiert wurde
/// \param line Die Linie in der der Fehler generiert wurde.
/// \param Eine beschreibung des Fehlers.
void PanicAssert(const char *file, u32int line, const char *desc);
#define ASSERT(b) ((b) ? (void)0 : PanicAssert(__FILE__,__LINE__,#b))

/// memset.
/// Setzt einen bestimmten Speicherbereich *p der länge n auf den in c angegeben wert.
/// \param p Die zu bearbeitende Position im Ram
/// \param c Der Wert auf den der Speicherbereich gesetzt werden soll
/// \param n Die Länge des Speicherbereichs
void *memset(void *p, int c, unsigned int n);

/// Aktiviert das A20gate.
/// \return 1 wenn erflogreich
int A20Gate();

/// Initialisiert den Kernel.
/// Ruft alle initmethoden aller Sub-module auf
/// \param maxMem Der Pointer auf den Eintrag über den Maximalen Speicher in der Grub Multiboot Structur
void Init(unsigned int *maxMem);

/// Vergeleicht 2 Strings.
/// Geht Zeichen für Zeichen durch und überprüft ob diese identisch sind
/// \param str1 Der Pointer auf den ersten String
/// \param str2 Der Pointer auf den 2 String
/// \return 1 wenn str1 == str2
int StrComp(char* str1, char* str2);

/// CPU zurücksetzten.
/// Bewirkt einen Neustart
void CPUReset();

/// Gibt die Länge eines Strings an.
/// Zält jedes einzelne Zeichen
/// \param str Der Pointer auf den zu zälenden String
/// \return die Länge des Strings
int StringLength(char *str);


#endif
