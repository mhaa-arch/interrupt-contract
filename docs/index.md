# Interrupt Control Contract guide

A gate may be local to one CPU core. A one-bit snapshot represents that gate's prior state. Read the scope of the gate and the requirements for restoration before using a guard.

1. Start with [the contract](contract.md) for implementer obligations and capability boundaries.
2. Read [the conformance example](examples.md) for an implementation you can compile locally.
3. Consult [the portability notes](compatibility.md) before choosing a hardware mapping.