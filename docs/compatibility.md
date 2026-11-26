# Porting the Interrupt Control Contract

Hardware Definitions describe interrupt facilities and core-local control. The Adapter must define which maskable delivery the gate controls and provide the atomic extension only when it can guarantee that operation. The interface does not exclude another core, DMA or nonmaskable handlers, so those require their own synchronization.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
