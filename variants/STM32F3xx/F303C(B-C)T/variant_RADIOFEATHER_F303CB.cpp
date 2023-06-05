/*
 *******************************************************************************
 * Copyright (c) 2020, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_RADIOFEATHER_F303CB)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
    PC_13, // D0 - NEOPIXEL
    PB_12, // D1 - SPI2_NSS
    PB_13, // D2 - SPI2_CLK
    PB_14, // D3 - SPI2_MISO
    PB_15, // D4 - SPI2_MOSI
    PA_0,  // D5
    PA_1,  // D6
    PB_6,  // D7 - I2C1_SCL
    PB_7,  // D8 - I2C1_SDC
    PB_8,  // D9  - CAN_RX
    PB_9,  // D10 - CAN_TX
    PB_10, // D11 - USART3_TX
    PB_11, // D12 - USART3_RX
    PA_8,  // D13
    PA_13, // D14 - SWDI0
    PA_14, // D15 - SWCLK
    PA_15, // D16 - SPI3_NSS or TDI
    PB_3,  // D17 - SPI3_CLK or SWO or TDO
    PB_4,  // D18 - SPI3_MISO or ~TRST
    PB_5,  // D19 - SPI3_MOSI
    PA_4,  // D20/A0 - SPI1_NSS
    PA_3,  // D21/A1 - USART2_RX
    PA_2,  // D22/A2 - USART2_TX
    PB_0,  // D23/A3
    PB_1,  // D24/A4
    PB_2,  // D25/A5
    PA_5,  // D26/A6 - SPI1_CLK
    PA_7,  // D27/A7 - SPI1_MOSI
    PA_6,  // D28/A8 - SPI1_MISO
    PA_10, // D29/A9  - USART1_RX
    PA_9,  // D30/A10 - USART1_TX
    PA_11, // D31 - USB_DM
    PA_12, // D32 - USB_DP
    PC_14, // D33 - OSC32 IN
    PC_15, // D34 - OSC32 OUT
    PF_0,  // D35 - OSC IN
    PF_1   // D36 - OSC OUT
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
    20, // A0,  PA4
    21, // A1,  PA3
    22, // A2,  PA2
    23, // A3,  PB0
    24, // A4,  PB1
    25, // A5,  PB2
    26, // A6,  PA5
    27, // A7,  PA7
    28, // A8,  PA6
    29, // A9,  PA10
    30  // A10, PA9
};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief System Clock Configuration
     * @retval None
     */
    void SystemClock_Config(void)
    {
        RCC_OscInitTypeDef RCC_OscInitStruct = {};
        RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
        RCC_PeriphCLKInitTypeDef PeriphClkInit = {};

        // Configure LSE Drive Capability
        //
        HAL_PWR_EnableBkUpAccess();
        __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

        // Initializes the RCC Oscillators according to the specified parameters
        // in the RCC_OscInitTypeDef structure.
        //
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
        RCC_OscInitStruct.LSEState = RCC_LSI_ON;
        RCC_OscInitStruct.HSIState = RCC_HSI_ON;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
        if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
        {
            Error_Handler();
        }

        // Initializes the CPU, AHB and APB buses clocks
        //
        RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                    |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
        RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
        RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
        RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

        if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
        {
            Error_Handler();
        }
        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB | RCC_PERIPHCLK_RTC;
        PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
        PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
        {
            Error_Handler();
        }
    }

#ifdef __cplusplus
}
#endif
#endif /* ARDUINO_GENERIC_* */
