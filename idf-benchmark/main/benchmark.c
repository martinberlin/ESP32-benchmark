/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "sdkconfig.h"

/* Can run 'make menuconfig' to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

static const char* TAG = "benchmark";


void app_main()
{

  int64_t d, overhead;
  int64_t time_since_boot = esp_timer_get_time();
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. 
    */
    gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    printf("Speed test\n");
    printf("----------\n");
    printf("GPIO set test\n");
    gpio_set_level(BLINK_GPIO, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    printf("digitalRead: \n");

  int64_t start = esp_timer_get_time();

  for (int i=0; i<2; i++)
  {
    for (int j=0; j<10000; j++)
    {
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
      gpio_get_level(BLINK_GPIO);       
    }
  }
  int64_t after = esp_timer_get_time();
  d = after-start;
  d /= 10.0;

  ESP_LOGI(TAG, "Boot time: %lld us", time_since_boot);
  ESP_LOGI(TAG, "GPIO_get_level * 200000: %lld us (digitalRead)", d);

  start = esp_timer_get_time();

  for (int i=0; i<2; i++)
  {
    for (int j=0; j<10000; j++)
    {
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0);   
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
      gpio_set_level(BLINK_GPIO, 1); 
      gpio_set_level(BLINK_GPIO, 0); 
    }
  }
  after = esp_timer_get_time();
  d = after-start;
  d /= 20.0;
  ESP_LOGI(TAG, "GPIO_set_level ON/OFF * 200000: %lld us (digitalWrite)", d);


  unsigned char c1,c2;
  c1 = 2;
  c2 = 3;
start = esp_timer_get_time();

  for (int i=0; i<20; i++)
  {
    for (int j=0; j<10000; j++)
    {
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
    }
  }
  after = esp_timer_get_time();
  d = after-start;
  d /= 20.0;
  ESP_LOGI(TAG, "Multiply byte 200000*20: %lld us", d);

  printf("End of test ------------\n"); 
  
}
