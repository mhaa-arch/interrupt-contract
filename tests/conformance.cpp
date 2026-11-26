#include <interrupt/controller.hpp>
#include <interrupt/mask_control.hpp>

#include <cassert>

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

int main()
{
    Fake fake;
    MaskControl &gate = fake;
    gate.disable();
    assert(!gate.save_and_disable());
    gate.restore(false);
    assert(!gate.enabled());
    gate.enable();
    assert(gate.save_and_disable() && !gate.enabled());
    gate.restore(true);
    assert(gate.enabled());
}
