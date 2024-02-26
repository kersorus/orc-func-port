
/* autogenerated from audiomixer_orc_add_f64.orc */

/* audiomixer_orc_add_f64 */
.global audiomixer_orc_add_f64
.p2align 4
audiomixer_orc_add_f64:
# LOOP SHIFT 0
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# LOOP SHIFT 1
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# LOOP SHIFT 2
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# LOOP SHIFT 2
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# LOOP SHIFT 1
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
# LOOP SHIFT 0
# 0: loadq
# 1: loadq
# 2: addd
# 3: storeq
  endbr64 
  vstmxcsr 596(%rdi)
  movl 596(%rdi), %ecx
  movl %ecx, 600(%rdi)
  or $32832, %ecx
  movl %ecx, 596(%rdi)
  vldmxcsr 596(%rdi)
  mov $32, %eax
  sub 24(%rdi), %eax
  and $31, %eax
  sar $3, %eax
  cmp %eax, 8(%rdi)
  jle 6f
  movl %eax, 12(%rdi)
  movl 8(%rdi), %ecx
  sub %eax, %ecx
  mov %ecx, %eax
  sar $3, %ecx
  movl %ecx, 16(%rdi)
  and $7, %eax
  movl %eax, 20(%rdi)
  jmp 7f
6:
  movl 8(%rdi), %eax
  movl %eax, 12(%rdi)
  mov $0, %eax
  movl %eax, 16(%rdi)
  movl %eax, 20(%rdi)
7:
  mov 24(%rdi), %rax
  mov 56(%rdi), %rdx
  testl $1, 12(%rdi)
  jz 16f
  vmovq 0(%rax), %xmm0
  vmovq 0(%rdx), %xmm1
  vaddpd %xmm1, %xmm0, %xmm0
  vmovq %xmm0, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
16:
  testl $2, 12(%rdi)
  jz 17f
  vmovdqu 0(%rax), %xmm0
  vmovdqu 0(%rdx), %xmm1
  vaddpd %xmm1, %xmm0, %xmm0
  vmovdqu %xmm0, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
17:
1:
  cmpb $0, 16(%rdi)
  jz 3f
  movl 16(%rdi), %esi
.p2align 4
2:
  vmovdqa 0(%rax), %ymm0
  vmovdqu 0(%rdx), %ymm1
  vaddpd %ymm1, %ymm0, %ymm0
  vmovdqa %ymm0, 0(%rax)
  vmovdqa 32(%rax), %ymm0
  vmovdqu 32(%rdx), %ymm1
  vaddpd %ymm1, %ymm0, %ymm0
  vmovdqa %ymm0, 32(%rax)
  leaq 64(%rax), %rax
  leaq 64(%rdx), %rdx
  add $-1, %esi
  jnz 2b
3:
  testl $4, 20(%rdi)
  jz 10f
  vmovdqu 0(%rax), %ymm0
  vmovdqu 0(%rdx), %ymm1
  vaddpd %ymm1, %ymm0, %ymm0
  vmovdqu %ymm0, 0(%rax)
  leaq 32(%rax), %rax
  leaq 32(%rdx), %rdx
10:
  testl $2, 20(%rdi)
  jz 9f
  vmovdqu 0(%rax), %xmm0
  vmovdqu 0(%rdx), %xmm1
  vaddpd %xmm1, %xmm0, %xmm0
  vmovdqu %xmm0, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
9:
  testl $1, 20(%rdi)
  jz 8f
  vmovq 0(%rax), %xmm0
  vmovq 0(%rdx), %xmm1
  vaddpd %xmm1, %xmm0, %xmm0
  vmovq %xmm0, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
8:
  vldmxcsr 596(%rdi)
  vzeroupper 
  retq 


