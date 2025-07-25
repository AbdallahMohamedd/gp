/**
 * @file DebugInfo.h
 * @brief Provides simple debug message capabilities for the BMS project.
 *
 * @details This header defines a macro (`DebugInfo`) to print standard debug
 *          information (function name, file name, line number) to the console.
 *          The printing is conditionally compiled based on the `DebugInfoManager` macro.
 *
 * @note To enable debug prints globally, un-comment the line #define DebugInfoManager.
 * @note To disable debug prints globally, ensure `#define DebugInfoManager` is commented out or undefined.
 * @note Usage: Place the following block where a debug print is needed:
 *       #ifdef DebugInfoManager
 *           DebugInfo;
 *       #endif
 *
 * @note Project: Graduation Project - Battery Management System
 * @note Engineer: Abdullah Mohamed
 * @note Component: DebugInfoManager
 */

#ifndef DEBUG_INFO_MANAGER
#define DEBUG_INFO_MANAGER

//=============================================================================
// Includes
//=============================================================================
#include "source/COTs/KL25ZUtilize/Inc/KL25ZUtil.h"
#include <MKL25Z4.h>
#include "stdint.h"                  		// For standard integer types
#include <string.h>
#include <math.h>
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "fsl_debug_console.h"
#include <tpm1.h>
//=============================================================================
// Debug Control Macro Definition (General)
//=============================================================================
/**
 * @brief Master switch to enable/disable all `DebugInfo` prints at compile time.
 * @details Uncomment the following line to globally enable the debug messages
 *          defined by the `DebugInfo` macro throughout the project.
 *          Leave it commented out to disable them (reducing code size and execution time).
 */
 #define DebugInfoManager

/**
 * @brief Prints standard debug context information (function, file, line).
 * @details This macro, when used within the `#ifdef DebugInfoManager` block,
 *          will print the current function name, the source file name, and the
 *          line number where the macro is called. Useful for tracing execution flow.
 */
#define DebugInfo PRINTF("DebugInfo: @ Func: %s, File: %s, Line: %d \n\r\r", __func__, __FILE__, __LINE__)

//=============================================================================
//  Module-Specific Debug Switches
//=============================================================================
//  --- SlaveIF Module Debug Switches ---
/**
 * @brief Define these macros to enable specific debug print categories within SlaveIF.c.
 * @details Uncomment the desired lines to activate the corresponding PRINTF statements
 *          in the SlaveIF driver implementation. Keep them commented out to disable.
 */
// #define SLAVEIF_DEBUG_INIT      ///< Enable SlaveIF Initialization step prints
// #define SLAVEIF_DEBUG_CONFIG    ///< Enable SlaveIF Configuration step prints
// #define SLAVEIF_DEBUG_COMM      ///< Enable SlaveIF SPI frame construction/reception prints
// #define SLAVEIF_DEBUG_ISR       ///< Enable SlaveIF ISR entry/workaround prints
// #define SLAVEIF_DEBUG_DMA       ///< Enable SlaveIF DMA Callback prints (Note: May not trigger with ISR workaround)
// #define SLAVEIF_DEBUG_MEAS      ///< Enable SlaveIF Measurement trigger/status prints
// #define SLAVEIF_DEBUG_FAULT     ///< Enable SlaveIF Fault status reading prints
// #define SLAVEIF_DEBUG_BALANCING ///< Enable SlaveIF Cell Balancing operation prints
// #define SLAVEIF_DEBUG_TEMP      ///< Enable SlaveIF Temperature reading/conversion prints
// #define SLAVEIF_DEBUG_VOLTAGE   ///< Enable SlaveIF Voltage reading prints
// #define SLAVEIF_DEBUG_CURRENT   ///< Enable SlaveIF Current reading prints
// #define SLAVEIF_DEBUG_GPIO      ///< Enable SlaveIF GPIO status prints
// #define SLAVEIF_DEBUG

//  --- DataMonitor Module Debug Switches ---
/**
 * @brief Define these macros to enable specific debug print categories within DataMonitor.c.
 * @details Uncomment the desired lines to activate the corresponding PRINTF statements
 *          in the DataMonitor driver implementation. Keep them commented out to disable.
 */
// #define DATAMONITOR_DEBUG_CONVERSION ///< Enable DataMonitor float-to-string conversion debug prints
// #define DATAMONITOR_DEBUG_SOC        ///< Enable DataMonitor SOC display debug prints
// #define DATAMONITOR_DEBUG_SOH        ///< Enable DataMonitor SOH display debug prints
// #define DATAMONITOR_DEBUG_CURRENT    ///< Enable DataMonitor current display debug prints
// #define DATAMONITOR_DEBUG_FAULT      ///< Enable DataMonitor fault status display debug prints
// #define DATAMONITOR_DEBUG_TEMP       ///< Enable DataMonitor temperature display debug prints
// #define DATAMONITOR_DEBUG_MODE       ///< Enable DataMonitor operating mode display debug prints
// #define DATAMONITOR_DEBUG_DATA       ///< Enable DataMonitor all parameters display debug prints

//  --- ScreenIF Module Debug Switches ---
/**
 * @brief Define these macros to enable specific debug print categories within ScreenIF.c.
 * @details Uncomment the desired lines to activate the corresponding PRINTF statements
 *          in the ScreenIF driver implementation. Keep them commented out to disable.
 */
// #define SCREENIF_DEBUG_INIT    ///< Enable ScreenIF initialization and setup debug prints
// #define SCREENIF_DEBUG_I2C     ///< Enable ScreenIF I2C communication debug prints
// #define SCREENIF_DEBUG_CMD     ///< Enable ScreenIF LCD command execution debug prints
// #define SCREENIF_DEBUG_DATA    ///< Enable ScreenIF data (character/string) display debug prints

//  --- FanCtrl Module Debug Switches ---
/**
 * @brief Define these macros to enable specific debug print categories within FanCtrl.c.
 * @details Uncomment the desired lines to activate the corresponding PRINTF statements
 *          in the FanCtrl driver implementation. Keep them commented out to disable.
 */
// #define FANCTRL_DEBUG_INIT    ///< Enable FanCtrl initialization debug prints
// #define FANCTRL_DEBUG_PWM     ///< Enable FanCtrl PWM duty cycle debug prints

//  --- TempSensorIF Module Debug Switches ---
/**
 * @brief Define these macros to enable specific debug print categories within TempSensorIF.c.
 * @details Uncomment the desired lines to activate the corresponding PRINTF statements
 *          in the TempSensorIF driver implementation. Keep them commented out to disable.
 */
//#define TEMPSENSORIF_DEBUG_CONVERT    ///< Enable TempSensorIF temperature conversion debug prints


#endif /* DEBUG_INFO_MANAGER */
//=============================================================================
// End of File
//=============================================================================
