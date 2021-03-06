#include <rtthread.h>

int rt_application_init()
{
	rt_device_t device;
	struct rt_device_rect_info info;

	device = rt_device_find("sdl");
	if (device != RT_NULL)
	{
		info.width = 800;
		info.height = 480;

		/* set graphic resolution */
		rt_device_control(device, RTGRAPHIC_CTRL_SET_MODE, &info);
	}
	/* re-set graphic device */
	rtgui_graphic_set_device(device);

	application_init();

	return 0;
}
