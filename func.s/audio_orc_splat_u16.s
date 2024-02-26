
/* autogenerated from audio_orc_splat_u16.orc */

/* audio_orc_splat_u16 */
.global audio_orc_splat_u16
.p2align 4
audio_orc_splat_u16:
# 0: loadpw
# LOOP SHIFT 0
# 1: copyw
# 2: storew
# LOOP SHIFT 1
# 1: copyw
# 2: storew
# LOOP SHIFT 2
# 1: copyw
# 2: storew
# LOOP SHIFT 3
# 1: copyw
# 2: storew
# LOOP SHIFT 4
# 1: copyw
# 2: storew
# 1: copyw
# 2: storew
# LOOP SHIFT 4
# 1: copyw
# 2: storew
# LOOP SHIFT 3
# 1: copyw
# 2: storew
# LOOP SHIFT 2
# 1: copyw
# 2: storew
# LOOP SHIFT 1
# 1: copyw
# 2: storew
# LOOP SHIFT 0
# 1: copyw
# 2: storew
  endbr64 
  vmovd 632(%rdi), %xmm0
  vpbroadcastw %xmm0, %ymm0
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
  testl $1, 12(%rdi)
  jz 16f
  vmovdqa %xmm0, %xmm1
  vpextrw $0, %xmm1, 0(%rax)
  leaq 2(%rax), %rax
16:
  testl $2, 12(%rdi)
  jz 17f
  vmovdqa %xmm0, %xmm1
  vmovd %xmm1, 0(%rax)
  leaq 4(%rax), %rax
17:
  testl $4, 12(%rdi)
  jz 18f
  vmovdqa %xmm0, %xmm1
  vmovq %xmm1, 0(%rax)
  leaq 8(%rax), %rax
18:
  testl $8, 12(%rdi)
  jz 19f
  vmovdqa %xmm0, %xmm1
  vmovdqu %xmm1, 0(%rax)
  leaq 16(%rax), %rax
19:
1:
  cmpb $0, 16(%rdi)
  jz 3f
  movl 16(%rdi), %edx
.p2align 4
2:
  vmovdqa %ymm0, %ymm1
  vmovdqa %ymm1, 0(%rax)
  vmovdqa %ymm0, %ymm1
  vmovdqa %ymm1, 32(%rax)
  leaq 64(%rax), %rax
  add $-1, %edx
  jnz 2b
3:
  testl $16, 20(%rdi)
  jz 12f
  vmovdqa %ymm0, %ymm1
  vmovdqu %ymm1, 0(%rax)
  leaq 32(%rax), %rax
12:
  testl $8, 20(%rdi)
  jz 11f
  vmovdqa %xmm0, %xmm1
  vmovdqu %xmm1, 0(%rax)
  leaq 16(%rax), %rax
11:
  testl $4, 20(%rdi)
  jz 10f
  vmovdqa %xmm0, %xmm1
  vmovq %xmm1, 0(%rax)
  leaq 8(%rax), %rax
10:
  testl $2, 20(%rdi)
  jz 9f
  vmovdqa %xmm0, %xmm1
  vmovd %xmm1, 0(%rax)
  leaq 4(%rax), %rax
9:
  testl $1, 20(%rdi)
  jz 8f
  vmovdqa %xmm0, %xmm1
  vpextrw $0, %xmm1, 0(%rax)
  leaq 2(%rax), %rax
8:
  vzeroupper 
  retq 


