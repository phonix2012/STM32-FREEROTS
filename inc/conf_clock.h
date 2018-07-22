#ifndef __CONF_CLOCK_H
#define __CONF_CLOCK_H

#include "stm32f4xx_conf.h"


/* PPRE1/2: APB high-speed prescalers */
#define RCC_CFGR_PPRE2_SHIFT      13
#define RCC_CFGR_PPRE2_MASK     0x7
#define RCC_CFGR_PPRE1_SHIFT      10
#define RCC_CFGR_PPRE1_MASK     0x7
#define RCC_CFGR_PPRE_DIV_NONE      0x0
#define RCC_CFGR_PPRE_DIV_2     0x4
#define RCC_CFGR_PPRE_DIV_4     0x5
#define RCC_CFGR_PPRE_DIV_8     0x6
#define RCC_CFGR_PPRE_DIV_16      0x7

enum rcc_clock_3v3 {
  RCC_CLOCK_3V3_48MHZ,
  RCC_CLOCK_3V3_84MHZ,
  RCC_CLOCK_3V3_120MHZ,
  RCC_CLOCK_3V3_168MHZ,
  RCC_CLOCK_3V3_END
};


struct rcc_clock_scale{
  uint32_t pllm;
  uint32_t plln;
  uint32_t pllp;
  uint32_t pllq;
  uint32_t pllr;
  uint32_t flash_config;
  uint32_t hpre;
  uint32_t ppre1;
  uint32_t ppre2;
  uint32_t power_save;
  uint32_t ahb_frequency;
  uint32_t apb1_frequency;
  uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END];


int rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock);



#endif


