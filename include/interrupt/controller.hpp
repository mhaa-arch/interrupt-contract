#ifndef MHAA_INTERRUPT_CONTROLLER_HPP
#define MHAA_INTERRUPT_CONTROLLER_HPP

namespace mhaa
{
    namespace interrupt
    {
        /** @brief Controls the global maskable interrupt gate of one execution context. */
        class Controller
        {
        public:
            virtual ~Controller() = default;
            virtual void enable() = 0;
            virtual void disable() = 0;
            virtual bool enabled() const = 0;
        };
    }
}

#endif
