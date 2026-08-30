#include "idlestate_switch.h"

namespace esphome
{
    namespace balboa_spa
    {
        void IdleStateSwitch::update(SpaState *spaState)
        {
            if (this->state != spaState->highrange)
            {
                this->publish_state(spaState->highrange);
            }
        }

        void IdleStateSwitch::set_parent(BalboaSpa *parent)
        {
            spa = parent;
            parent->register_listener([this](SpaState *spaState)
                                      { this->update(spaState); });
        }

        void IdleStateSwitch::write_state()
        {
            spa->toggle_heat();
        }

    } // namespace balboa_spa
} // namespace esphome
