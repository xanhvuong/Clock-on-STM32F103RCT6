#include "main.h"
#include "lcd.h"
#include "stdlib.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;   // Timer 1 handler structure (used for delay function)

/* USER CODE BEGIN PV */
unsigned char flag = 0;    // Flag variable (used to detect button press: 1 = minute adjust, 2 = hour adjust)
uint16_t hh,              // Full hour value (0–23)
         h,               // Hour unit digit (ones place)
         mm,              // Minute tens digit
         m,               // Minute unit digit (ones place)
         ss,              // Second tens digit
         s,               // Second unit digit (ones place)
         temp;            // Temporary variable used for digit separation
/* USER CODE END PV */

/* Function prototypes -------------------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);

/* USER CODE BEGIN 0 */

/**
 * @brief Delay function (in milliseconds)
 * This function creates a blocking delay using TIM1 counter.
 * @param ms Number of milliseconds to delay
 */
void delay_ms(uint16_t ms) {
    for(int i=0; i < ms; i++) {
        htim1.Instance->CNT = 0;            // Reset timer counter
        HAL_TIM_Base_Start(&htim1);         // Start TIM1
        while(htim1.Instance->CNT < 999);   // Wait until counter reaches ~1ms
        HAL_TIM_Base_Stop(&htim1);          // Stop TIM1
    }
}

/**
 * @brief External interrupt callback
 * Called automatically when a GPIO pin configured as EXTI triggers an interrupt.
 * @param GPIO_Pin Pin number that triggered the interrupt
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if(GPIO_Pin == GPIO_PIN_1) {    // If button 1 is pressed
        flag = 1;                   // Set flag to adjust minutes
    }
    if(GPIO_Pin == GPIO_PIN_2) {    // If button 2 is pressed
        flag = 2;                   // Set flag to adjust hours
    }
}

/**
 * @brief Clock display function
 * This function simulates a digital clock on the LCD.
 * It loops through hours, minutes, and seconds,
 * updating the display and toggling an LED depending on the time of day.
 */
void dong_ho() {
    for(hh = 0; hh <= 24; hh++) {                 // Loop through hours (0–24)
        
        // Control LED based on daytime (on at night, off during the day)
        if(hh <= 6 && hh >= 18) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);   // Turn ON LED
        }
        if(hh > 6 && hh < 18){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);   // Turn OFF LED
        }

        // Display the hour on LCD
        temp = hh / 10;                        // Get tens digit of hour
        if(temp >= 1) {
            LCD_setCursor(0, 0);               // Move cursor to LCD column 0, row 0
            LCD_printf("%d", temp);            // Print tens digit
        }
        if(temp < 1) {
            LCD_setCursor(0, 0);
            LCD_printf(" ");                   // Print space if no tens digit
        }

        h = hh % 10;                           // Get ones digit of hour
        LCD_setCursor(0, 1);
        LCD_printf("%d", h);                   // Print ones digit of hour

        // Loop through minutes
        for(mm = 0; mm <= 6; mm++) {           // Tens place of minutes
            LCD_setCursor(0, 3);
            LCD_printf("%d", mm);
            for(m = 0; m <= 6; m++) {          // Ones place of minutes
                LCD_setCursor(0, 4);
                LCD_printf("%d", m);

                // Loop through seconds
                for(ss = 0; ss <= 6; ss++) {   // Tens place of seconds
                    LCD_setCursor(0, 6);
                    LCD_printf("%d", ss);
                    for(s = 0; s <= 6; s++) {  // Ones place of seconds
                        LCD_setCursor(0, 7);
                        LCD_printf("%d", s);
                        delay_ms(1000);        // Delay 1 second
                    }
                }
            }
        }
    }
}
/* USER CODE END 0 */

/**
  * @brief  Main program entry point
  * @retval int
  */
int main(void)
{
  /* Reset of all peripherals, initialize Flash and Systick */
  HAL_Init();              // Initialize HAL library
  LCD_init();              // Initialize LCD module

  /* Configure system clock */
  SystemClock_Config();

  /* Initialize peripherals */
  MX_GPIO_Init();          // Initialize GPIO
  MX_TIM1_Init();          // Initialize TIM1
  HAL_TIM_Base_Init(&htim1); // Initialize TIM1 base functionality

  /* Infinite loop */
  while (1)
  {
      // Print colons for HH:MM:SS format
      LCD_setCursor(0, 2);
      LCD_printf(":");
      LCD_setCursor(0, 5);
      LCD_printf(":");

      // Run clock display function
      dong_ho();

      // Handle button inputs
      if(flag == 1) {      // If button 1 pressed
          m++;             // Increment minute
      }
      if(flag == 2) {      // If button 2 pressed
          hh++;            // Increment hour
      }
      flag = 0;            // Reset flag
  }
}
