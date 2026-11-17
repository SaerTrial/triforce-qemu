#ifndef __AFL_H
#define __AFL_H
extern const char *aflFile;
extern const char *covFile;
extern FILE* cov_fp;

extern unsigned long aflPanicAddr;
extern unsigned long aflDmesgAddr;
extern uint32_t afl_entry_point;

extern int aflEnableTicks;
extern int aflStart;
extern int aflGotLog;
extern unsigned char afl_fork_child;
extern int afl_wants_cpu_to_stop;

extern int afl_qemuloop_pipe[2];
extern CPUState *restart_cpu;

void afl_setup(void);
void afl_forkserver(CPUArchState*);

/* The "boot" section (hooks/hook_engine.h). */
extern int afl_fork_at_entry;
extern int afl_fork_pending;
void afl_start_fuzzing(CPUArchState *env);
void afl_discard_coverage(void);
void switch_to_fuzz_input(void);
#endif