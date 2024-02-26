
/* autogenerated from audiomixer_orc_add_u16.orc */

/* audiomixer_orc_add_u16 */
.global audiomixer_orc_add_u16
.p2align 4
audiomixer_orc_add_u16:
# LOOP SHIFT 0
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 1
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 2
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 3
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 4
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 4
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 3
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 2
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 1
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
# LOOP SHIFT 0
# 0: loadw
# 1: loadw
# 2: addusw
# 3: storew
  endbr64 
  mov $32, %eax
  sub 24(%rdi), %eax
  and $31, %eax
  sar %eax
  cmp %eax, 8(%rdi)
  jle 6f
  movl %eax, 12(%rdi)
  movl 8(%rdi), %ecx
  sub %eax, %ecx
  mov %ecx, %eax
  sar $5, %ecx
  movl %ecx, 16(%rdi)
  and $31, %eax
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
  vpxor %ymm0, %ymm0, %ymm0
  vpinsrw $0, 0(%rax), %xmm0, %xmm0
  vpxor %ymm1, %ymm1, %ymm1
  vpinsrw $0, 0(%rdx), %xmm1, %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vpextrw $0, %xmm0, 0(%rax)
  leaq 2(%rax), %rax
  leaq 2(%rdx), %rdx
16:
  testl $2, 12(%rdi)
  jz 17f
  vmovd 0(%rax), %xmm0
  vmovd 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovd %xmm0, 0(%rax)
  leaq 4(%rax), %rax
  leaq 4(%rdx), %rdx
17:
  testl $4, 12(%rdi)
  jz 18f
  vmovq 0(%rax), %xmm0
  vmovq 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovq %xmm0, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
18:
  testl $8, 12(%rdi)
  jz 19f
  vmovdqu 0(%rax), %xmm0
  vmovdqu 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovdqu %xmm0, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
19:
1:
  cmpb $0, 16(%rdi)
  jz 3f
  movl 16(%rdi), %esi
.p2align 4
2:
  vmovdqa 0(%rax), %ymm0
  vmovdqu 0(%rdx), %ymm1
  vpaddusw %ymm1, %ymm0, %ymm0
  vmovdqa %ymm0, 0(%rax)
  vmovdqa 32(%rax), %ymm0
  vmovdqu 32(%rdx), %ymm1
  vpaddusw %ymm1, %ymm0, %ymm0
  vmovdqa %ymm0, 32(%rax)
  leaq 64(%rax), %rax
  leaq 64(%rdx), %rdx
  add $-1, %esi
  jnz 2b
3:
  testl $16, 20(%rdi)
  jz 12f
  vmovdqu 0(%rax), %ymm0
  vmovdqu 0(%rdx), %ymm1
  vpaddusw %ymm1, %ymm0, %ymm0
  vmovdqu %ymm0, 0(%rax)
  leaq 32(%rax), %rax
  leaq 32(%rdx), %rdx
12:
  testl $8, 20(%rdi)
  jz 11f
  vmovdqu 0(%rax), %xmm0
  vmovdqu 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovdqu %xmm0, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
11:
  testl $4, 20(%rdi)
  jz 10f
  vmovq 0(%rax), %xmm0
  vmovq 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovq %xmm0, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
10:
  testl $2, 20(%rdi)
  jz 9f
  vmovd 0(%rax), %xmm0
  vmovd 0(%rdx), %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vmovd %xmm0, 0(%rax)
  leaq 4(%rax), %rax
  leaq 4(%rdx), %rdx
9:
  testl $1, 20(%rdi)
  jz 8f
  vpxor %ymm0, %ymm0, %ymm0
  vpinsrw $0, 0(%rax), %xmm0, %xmm0
  vpxor %ymm1, %ymm1, %ymm1
  vpinsrw $0, 0(%rdx), %xmm1, %xmm1
  vpaddusw %xmm1, %xmm0, %xmm0
  vpextrw $0, %xmm0, 0(%rax)
  leaq 2(%rax), %rax
  leaq 2(%rdx), %rdx
8:
  vzeroupper 
  retq 


