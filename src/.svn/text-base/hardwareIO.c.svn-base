//hardwareIO.c
//by cloidnerux

/// Stellt "out" und "in" Bindings für die entsprechendn ASM-Funktionen zur verfügung.

__inline__ unsigned char
inb (unsigned short int port)
{
  unsigned char _v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

__inline unsigned char
inb_p (unsigned short int port)
{
  unsigned char _v;

  __asm__ __volatile__ ("inb %w1,%0\noutb %%al,$0x80":"=a" (_v):"Nd" (port));
  return _v;
}

__inline unsigned short int
inw (unsigned short int port)
{
  unsigned short _v;

  __asm__ __volatile__ ("inw %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

__inline unsigned short int
inw_p (unsigned short int port)
{
  unsigned short int _v;

  __asm__ __volatile__ ("inw %w1,%0\noutb %%al,$0x80":"=a" (_v):"Nd" (port));
  return _v;
}

__inline unsigned int
inl (unsigned short int port)
{
  unsigned int _v;

  __asm__ __volatile__ ("inl %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

__inline unsigned int
inl_p (unsigned short int port)
{
  unsigned int _v;
  __asm__ __volatile__ ("inl %w1,%0\noutb %%al,$0x80":"=a" (_v):"Nd" (port));
  return _v;
}

__inline void
outb (unsigned char value, unsigned short int port)
{
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (value), "Nd" (port));
}

__inline void
outb_p (unsigned char value, unsigned short int port)
{
  __asm__ __volatile__ ("outb %b0,%w1\noutb %%al,$0x80": :"a" (value),
			"Nd" (port));
}

__inline void
outw (unsigned short int value, unsigned short int port)
{
  __asm__ __volatile__ ("outw %w0,%w1": :"a" (value), "Nd" (port));

}

__inline void
outw_p (unsigned short int value, unsigned short int port)
{
  __asm__ __volatile__ ("outw %w0,%w1\noutb %%al,$0x80": :"a" (value),
			"Nd" (port));
}

 __inline void
outl (unsigned int value, unsigned short int port)
{
  __asm__ __volatile__ ("outl %0,%w1": :"a" (value), "Nd" (port));
}

__inline void
outl_p (unsigned int value, unsigned short int port)
{
  __asm__ __volatile__ ("outl %0,%w1\noutb %%al,$0x80": :"a" (value),
			"Nd" (port));
}

__inline void
insb (unsigned short int port, void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; insb":"=D" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}

__inline void
insw (unsigned short int port, void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; insw":"=D" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}

__inline void
insl (unsigned short int port, void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; insl":"=D" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}

__inline void
outsb (unsigned short int port, const void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; outsb":"=S" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}

__inline void
outsw (unsigned short int port, const void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; outsw":"=S" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}

__inline void
outsl (unsigned short int port, const void *addr, unsigned long int count)
{
  __asm__ __volatile__ ("cld ; rep ; outsl":"=S" (addr),
			"=c" (count):"d" (port), "0" (addr), "1" (count));
}
