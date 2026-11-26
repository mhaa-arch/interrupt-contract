# Interrupt Control contract

## Gate control

[Controller](../include/interrupt/controller.hpp) controls maskable interrupt delivery in its execution context. `enabled()` observes that gate. Per-source masks, priority settings and nonmaskable faults are outside the interface.

## Atomic save and restoration

[MaskControl](../include/interrupt/mask_control.hpp) extends the same gate. `save_and_disable()` captures the prior enable state and masks delivery as one atomic operation with respect to that gate. Restore the captured state with `restore` in the same context and in reverse acquisition order. Both methods are nonthrowing. Separate query and disable calls do not provide the atomic capability.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Each interface uses built-in C++ types.
