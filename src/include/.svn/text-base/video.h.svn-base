//video.h
#ifndef VIDEO_H_
#define VIDEO_H_

/// Setz die Farbe der console
/// \param foreground Die Schriftfarbe
/// \param background Die Hintergrundfarbe
void SetColor(char foreground, char background);

/// Zeigt Oben eine Titelleiste an
void DisplayTitle();

/// Scrolt den Bildschirm
/// \param lines Anzahl an linien die gescrollt werden soll
void Scroll(int lines);

/// Ein Zeichen ausgeben
/// \param zeichen Das auszuegbende zeichen
void PutChr(char zeichen);

/// Simple Funktion zum Ausgeben von Text
/// \param msg Die Naricht die ausgegben werden soll.
void Printk(char *msg);

/// Gibt einen String in weißer Farbe aus, der aber nur angezeigt wird, solange
/// das Debugflag gesetzt ist.
/// \param format Der String der Ausgegben werden soll
void PrintDebug(const char *format, ...);

/// Gibt einen grünen Text aus
/// \param msg Die Naricht die ausgegben werden soll.
void PrintSuccessful(char *msg);

/// Gibt einen roten String aus
/// \param msg Die Naricht die ausgegben werden soll.
void PrintFailed(char *msg);

/// Löscht allen Bildschriminhalt
void ClearScreen();

/*
int InitPort(int val, int portr, int baudr);
void Comen(int an);
int Prop();
void CharSend(char a);*/

#endif
