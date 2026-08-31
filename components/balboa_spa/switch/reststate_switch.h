#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "../balboaspa.h"

namespace esphome
{
  namespace balboa_spa
  {

    class RestStateSwitch : public switch_::Switch
    {
    public:
      RestStateSwitch() {};
      void update(SpaState *spaState);
      void set_parent(BalboaSpa *parent);

    protected:
      void write_state(bool state) override;

    private:
    void toggle_heat();
      BalboaSpa *spa;
      ToggleStateMaybe setState = ToggleStateMaybe::DONT_KNOW;


  } // namespace balboa_spa
} // namespace esphome
