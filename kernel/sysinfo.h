struct sysinfo {
  uint64 freemem;   // amount of free memory (bytes)
  uint64 nproc;     // number of process
};
uint64 kmem_freenum(void);
uint64 procnum(void);