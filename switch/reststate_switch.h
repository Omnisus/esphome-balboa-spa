#pragma once

#include "../balboaspa.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/component.h"

namespace esphome::balboa_spa {

class ReststateSwitch : public switch_::Switch {
 public:
  ReststateSwitch() {};
  void update(SpaState *spa_state);
  void set_parent(BalboaSpa *parent);

 protected:
  void write_state(bool state) override;

 private:
  void toggle_heat_();
  BalboaSpa *spa_;
  ToggleStateMaybe set_state_ = ToggleStateMaybe::DONT_KNOW;
};

}  // namespace esphome::balboa_spa
