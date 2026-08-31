#include "reststate_switch.h"

namespace esphome
{
    namespace balboa_spa
    {
        void ReststateSwitch::update(SpaState *spaState)
        {
            if (this->state != spaState->rest_mode)
            {
                this->publish_state(spaState->rest_mode);
            }
        }

        void ReststateSwitch::set_parent(BalboaSpa *parent)
        {
            spa = parent;
            parent->register_listener([this](SpaState *spaState)
                                      { this->update(spaState); });
        }

        void ReststateSwitch::toggle_heat()
        {
            spa->toggle_heat();
        }

        void ReststateSwitch::write_state(bool state)
        {
            SpaState *spaState = spa->get_current_state();

            if (spaState->rest_mode != state)
            {
                this->setState = state ?ToggleStateMaybe::ON : ToggleStateMaybe::OFF;
                this->toggle_heat();
            }
        }


    } // namespace balboa_spa
} // namespace esphome
