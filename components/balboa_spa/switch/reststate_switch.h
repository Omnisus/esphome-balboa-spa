#pragma once

#include "../balboaspa.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/component.h"

namespace esphome 
{
  namespace balboa_spa 
  {

    class ReststateSwitch : public switch_::Switch 
    {
      public:
        ReststateSwitch() {};
        void update(SpaState *spaState);
        void set_parent(BalboaSpa *parent);

      protected:
        void write_state(bool state) override;

      private:
        void toggle_heat();
        BalboaSpa *spa;
        ToggleStateMaybe setState = ToggleStateMaybe::DONT_KNOW;

      };

  } // namespace balboa_spa
} // namespace esphome