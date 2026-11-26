#include <interrupt/controller.hpp>

using namespace mhaa::interrupt;

class Incomplete final : public Controller
{
public:
    void disable() override;
    bool enabled() const override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
