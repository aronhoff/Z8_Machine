#pragma once

class MotorControls {
  private:
    static const short bcc_pin = 3; // TODO: Change to actual pin number

  public:
    MotorControls();
    void leftOverride() const;
    void rightOverride() const;
    void go() const;
    void stop1() const;
};
