# Smart Desk Clock using STM32F446RE

A feature-rich **bare-metal embedded systems project** built on the **STM32F446RE Nucleo** development board. This project implements a digital desk clock with environmental sensing, alarm and timer functionality, OLED user interface, and interrupt-driven peripherals **without using STM32 HAL or CubeMX-generated drivers**.

The project demonstrates direct register-level programming, modular driver development, interrupt-based communication, DMA, and real-time embedded system design.

---

## Features

- Real-Time Clock (RTC)
  - Time and date display
  - User configurable date and time
  - RTC Alarm support
  - Countdown timer using RTC Alarm

- Environmental Monitoring
  - Temperature & Humidity using DHT22
  - Temperature & Pressure using BMP280
  - Automatic switching between sensors

- OLED User Interface
  - 128×64 SSD1306 OLED
  - Custom framebuffer graphics engine
  - Text rendering
  - Adjustable display contrast
  - Menu-based navigation

- Alarm System
  - Configurable alarm
  - RTC Alarm interrupt
  - Buzzer notification
  - Alarm cancellation

- User Input
  - Multiple push buttons using EXTI interrupts
  - Menu navigation
  - Date/Time configuration
  - Alarm configuration
  - Timer configuration

- ADC Controlled Contrast
  - Potentiometer controlled OLED brightness

- UART Debug Console
  - Sensor initialization status
  - I2C error reporting
  - Alarm and timer debugging

---

# Hardware Used

| Component | Purpose |
|-----------|---------|
| STM32F446RE Nucleo | Main Controller |
| SSD1306 OLED (128×64 SPI) | Display |
| BMP280 | Temperature & Pressure Sensor |
| DHT22 | Temperature & Humidity Sensor |
| Potentiometer | OLED Contrast Control |
| Push Buttons | User Interface |
| Active Buzzer | Alarm Output |

---

# Peripherals Used

- GPIO
- EXTI
- ADC1
- SPI1
- DMA2
- I2C1
- USART2
- RTC
- SysTick
- NVIC

---

# Software Architecture

```
                    Application Layer
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
     Display           Sensor Logic      User Interface
        │                  │                  │
 ┌──────┼──────┐      ┌────┴────┐      ┌──────┴──────┐
 │             │      │         │      │             │
OLED Driver  SPI     BMP280   DHT22   EXTI       RTC Alarm
                │        │         │
              I2C Driver │         │
                │        │         │
              STM32 Peripheral Drivers
```

---

# Project Structure

```
├── Inc
│   ├── ADC.h
│   ├── BMP280.h
│   ├── DHT22.h
│   ├── Display.h
│   ├── I2C.h
│   ├── Interrupt.h
│   ├── OLED.h
│   ├── RTC.h
│   ├── SPI.h
│   ├── SYSTIC.h
│   ├── uart.h
│   └── ...
│
├── Src
│   ├── ADC.c
│   ├── BMP280.c
│   ├── DHT22.c
│   ├── Display.c
│   ├── I2C.c
│   ├── Interrupt.c
│   ├── OLED.c
│   ├── RTC.c
│   ├── SPI.c
│   ├── SYSTIC.c
│   ├── uart.c
│   └── main.c
```

---

# Driver Overview

## RTC Driver

- Time initialization
- Date initialization
- Time update
- Date update
- BCD conversion
- RTC Alarm
- Alarm interrupt

---

## I2C Driver

- Register-level implementation
- Interrupt-driven transmission
- Interrupt-driven reception
- Error handling
- Callback mechanism
- Repeated Start support

---

## SPI Driver

- Master mode
- DMA transmission
- OLED communication

---

## UART Driver

- Transmitter mode
- Serial logging (115200 Baud)
- For Debugging
  
---


## OLED Driver

- Framebuffer graphics
- Bitmap rendering
- Text rendering
- Rectangle drawing
- Display update
- Contrast control

---

## BMP280 Driver

- Device identification
- Calibration parameter reading
- Temperature measurement
- Pressure measurement

---

## DHT22 Driver

- One-wire communication
- Humidity measurement
- Temperature measurement
- Checksum verification

---

## ADC Driver

- Continuous conversion
- 8-bit resolution
- Contrast adjustment

---

## Interrupt Driver

External interrupts for:

- Navigation
- Menu selection
- Value increment
- Alarm acknowledgement
- Contrast mode selection

---

# Interrupts Used

| Interrupt | Purpose |
|------------|---------|
| EXTI0 | Menu Navigation |
| EXTI1 | Brightness Mode |
| EXTI3 | Alarm Stop |
| EXTI4 | Selection |
| EXTI9_5 | Increment Value |
| EXTI15_10 | Confirm |
| RTC Alarm | Alarm Trigger |
| I2C Event | I2C State Machine |
| I2C Error | Error Handling |
| SysTick | Periodic Sensor Switching |

---

# User Interface

## Home Screen

Displays

- Date
- Time
- Temperature
- Humidity

Code automatically alternates between

- DHT22
- BMP280

---

## Alarm Screen

Allows the user to configure

- Alarm Hour
- Alarm Minute

---

## Timer Screen

Allows configuring a countdown timer using the RTC Alarm peripheral.

---

# Pin Connections

## OLED (SPI)

| OLED | STM32 |
|------|--------|
| SCK | PA5 |
| MOSI | PA7 |
| CS | PA4 |
| DC | PA8 |
| RESET | PA9 |

---

## BMP280 (I2C)

| BMP280 | STM32 |
|---------|--------|
| SCL | PB8 |
| SDA | PB9 |

---

## DHT22

| Sensor | STM32 |
|---------|--------|
| DATA | PA10 |

---

## Brightness Potentiometer

| Potentiometer | STM32 |
|---------------|--------|
| Output | PA0 (ADC1_IN0) |

---

## Buzzer

| Device | STM32 |
|---------|--------|
| Buzzer | PB6 |

---

## Push Buttons

| Function | Pin |
|-----------|-----|
| Navigation | PB0 |
| Contrast Mode | PA1 |
| Alarm Stop | PB3 |
| Select | PB4 |
| Increment | PB5 |
| Confirm | PB10 |

---

# Development Highlights

- Pure register-level programming
- No STM32 HAL
- No CubeMX generated peripheral drivers
- Interrupt-driven I2C communication
- DMA-based SPI transfers
- Modular driver architecture
- Reusable peripheral drivers
- Bare-metal firmware development

---

# Future Improvements

- Hardware debouncing
- Non-blocking DHT22 driver
- EEPROM/Flash storage for settings
- Low-power sleep mode
- Multi-alarm support
- Stopwatch mode
- Animated OLED interface
- RTC backup register support

---

# Build Requirements

- STM32CubeIDE
- STM32F446RE Nucleo Board
- ARM GCC Toolchain

---

# License

This project is released under the MIT License.

---

## Author

**Mudit Goyal**

