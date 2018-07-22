#include "conf_clock.h"
#include "stm32f4xx.h"




const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END] = {
  { /* 48MHz */
    .pllm = 8,
    .plln = 96,
    .pllp = 2,
    .pllq = 2,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 48000000,
    .apb1_frequency = 12000000,
    .apb2_frequency = 24000000,
  },
  { /* 84MHz */
    .pllm = 8,
    .plln = 336,
    .pllp = 4,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div2,
    .ppre2 = RCC_CFGR_PPRE_DIV_NONE,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_2WS,
    .ahb_frequency  = 84000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
  { /* 120MHz */
    .pllm = 8,
    .plln = 240,
    .pllp = 2,
    .pllq = 5,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 120000000,
    .apb1_frequency = 30000000,
    .apb2_frequency = 60000000,
  },
  { /* 168MHz */
    .pllm = 8,
    .plln = 336,
    .pllp = 2,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_5WS,
    .ahb_frequency  = 168000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
};



const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END] = {
  { /* 48MHz */
    .pllm = 12,
    .plln = 96,
    .pllp = 2,
    .pllq = 2,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 48000000,
    .apb1_frequency = 12000000,
    .apb2_frequency = 24000000,
  },
  { /* 84MHz */
    .pllm = 12,
    .plln = 336,
    .pllp = 4,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div2,
    .ppre2 = RCC_CFGR_PPRE_DIV_NONE,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_2WS,
    .ahb_frequency  = 84000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
  { /* 120MHz */
    .pllm = 12,
    .plln = 240,
    .pllp = 2,
    .pllq = 5,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 120000000,
    .apb1_frequency = 30000000,
    .apb2_frequency = 60000000,
  },
  { /* 168MHz */
    .pllm = 12,
    .plln = 336,
    .pllp = 2,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_5WS,
    .ahb_frequency  = 168000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
};

const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END] = {
  { /* 48MHz */
    .pllm = 16,
    .plln = 96,
    .pllp = 2,
    .pllq = 2,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 48000000,
    .apb1_frequency = 12000000,
    .apb2_frequency = 24000000,
  },
  { /* 84MHz */
    .pllm = 16,
    .plln = 336,
    .pllp = 4,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div2,
    .ppre2 = RCC_CFGR_PPRE_DIV_NONE,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_2WS,
    .ahb_frequency  = 84000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
  { /* 120MHz */
    .pllm = 16,
    .plln = 240,
    .pllp = 2,
    .pllq = 5,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 120000000,
    .apb1_frequency = 30000000,
    .apb2_frequency = 60000000,
  },
  { /* 168MHz */
    .pllm = 16,
    .plln = 336,
    .pllp = 2,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_5WS,
    .ahb_frequency  = 168000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
};

const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END] = {
  { /* 48MHz */
    .pllm = 25,
    .plln = 96,
    .pllp = 2,
    .pllq = 2,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 48000000,
    .apb1_frequency = 12000000,
    .apb2_frequency = 24000000,
  },
  { /* 84MHz */
    .pllm = 25,
    .plln = 336,
    .pllp = 4,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div2,
    .ppre2 = RCC_CFGR_PPRE_DIV_NONE,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_2WS,
    .ahb_frequency  = 84000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
  { /* 120MHz */
    .pllm = 25,
    .plln = 240,
    .pllp = 2,
    .pllq = 5,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .power_save = 1,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_3WS,
    .ahb_frequency  = 120000000,
    .apb1_frequency = 30000000,
    .apb2_frequency = 60000000,
  },
  { /* 168MHz */
    .pllm = 25,
    .plln = 336,
    .pllp = 2,
    .pllq = 7,
    .pllr = 0,
    .hpre = RCC_SYSCLK_Div1,
    .ppre1 = RCC_HCLK_Div4,
    .ppre2 = RCC_HCLK_Div2,
    .flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
        FLASH_ACR_LATENCY_5WS,
    .ahb_frequency  = 168000000,
    .apb1_frequency = 42000000,
    .apb2_frequency = 84000000,
  },
};

int rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock)
{

  int8_t status;
  /* Enable internal high-speed oscillator. */
  // rcc_osc_on(RCC_HSI);
  // rcc_wait_for_osc_ready(RCC_HSI);
  RCC_HSICmd(ENABLE);
  status = (int8_t)RCC_GetFlagStatus(RCC_FLAG_HSIRDY);
  if (status != (int8_t)SET)
    return -1;


  /* Select HSI as SYSCLK source. */
  // rcc_set_sysclk_source(RCC_CFGR_SW_HSI);
  RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
  /* Enable external high-speed oscillator 8MHz. */
  RCC_HSEConfig(RCC_HSE_ON);
  status = (int8_t)RCC_WaitForHSEStartUp();
  if (status != (int8_t)SUCCESS)
    return -1;

  // rcc_osc_on(RCC_HSE);
  // rcc_wait_for_osc_ready(RCC_HSE);

  /* Enable/disable high performance mode */
  // if (!clock->power_save) {
    // pwr_set_vos_scale(PWR_SCALE1);
  // } else {
  //   pwr_set_vos_scale(PWR_SCALE2);
  // }

  /*
   * Set prescalers for AHB, ADC, ABP1, ABP2.
   * Do this before touching the PLL (TODO: why?).
   */
  RCC_HCLKConfig(clock->hpre);
  RCC_PCLK1Config(clock->ppre1);
  RCC_PCLK2Config(clock->ppre2);
  // rcc_set_hpre(clock->hpre);
  // rcc_set_ppre1(clock->ppre1);
  // rcc_set_ppre2(clock->ppre2);


  RCC_PLLConfig(RCC_PLLSource_HSE, clock->pllm, clock->plln, clock->pllp, clock->pllq);
  // rcc_set_main_pll_hse(clock->pllm, clock->plln,
  //     clock->pllp, clock->pllq, clock->pllr);

  /* Enable PLL oscillator and wait for it to stabilize. */
  RCC_PLLCmd(ENABLE);
  // rcc_osc_on(RCC_PLL);
  status = RCC_GetFlagStatus(RCC_FLAG_PLLRDY);
  if (status != SET)
    return -1;

  // rcc_wait_for_osc_ready(RCC_PLL);

  /* Configure flash settings. */
  FLASH_SetLatency(FLASH_Latency_5);
  FLASH_DataCacheCmd(ENABLE);
  FLASH_InstructionCacheCmd(ENABLE);
  // flash_set_ws(clock->flash_config);
  /* Select PLL as SYSCLK source. */

  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

  // rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

  /* Wait for PLL clock to be selected. */
  while (!(RCC_GetSYSCLKSource() == 0x08) );

  // rcc_wait_for_sysclk_status(RCC_PLL);

  /* Set the peripheral clock frequencies used. */
  // rcc_ahb_frequency  = clock->ahb_frequency;
  // rcc_apb1_frequency = clock->apb1_frequency;
  // rcc_apb2_frequency = clock->apb2_frequency;

  /* Disable internal high-speed oscillator. */
  RCC_HSICmd(DISABLE);
  // rcc_osc_off(RCC_HSI);
  return 0;
}


