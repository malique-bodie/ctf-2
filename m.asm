push $0x14
pop %eax
int $0x80
mov %eax, %ebx
push $0x0a
pop %ecx
push $0x25
pop %eax
int $0x80