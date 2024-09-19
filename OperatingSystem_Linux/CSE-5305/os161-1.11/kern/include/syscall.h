#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*
 * Prototypes for IN-KERNEL entry points for system call implementations.
 */

int sys_reboot(int code);

/*
 * System Call _exit()
 */
void sys__exit(int exitcode);

int sys_printint(int code);

int sys_reversestring(const char *str, int len);

#endif /* _SYSCALL_H_ */
