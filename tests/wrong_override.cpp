#include <interrupt/controller.hpp>

using namespace mhaa::interrupt;

class WrongOverride final : public Controller
{
public:
    void enable() const override;
};
