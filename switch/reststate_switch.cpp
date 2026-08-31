#include "reststate_switch.h"

namespace esphome::balboa_spa {
void ReststateSwitch::update(SpaState *spa_state) {
  if (this->state != spa_state->rest_mode) {
    this->publish_state(spa_state->rest_mode);
  }
}

void ReststateSwitch::set_parent(BalboaSpa *parent) {
  spa_ = parent;
  parent->register_listener([this](SpaState *spa_state) { this->update(spa_state); });
}

void ReststateSwitch::toggle_heat_() { spa_->toggle_heat(); }

void ReststateSwitch::write_state(bool state) {
  SpaState *spa_state = spa_->get_current_state();

  if (spa_state->rest_mode != state) {
    this->set_state_ = state ? ToggleStateMaybe::ON : ToggleStateMaybe::OFF;
    this->toggle_heat_();
  }
}

}  // namespace esphome::balboa_spa
