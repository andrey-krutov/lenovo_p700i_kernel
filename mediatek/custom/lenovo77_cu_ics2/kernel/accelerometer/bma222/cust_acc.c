#include <linux/types.h>
#include <cust_acc.h>
#include <mach/mt6577_pm_ldo.h>


/*---------------------------------------------------------------------------*/
static struct acc_hw cust_acc_hw = {
    .i2c_num = 0,
/* lenovo anhui board sensors spec, plz don't change it!!! ---liaoxl.lenovo 4.19.2012 start  */	
    .direction = 3,
/* lenovo anhui board sensors spec, plz don't change it!!! ---liaoxl.lenovo 4.19.2012 end  */	
    .power_id = MT65XX_POWER_NONE,  /*!< LDO is not used */
    .power_vol= VOL_DEFAULT,        /*!< LDO is not used */
    .firlen = 0, //old value 16                /*!< don't enable low pass fileter */
};
/*---------------------------------------------------------------------------*/
struct acc_hw* get_cust_acc_hw(void) 
{
    return &cust_acc_hw;
}
