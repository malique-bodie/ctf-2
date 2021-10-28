mov %esp, %ebx
push $0x01
pop %ecx
xor %edx, %edx
push $0x05
pop %eax
int $0x80
mov %eax, %ebx
mov %esp, %ecx
push $0x05
pop %edx
push $0x05
pop %eax
int $0x80

