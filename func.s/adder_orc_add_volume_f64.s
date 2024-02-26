
/* autogenerated from adder_orc_add_volume_f64.orc */

/* adder_orc_add_volume_f64 */
.global adder_orc_add_volume_f64
.p2align 4
adder_orc_add_volume_f64:
# 1: loadpq
# LOOP SHIFT 0
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# LOOP SHIFT 1
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# LOOP SHIFT 2
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# LOOP SHIFT 2
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# LOOP SHIFT 1
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
# LOOP SHIFT 0
# 0: loadq
# 2: muld
# 3: loadq
# 4: addd
# 5: storeq
  endbr64 
  vstmxcsr 596(%rdi)
  movl 596(%rdi), %ecx
  movl %ecx, 600(%rdi)
  or $32832, %ecx
  movl %ecx, 596(%rdi)
  vldmxcsr 596(%rdi)
  vmovd 632(%rdi), %xmm0
  vpinsrd $1, 664(%rdi), %xmm0, %xmm0
  vpbroadcastq %xmm0, %ymm0
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
  vmovq 0(%rdx), %xmm1
  vmulpd %xmm0, %xmm1, %xmm1
  vmovq 0(%rax), %xmm2
  vaddpd %xmm1, %xmm2, %xmm2
  vmovq %xmm2, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
16:
  testl $2, 12(%rdi)
  jz 17f
  vmovdqu 0(%rdx), %xmm1
  vmulpd %xmm0, %xmm1, %xmm1
  vmovdqu 0(%rax), %xmm2
  vaddpd %xmm1, %xmm2, %xmm2
  vmovdqu %xmm2, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
17:
1:
  cmpb $0, 16(%rdi)
  jz 3f
  movl 16(%rdi), %esi
.p2align 4
2:
  vmovdqu 0(%rdx), %ymm1
  vmulpd %ymm0, %ymm1, %ymm1
  vmovdqa 0(%rax), %ymm2
  vaddpd %ymm1, %ymm2, %ymm2
  vmovdqa %ymm2, 0(%rax)
  vmovdqu 32(%rdx), %ymm1
  vmulpd %ymm0, %ymm1, %ymm1
  vmovdqa 32(%rax), %ymm2
  vaddpd %ymm1, %ymm2, %ymm2
  vmovdqa %ymm2, 32(%rax)
  leaq 64(%rax), %rax
  leaq 64(%rdx), %rdx
  add $-1, %esi
  jnz 2b
3:
  testl $4, 20(%rdi)
  jz 10f
  vmovdqu 0(%rdx), %ymm1
  vmulpd %ymm0, %ymm1, %ymm1
  vmovdqu 0(%rax), %ymm2
  vaddpd %ymm1, %ymm2, %ymm2
  vmovdqu %ymm2, 0(%rax)
  leaq 32(%rax), %rax
  leaq 32(%rdx), %rdx
10:
  testl $2, 20(%rdi)
  jz 9f
  vmovdqu 0(%rdx), %xmm1
  vmulpd %xmm0, %xmm1, %xmm1
  vmovdqu 0(%rax), %xmm2
  vaddpd %xmm1, %xmm2, %xmm2
  vmovdqu %xmm2, 0(%rax)
  leaq 16(%rax), %rax
  leaq 16(%rdx), %rdx
9:
  testl $1, 20(%rdi)
  jz 8f
  vmovq 0(%rdx), %xmm1
  vmulpd %xmm0, %xmm1, %xmm1
  vmovq 0(%rax), %xmm2
  vaddpd %xmm1, %xmm2, %xmm2
  vmovq %xmm2, 0(%rax)
  leaq 8(%rax), %rax
  leaq 8(%rdx), %rdx
8:
  vldmxcsr 596(%rdi)
  vzeroupper 
  retq 


