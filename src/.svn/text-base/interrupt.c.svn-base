//Stellt Alle Interruptfunktionen bereit.
//interrupt.c 

#include "include/system.h"

/// Setzt die Intterrupthandler für Die ISRS.
/// ISRS sind Toutinen die Fehler wie 2Divide by Zero" behandeln.
void ISRSInstall()
{
    IDTSetGate(0, (unsigned)isr0, 0x08, 0x8E);
    IDTSetGate(1, (unsigned)isr1, 0x08, 0x8E);
    IDTSetGate(2, (unsigned)isr2, 0x08, 0x8E);
    IDTSetGate(3, (unsigned)isr3, 0x08, 0x8E);
    IDTSetGate(4, (unsigned)isr4, 0x08, 0x8E);
    IDTSetGate(5, (unsigned)isr5, 0x08, 0x8E);
    IDTSetGate(6, (unsigned)isr6, 0x08, 0x8E);
    IDTSetGate(7, (unsigned)isr7, 0x08, 0x8E);

    IDTSetGate(8, (unsigned)isr8, 0x08, 0x8E);
    IDTSetGate(9, (unsigned)isr9, 0x08, 0x8E);
    IDTSetGate(10, (unsigned)isr10, 0x08, 0x8E);
    IDTSetGate(11, (unsigned)isr11, 0x08, 0x8E);
    IDTSetGate(12, (unsigned)isr12, 0x08, 0x8E);
    IDTSetGate(13, (unsigned)isr13, 0x08, 0x8E);
    IDTSetGate(14, (unsigned)isr14, 0x08, 0x8E);
    IDTSetGate(15, (unsigned)isr15, 0x08, 0x8E);

    IDTSetGate(16, (unsigned)isr16, 0x08, 0x8E);
    IDTSetGate(17, (unsigned)isr17, 0x08, 0x8E);
    IDTSetGate(18, (unsigned)isr18, 0x08, 0x8E);
    IDTSetGate(19, (unsigned)isr19, 0x08, 0x8E);
    IDTSetGate(20, (unsigned)isr20, 0x08, 0x8E);
    IDTSetGate(21, (unsigned)isr21, 0x08, 0x8E);
    IDTSetGate(22, (unsigned)isr22, 0x08, 0x8E);
    IDTSetGate(23, (unsigned)isr23, 0x08, 0x8E);

    IDTSetGate(24, (unsigned)isr24, 0x08, 0x8E);
    IDTSetGate(25, (unsigned)isr25, 0x08, 0x8E);
    IDTSetGate(26, (unsigned)isr26, 0x08, 0x8E);
    IDTSetGate(27, (unsigned)isr27, 0x08, 0x8E);
    IDTSetGate(28, (unsigned)isr28, 0x08, 0x8E);
    IDTSetGate(29, (unsigned)isr29, 0x08, 0x8E);
    IDTSetGate(30, (unsigned)isr30, 0x08, 0x8E);
    IDTSetGate(31, (unsigned)isr31, 0x08, 0x8E);
}

/// Ein Array an Fehlermessages, um den Fehlergrund auszugeben. 
char *exceptionMessages[32] =
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoin Exeption",
	"Into Detected Overflow Exception",
	"Out of Bounds Exception",
	"Invalid Opcode Exception",
 	"No Coprocessor Exception",
 	"Double Fault Exception",
 	"Coprocessor Segment Overrun Exception",
 	"Bad TSS Exception",
 	"Segment Not Present Exception",
 	"Stack Fault Exception",
 	"General Protection Fault Exception",
 	"Page Fault Exception",
 	"Unknown Interrupt Exception",
 	"Coprocessor Fault Exception",
 	"Alignment Check Exception (486+)",
 	"Machine Check Exception (Pentium/586+)",
    "Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
    "Reserved"
};


/// Richtet den Interruptcontroller ein.
/// Dieser Steuert den Hardwaremäsigen aufruf von Interrutps.
void SetPic()
{
	outb(0x11, 0x20);
	outb(0x11, 0xA0);
	outb(0x20, 0x21);
	outb(0x28, 0xA1);
	outb(0x04, 0x21);
	outb(0x02, 0xA1);
	outb(0x01, 0x21);
	outb(0x01, 0xA1);
	outb(0x00, 0x21);
	outb(0x00, 0xA1);      
}

/// Ein Array an Funktionspointern zu Routinen die im falle eines 
/// Hardwareinterrupts aufgerufen werden sollen.
void *irqRoutines[16] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

/// Weißt einem Hardwareinterrupt einen bestimmten Handler zu.
/// \param irq Die Nummer des Handlers(0 - 13).
/// \param handler Der Pointer zu der Entsprechenden Funktion.
void IRQInstallHandler(int irq, void (*handler)(struct regs *r))
{
    irqRoutines[irq] = handler;
}

/// Entfernt einen Eintrag für einen bestimmten Hardwareinterrupt.
/// \param irq Die Nummer des Handlers(0 - 13).
void IRQUninstallHandler(int irq)
{
    irqRoutines[irq] = 0;
}

/// Setzt die Interrupthandler für die Hardwareinterrupts.
void IRQInstall()
{
  SetPic();
  IDTSetGate(32, (unsigned)irq0, 0x08, 0x8E);
  IDTSetGate(33, (unsigned)irq1, 0x08, 0x8E);
  IDTSetGate(34, (unsigned)irq2, 0x08, 0x8E);
  IDTSetGate(35, (unsigned)irq3, 0x08, 0x8E);
  IDTSetGate(36, (unsigned)irq4, 0x08, 0x8E);
  IDTSetGate(37, (unsigned)irq5, 0x08, 0x8E);
  IDTSetGate(38, (unsigned)irq6, 0x08, 0x8E);
  IDTSetGate(39, (unsigned)irq7, 0x08, 0x8E);

  IDTSetGate(40, (unsigned)irq8, 0x08, 0x8E);
  IDTSetGate(41, (unsigned)irq9, 0x08, 0x8E);
  IDTSetGate(42, (unsigned)irq10, 0x08, 0x8E);
  IDTSetGate(43, (unsigned)irq11, 0x08, 0x8E);
  IDTSetGate(44, (unsigned)irq12, 0x08, 0x8E);
  IDTSetGate(45, (unsigned)irq13, 0x08, 0x8E);
  IDTSetGate(46, (unsigned)irq15, 0x08, 0x8E);
  IDTSetGate(47, (unsigned)irq15, 0x08, 0x8E);
}

/// Setzt den Timer aufeine bestimmte Taktfrequenz, in der er einen Interrupt auslösen soll.
/// \param hz Die Frequenz in Takte/Sekunde.
void TimerPhase(int hz)
{
  unsigned int divisor = (unsigned int)(1193180/hz);
  outb(0x36, 0x43);
  outb(divisor&0xFF, 0x40);
  outb(divisor>>8, 0x40);
}

/// Speichert die Zeit die der Kernel schon läuft.
u32int timer_ticks = 0;

/// Der Interrupthandler für den Timer.
/// \param r Ein vom Aufrufer Generiertes Struct, über den Zustand des Computer zur Zeit des Aufrufens.
void TimerHandler(struct regs *r)
{
    timer_ticks++;
    if(timer_ticks >= (0xff ^ sizeof(u32int)))timer_ticks=0;
    if (timer_ticks % 18 == 0)
    {
        //Printk("One second has passed\n");
    }
}

/// Richtet den Interrupthandler für den Timer ein.
void TimerInstall()
{
    IRQInstallHandler(0, TimerHandler);
}

/// Eine simple funktion um eine kurze Zeit zu warten.
/// \param ticks Anzahl ticks die gewartet werden sol, hängt mit der Eingestellten Frequenz zusammen.
void TimerWait(int ticks)
{
    unsigned long eticks;

    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}

/// Interruptstruct zum Initialisieren.
struct idtEntry idt[256];
/// Pointer zum Starten des Interruptsystems.
struct idtPtr idtp;


/// Aktiviert Interrupts.
void Enable()
{
  outb(0x00, 0x21);
  outb(0x00, 0xA1);
}

/// Deaktiviert Interrupts.
void Disable()
{
  outb(0xFB, 0x21);
  outb(0xFF, 0xA1);
}

/// Initialisiert einen Interrupt.
/// Wichitg für die spätere Verwendung des Interrupts.
/// \param num Nummer des Interrupts
/// \param base Die Addresse der Interruptfunktion
/// \param sel Kernelsegment
/// \param flags Einstellungen für den Interrupt
void IDTSetGate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;

    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

/// Der Interrupthandler der alle weiteren Aufruft.
/// \param r Ein vom Aufrufer Generiertes Struct, über den Zustand des Computer zur Zeit des Aufrufens.
void InterruptStandardHandler(struct regs *r)
{
	void (*handler)(struct regs *r);
	if (r->int_no < 32 && !(r->int_no==14))
	{
		PrintFailed(exceptionMessages[r->int_no]);
		PrintFailed(". System Halted!\n");
		Printf("gs: %d  fs: %d  es: %d  ds: %d  edi: %d\nesi: %d  ebp: %d  esp: %d  ebx: %d  edx: %d\necx: %d  eax: %d\nInterrupt number: %d\nerror code: %d\neip: %d  cs: %d  eflags: %d  useresp: %d  ss: %d\nat 0x%X",r->gs,r->fs,r->es,r->ds,r->edi,r->esi,r->ebp,r->esp,r->ebx,r->edx,r->ecx,r->eax,r->int_no,r->err_code,r->eip,r->cs,r->eflags,r->useresp,r->ss, ReadCR2());
		for (;;);
	}
	else if(r->int_no == 14)
	{
		PageFaultHandler(r);
	}
	else if ((r->int_no >= 32) && (r->int_no < 48))
	{
		//Prüfen, ob es einen eigenen Interrupthandler gibt und diesen dann ausführen
		handler = irqRoutines[r->int_no - 32];
		if (handler)
		{
			handler(r);
		}
		if (r->int_no >= 40)
		{
			outb(0x20, 0xA0);
		}
		outb(0x20, 0x20);
	}
	else
	{
		Printk("Unbekannter Intterrupt");
	}
}

void SetStandardInterrupt()
{
	int i;
	for(i = 0; i < 256; i++)
	{
		IDTSetGate(i, (unsigned)null_handler, 0x08, 0x8E);
	}
}

/// Richtet die Interrupts ein und aktiviert es in der CPU.
void IDTInstall()
{
	Printk("Initialisiere IDT\n");
	idtp.limit = (sizeof (struct idtEntry) * 256) - 1;
	idtp.base = (unsigned int)&idt;
	memset(&idt, 0, sizeof(struct idtEntry) * 256);
	SetStandardInterrupt();
	Printk("   Initialisiere ISRs\n");
	ISRSInstall();
	Printk("   Initialisiere IRQs\n");
	IRQInstall();
	TimerInstall();
	Printk("   Lade IDT\n");
	Enable();
	IDTLoad();
}


