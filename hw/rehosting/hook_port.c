/* SPDX-License-Identifier: GPL-2.0-or-later */
/* Fuzzer side of the hook port: everything is concrete, so the symbolic calls are empty. */
#include "qemu/osdep.h"
#include "qemu/log.h"
#include "cpu.h"
#include "hooks/hook_engine.h"

extern target_ulong fuzz_cursor;
bool getFuzz(uint8_t *buf, uint32_t size);

uint64_t hook_port_take_input(uint8_t *buf, size_t len)
{
    uint64_t offset = fuzz_cursor;

    getFuzz(buf, len);          /* ends the run when input runs out */
    return offset;
}

void hook_port_mem_input(void *host, size_t len, uint64_t offset)
{
}

void hook_port_mem_concrete(void *host, size_t len)
{
}

void hook_port_reg_concrete(CPUState *cs, unsigned reg)
{
}

void hook_port_log(const char *msg)
{
    qemu_log_mask(LOG_AFL, "%s", msg);
}
