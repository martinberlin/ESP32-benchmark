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

static void periodic_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);
}

void app_main()
{

  const esp_timer_create_args_t periodic_timer_args = {
          .callback = &periodic_timer_callback,
          /* name is optional, but may help identify the timer when debugging */
          .name = "periodic"
  };

  esp_timer_handle_t periodic_timer;
  ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));

  int64_t d, overhead;
  int64_t time_since_boot = esp_timer_get_time();

   ESP_LOGI(TAG, "Boot time: %lld us", time_since_boot);
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
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);       
      gpio_get_level(10);  
      //vTaskDelay(1 / portTICK_PERIOD_MS);    
    }
  }
  int64_t after = esp_timer_get_time();
  d = after-start;
  d /= 20.0;
  ESP_LOGI(TAG, "digitalRead * 200000: %lld us", d);

  printf("End of test ------------\n"); 
  vTaskDelay(100 / portTICK_PERIOD_MS);
}
