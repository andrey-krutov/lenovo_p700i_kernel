#include <cust_leds.h>
#include <mach/mt6577_pwm.h>

#include <linux/kernel.h>
#include <mach/pmic_mt6329_hw_bank1.h> 
#include <mach/pmic_mt6329_sw_bank1.h> 
#include <mach/pmic_mt6329_hw.h>
#include <mach/pmic_mt6329_sw.h>
#include <mach/upmu_common_sw.h>
#include <mach/upmu_hw.h>

extern int mtkfb_set_backlight_level(unsigned int level);
extern int mtkfb_set_backlight_pwm(int div);

/*lenovo-sw jixj 2012.4.16 add begin*/
#ifdef LENOVO_PROJECT_SEATTLE
#ifdef CONFIG_LENOVO_LED
extern void led_breath_set(u8 mode, u8 color,u8 style);
extern void led_button_set(u8 mode);
unsigned int Cust_SetBreathlight(int level, unsigned char color,int style)
{
    led_breath_set(level, color, style);
    return 0;
}
unsigned int Cust_SetButtonBacklight(int level, int div)
{
    led_button_set(level);
    return 0;
}
#endif
#endif
/*lenovo-sw jixj 2012.4.16 add end*/
unsigned int brightness_mapping(unsigned int level)
{
    unsigned int mapped_level;
    
    mapped_level = level;
       
	return mapped_level;
}

unsigned int Cust_SetBacklight(int level, int div)
{
    mtkfb_set_backlight_pwm(div);
    mtkfb_set_backlight_level(brightness_mapping(level));
    return 0;
}

static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",               MT65XX_LED_MODE_NONE, -1,{0}},
	{"green",             MT65XX_LED_MODE_NONE, -1,{0}},
	{"blue",              MT65XX_LED_MODE_NONE, -1,{0}},
	{"jogball-backlight", MT65XX_LED_MODE_NONE, -1,{0}},
	{"keyboard-backlight",MT65XX_LED_MODE_NONE, -1,{0}},
/*lenovo-sw jixj 2012.4.16 add begin*/
#ifdef LENOVO_PROJECT_SEATTLE
#ifdef CONFIG_LENOVO_LED
	{"button-backlight",  MT65XX_LED_MODE_CUST, (int)Cust_SetButtonBacklight,{0}},
#else
	{"button-backlight",  MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_BUTTON,{0}},
#endif
#else
	{"button-backlight",  MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_BUTTON,{0}},
#endif
/*lenovo-sw jixj 2012.4.16 add end*/
	{"lcd-backlight",     MT65XX_LED_MODE_CUST, (int)Cust_SetBacklight,{0}},
/*lenovo-sw jixj 2012.4.16 add begin*/
#ifdef LENOVO_PROJECT_SEATTLE
#ifdef CONFIG_LENOVO_LED
	{"breath",               MT65XX_LED_MODE_CUST, (int)Cust_SetBreathlight, {0}},
#endif
#endif
/*lenovo-sw jixj 2012.4.16 add end*/
};

struct cust_mt65xx_led *get_cust_led_list(void)
{
	return cust_led_list;
}

