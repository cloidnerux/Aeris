;Registermanipulation
global ReadCR0
ReadCR0:
   mov eax, cr0
   retn
   
global WriteCR0
WriteCR0:
   push ebp
   mov ebp, esp
   mov eax, [ebp+8]
   mov cr0, eax
   pop ebp
   retn

global ReadCR3
ReadCR3:
   mov eax, cr3
   retn

global WriteCR3
WriteCR3:
   push ebp
   mov ebp, esp
   mov eax, [ebp+8]
   mov cr3, eax
   pop ebp
   retn

global ReadCR2
ReadCR2:
   mov eax, cr2
   retn

global WriteCR2
WriteCR2:
   push ebp
   mov ebp, esp
   mov eax, [ebp+8]
   mov cr2, eax
   pop ebp
   retn

;global InvalidateTLB
;InvalidateTLB:
  ;push ebp;
  ;mov ebp, esp;
  ;mov eax, [ebp+2]
  ;invlpg eax
  ;pop ebp
  ;retn
