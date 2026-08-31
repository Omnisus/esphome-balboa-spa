#include "reststate_switch.h"

namespace esphome
{
    namespace balboa_spa
    {
        void RestStateSwitch::update(SpaState *spaState)
        {
            if (this->state != spaState->rest_mode)
            {
                this->publish_state(spaState->rest_mode);
            }
        }

        void RestStateSwitch::set_parent(BalboaSpa *parent)
        {
            spa = parent;
            parent->register_listener([this](SpaState *spaState)
                                      { this->update(spaState); });
        }

        void RestStateSwitch::toggle_heat()
        {
            spa->toggle_heat();
        }

        void RestStateSwitch::write_state(bool state)
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
