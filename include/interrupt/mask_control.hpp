#ifndef MHAA_INTERRUPT_MASK_CONTROL_HPP
#define MHAA_INTERRUPT_MASK_CONTROL_HPP

#include <interrupt/controller.hpp>

namespace mhaa
{
    namespace interrupt
    {
        /** @brief Guarantees a single atomic save-and-mask operation for the related gate. */
        class MaskControl : public Controller
        {
        public:
            /** @brief Saves the previous gate state and masks delivery atomically. */
            virtual bool save_and_disable() noexcept = 0;

            /** @brief Restores the sampled gate state in the same execution context. */
            virtual void restore(bool was_enabled) noexcept = 0;
        };
    }
}

#endif
