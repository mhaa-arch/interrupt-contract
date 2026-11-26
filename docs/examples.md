# Interrupt Control Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The fake provides both the base gate and `MaskControl`. The test captures a disabled gate and restores false, then repeats the exercise from an enabled gate. A bool in a host fixture checks the state protocol. It cannot establish instruction-level atomicity on a microcontroller.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <interrupt/controller.hpp>
#include <interrupt/mask_control.hpp>


using namespace mhaa::interrupt;

class Fake final : public MaskControl
{
public:
    void enable() override { enabled_ = true; }
    void disable() override
    {
        enabled_ = false;
        ++separate_masks;
    }
    bool enabled() const override { return enabled_; }
    bool save_and_disable() noexcept override
    {
        ++atomic_masks;
        const bool old = enabled_;
        enabled_ = false;
        return old;
    }
    void restore(bool enabled) noexcept override
    {
        enabled_ = enabled;
        ++restores;
    }

    unsigned atomic_masks = 0;
    unsigned separate_masks = 0;
    unsigned restores = 0;

private:
    bool enabled_ = true;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
