#include <debug.h>
#include "syscall.h"
#include <sys/time.h>
#include <mem.h>
#include <fs.h>
#include <proc.h>

void syscall_handle(Context *c) {
  uintptr_t a[4];
  a[0] = c->SYS_NUM;
  a[1] = c->SYS_ARG1;
  a[2] = c->SYS_ARG2;
  a[3] = c->SYS_ARG3;
  switch (a[0]) {
    case SYS_exit: {
      // Lab7 TODO: exit the current process
      break;
    }
    case SYS_yield: {
      // Lab7 TODO: yield the current process
      break;
    }
    case SYS_write: {
      // Lab7 TODO: use `fs_write` to write the file with fd from offset by buf
    }
    case SYS_open: {
      // Lab7 TODO: open the file with name = (char *)a[1]
    }
    case SYS_read: {
      // Lab7 TODO: read the file with fd from offset into buf
    }
    case SYS_lseek: {
      // Lab7 TODO: seek the file with fd from the offset based on whence
    }
    case SYS_close: {
      // Lab7 TODO: close the file with fd
    }
    case SYS_gettimeofday: {
      size_t time = io_read(DEV_TIMER_UPTIME).us;
      ((struct timeval *)a[1])->tv_sec = time / 1000000;
      ((struct timeval *)a[1])->tv_usec = time % 1000000;
      c->SYS_RET = 0;
      break;
    }
    case SYS_execve: {
      user_naive_load((const char *) a[1]);
      c->SYS_RET = 0;
      break;
    }
    case SYS_brk: {
      c->SYS_RET = mm_brk(a[1]); 
      break;
    }
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
