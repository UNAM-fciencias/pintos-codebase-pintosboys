#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "userprog/process.h"

static void syscall_handler (struct intr_frame *);
static int32_t write_wrapper (int32_t *esp);
static void exit_wrapper (int32_t *esp);
static int32_t write (int file_descriptor, char* buffer, unsigned size);
static void exit (int exit_status);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int32_t* esp = f->esp;
  int32_t syscall = *esp;
  esp++;
  
  switch(syscall) {
    case SYS_WRITE: {
      f->eax = write_wrapper (esp);
      break;
    }
    case SYS_EXIT: {
      exit_wrapper (esp);
      break;
    }
    case SYS_WAIT:{
       tid_t child_tid = *esp;

      f->eax = process_wait(child_tid);

      break;
    }
    case SYS_EXEC:{
      const char* cmd = (char*)*esp;

      f->eax = (uint32_t) process_execute(cmd);

      break;
    }
    default: {
      printf ("unsupported syscall\n");
      thread_exit ();
    }
  }
}

/* Write Syscall Implementation */
static int32_t 
write_wrapper (int32_t *esp) {
  int file_descriptor = *esp;
  char *buffer = (char *) *++esp;
  unsigned size = (unsigned) *++esp;
  return write (file_descriptor, buffer, size);
}

static int32_t 
write (int file_descriptor UNUSED, char* buffer, unsigned size) {
  putbuf (buffer, size);
  return size;
}

/* Write Syscall Implementation */
static void 
exit_wrapper (int32_t *esp) {
  int exit_status = *esp;
  printf("%s: exit(%d)\n", thread_current()->name, exit_status);


      struct thread *cur = thread_current ();
      struct thread *padre = cur->father;

      if (padre != NULL) {
    struct list *hijos = &padre->childs;
    struct list_elem *hijo_elem;
    
    if (!list_empty(hijos)) {
        for (hijo_elem = list_front(hijos); hijo_elem != list_end(hijos); hijo_elem = list_next(hijo_elem)) {
            struct process *hijo = list_entry(hijo_elem, struct process, elem);
            
            if (hijo->tid == cur->tid) {
                hijo->exit_status = exit_status;
                sema_up(&padre->wait);
            }
        }
    }
}

  exit (exit_status);
}

static void 
exit (int exit_status UNUSED) {
  thread_exit ();
}
