/// hardwareIO.h
/// by clodinerux

#ifndef HARDWARE_IO_H
#define HARDWARE_IO_H

__inline__ unsigned char
inb (unsigned short int port);
__inline unsigned char
inb_p (unsigned short int port);
__inline unsigned short int
inw (unsigned short int port);
__inline unsigned short int
inw_p (unsigned short int port);
__inline unsigned int
inl (unsigned short int port);
__inline unsigned int
inl_p (unsigned short int port);
__inline void
outb (unsigned char value, unsigned short int port);
__inline void
outb_p (unsigned char value, unsigned short int port);
__inline void
outw (unsigned short int value, unsigned short int port);
__inline void
outw_p (unsigned short int value, unsigned short int port);
__inline void
outl (unsigned int value, unsigned short int port);
__inline void
outl_p (unsigned int value, unsigned short int port);
__inline void
insb (unsigned short int port, void *addr, unsigned long int count);

#endif
