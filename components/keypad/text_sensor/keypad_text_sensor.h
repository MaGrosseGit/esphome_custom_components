#pragma once

#include "esphome/core/automation.h"
#include "esphome/components/keypad/keypad.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace keypad {

class KeypadTextSensor : public KeypadListener, public text_sensor::TextSensor, public Component {
 public:
  KeypadTextSensor();
  void loop() override;
  void dump_config() override;
  void set_min_length(int min_length) { this->min_length_ = min_length; };
  void set_max_length(int max_length) { this->max_length_ = max_length; };
  void set_end_keys(std::string end_keys) { this->end_keys_ = end_keys; };
  void set_end_key_required(bool end_key_required) { this->end_key_required_ = end_key_required; };
  void set_back_keys(std::string back_keys) { this->back_keys_ = back_keys; };
  void set_clear_keys(std::string clear_keys) { this->clear_keys_ = clear_keys; };
  void set_allowed_keys(std::string allowed_keys) { this->allowed_keys_ = allowed_keys; };
  void clear_all_keys() { this->result_.clear(); };
  Trigger<std::string> *get_progress_trigger() const;
  void set_timeout(int timeout) { this->timeout_ = timeout; };

  void key_pressed(unsigned char key) override;

 protected:
  int min_length_{0};
  int max_length_{0};
  std::string end_keys_;
  bool end_key_required_{false};
  bool keycode_filled_{false};
  std::string back_keys_;
  std::string clear_keys_;
  std::string allowed_keys_;
  std::string result_;
  Trigger<std::string> *progress_trigger_;
  uint32_t last_key_time_;
  uint32_t timeout_{0};
};

}  // namespace keypad
}  // namespace esphome

